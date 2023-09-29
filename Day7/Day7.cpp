#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <cctype>

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
    Directory* parent = nullptr;
    std::vector<std::unique_ptr<File>> files;          //pointers to the file classes
    std::vector<std::shared_ptr<Directory>> childern;  //pointers to childern classes  
};

//returns total internal file size for the dir
long addFiles(Directory* dir){
    long fileSize = 0;

    for(int i = 0; i < dir->files.size(); i++){
        fileSize += dir->files.at(i)->size;
    }

}

//Computes the total size of each Dir
long totalDirSize(Directory* currentDir){

    long totalFileSize = 0;

    if(currentDir->childern.size() == 0){
        return addFiles(currentDir);
    }

    
}

int main(int argc, char **argv){
    std::string input;
    std::ifstream inputFile("input.txt");
    
    try{
        if(inputFile.is_open() == false){
            throw std::runtime_error("Could not open input.txt");
        }

        Directory* currentDir = nullptr;
        int linecount = 0;

        while(getline(inputFile, input)){
            // linecount++;
            // std::cout << "Linecout: " << linecount << std::endl;
            
            //Change directory
            if(input.substr(0,4) == "$ cd" && input != "$ cd .."){
                std::string newDirName = input.substr(5,input.length());
                Directory* newDir = new Directory(newDirName); //currentDir points to the memory address of the new directory on the heap
                newDir->parent = currentDir;
                currentDir = newDir;
            }
            //Change directory to the outer one (parent)
            else if(input == "$ cd .."){
                currentDir = currentDir->parent;
            }
            
            else if(input.substr(0,3) == "dir"){
                std::string childDirName = input.substr(4, input.length());
                currentDir->childern.push_back(std::make_shared<Directory>(childDirName));
            }
            else if(input != "$ ls"){
                std::size_t spacePos = input.find(' ');
                long fileSize = std::stoi(input.substr(0, spacePos));
                // std::cout << "FILESIZE: " << fileSize << std::endl;
                std::string fileName = input.substr(spacePos+1, input.length());
                currentDir->files.push_back(std::make_unique<File>(fileName, fileSize));
                // std::cout << "Current Dir: " << currentDir->name << ", Files: ";
                
                // for(int i = 0; i < currentDir->files.size(); i++){
                //     std::cout << currentDir->files.at(i)->name << " ";
                // }
                // std::cout << "\n";
            }
        }

        inputFile.close();
    } catch(std::exception& e){
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 2;
    }

    return 0;
}