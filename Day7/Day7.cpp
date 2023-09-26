#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

struct File{
    std::string name;
    long size;
};

struct Directory{
    std::string name;
    long size;
    Directory* parent;
    std::vector<std::unique_ptr<File>> files;          //pointers to the file classes
    std::vector<std::unique_ptr<Directory>> childern;  //pointers to childern classes  
};

int main(int argc, char **argv){
    

    return 0;
}