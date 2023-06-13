#ifndef DIR_HPP
#define DIR_HPP

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
        dir(std::string name);
        void addParent(std::string parentDir);
        void addChildDir(dir child);
        void addFile(int size);
};

#endif