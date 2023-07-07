#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include "dir.hpp"

using namespace std;

int main(){
    
    fstream inputFile("input.txt");
    string input;
    string currentDir;  //directory we're currently in
    string parentDir;   //parent of the directory we're in
    
    std::map<std::string, dir> map;

    while(getline(inputFile, input)){
        //do what u did with day two to parse

    }

    return 0;
}