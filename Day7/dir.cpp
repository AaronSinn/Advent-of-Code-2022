#include <iostream>
#include <vector>
#include <string>

class dir{
    private:
       long int fileSizes;
       std::vector<dir> childernDirs; 
       std::string parentDir;
       std::string dirName;
    
    public:
        dir(std::string name){
            fileSizes = 0;
            parentDir = "";
            dirName.assign(name);
        }

        void addParent(std::string parentDir){
            this->parentDir.assign(parentDir);
        }
        
        void addChildDir(dir child){
            childernDirs.push_back(child);
        }

        void addFile(int size){
            fileSizes += size;
        }
};