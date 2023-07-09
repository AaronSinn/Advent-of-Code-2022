#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void split(string input, string &Linput, string &Rinput);

class Dir{
    public:
        string name;
        int dirSize;
        Dir* parent;
        vector<Dir> childern;

        Dir(string name, int dirSize, Dir* parent){
            this->name = name;
            this->dirSize = dirSize;
            this->parent = parent;
        }

        int sumOfSizesLessThan100K(){
            int totalSize = 0;
            
            //if dir size < 100K
            if(this->dirSize <= 100'000 ){
                totalSize += dirSize;
            }

            for(Dir& child: childern){
                cout << child.name << endl;
                totalSize += child.sumOfSizesLessThan100K();
            }
            return totalSize;
        }
};

int main(){

    string input;   //line from the file
    string Linput;  //left side of the input. Will be either a command or file size
    string Rinput;  //right side of file. Will be a name or args for a command
    ifstream inputFile("input.txt");
    Dir root = Dir("/", 0, nullptr);
    Dir* currentDir;

    while(getline(inputFile, input)){
        split(input, Linput, Rinput);

        if(Linput == "cd"){
            if(Rinput == "/"){
                currentDir = &root;
            }
            else if(Rinput == ".."){
                currentDir = currentDir->parent;
            }
            else{
                for(Dir &child : currentDir->childern){
                    if(child.name == Rinput){
                        currentDir = &child; 
                        break;
                    }
                }
            }
        }

        else if(Linput == "dir"){
            currentDir->childern.push_back(Dir(Rinput, 0, currentDir));
        }

        //Linput is equal to a filesize and not the ls command which is the last available possibility
        else if(Linput != "ls"){
            int fileSize = stoi(Linput);
            currentDir->dirSize += fileSize;
        }

        Linput.clear();
        Rinput.clear();
    }
    cout << root.sumOfSizesLessThan100K() << endl;

    return 0;
}

void split(string input, string &Linput, string &Rinput){
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