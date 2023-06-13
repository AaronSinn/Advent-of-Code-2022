#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <dir.hpp>

using namespace std;

int main(){
    
    fstream inputFile("input.txt");
    string input;
    string currentDir;  //directory we're currently in
    string parentDir;   //parent of the directory we're in
    
    std::map<std::string, dir> map;

    while(getline(inputFile, input)){
        if(input[0] == 'c' && input[1] == 'd'){     //if a cd command is used
            for(int i = 3; i < input.length(); ++i){
                currentDir += input[i];
            }
        } 

        cout << currentDir << endl;

    }

    return 0;
}