#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>

struct File{

    File(std::string name, long size):name(name), size(size){};

    std::string name;
    long size;
};

struct Directory{

    Directory(){};
    Directory(std::string name):name(name){};
    std::string name;
    long size;
    Directory* parent;
    std::vector<std::unique_ptr<File>> files;          //pointers to the file classes
    std::vector<std::shared_ptr<Directory>> childern;  //pointers to childern classes  
};

int main(int argc, char **argv){
    std::string input;
    std::ifstream inputFile("input.txt");
    
    try{
        if(inputFile.is_open() == false){
            throw std::runtime_error("Could not open input.txt");
        }

        Directory* currentDir;

        while(getline(inputFile, input)){
            
            //Change directory
            if(input.substr(0,4) == "$ cd" && input != "$ cd .."){
                std::string newDirName = input.substr(5,input.length());
                currentDir = new Directory(newDirName); //currentDir points to the memory address of the new directory on the heap
            }
            //Change directory to the outer one (parent)
            else if(input == "$ cd .."){
                currentDir = currentDir->parent;
            }

            if(input.substr(0,4) == "$ ls"){
                if(input.substr(0,3) == "dir"){
                    std::string childDirName = input.substr(4, input.length());
                    currentDir->childern.push_back(std::make_shared<Directory>(new Directory(childDirName)));
                }
                else{
                    std::size_t spacePos = input.find(' ');
                    long fileSize = std::stoi(input.substr(0, spacePos));
                    std::string fileName = input.substr(spacePos+1, input.length());
                    //currentDir->files.push_back(std::make_unique<File>(new File(fileName, fileSize)));
                }
            }
        }

        inputFile.close();
    } catch(std::exception& e){
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 2;
    }

    return 0;
}