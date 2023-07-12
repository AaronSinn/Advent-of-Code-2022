#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void split(std::string  input, std::string  &Linput, std::string  &Rinput){
    //if the input is a dir or a file
    if(input[0] != '$'){
        int i;
        for(i = 0; input[i] != ' '; i++){
            Linput.push_back(input[i]);
        }
        i++;

        for(i; i<input.length(); i++){
            Rinput.push_back(input[i]);
        }    
    }
    //if the input is a terminal command
    else{

        if(input == "$ ls"){
            Linput = "ls";
            return;
        }

        int i;
        for(i = 2; input[i] != ' '; i++){
            Linput.push_back(input[i]);
        }

        i++;
        if(Linput != "ls"){
            for(i; i<input.length(); i++){
                Rinput.push_back(input[i]);
            }
        }
    }
}

struct Node{
    std::string name;
    int size = 0;
    Node* parent;     
    bool isDir;
    std::vector<Node> children;

    
};

int main(){

    std::string  input;   //line from the file
    std::string  Linput;  //left side of Wthe input. Will be either a command or file size
    std::string  Rinput;  //right side of file. Will be a name or args for a command
    std::ifstream inputFile("input.txt");
    int sizeOfAllFiles = 0;

    while(std::getline(inputFile, input)){
        

        Linput.clear();
        Rinput.clear();
    }

    return 0;
}