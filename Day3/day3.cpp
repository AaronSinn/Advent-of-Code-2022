#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

void parseStrings(std::string &left, std::string &right, std::string input);
char findSameType(std::string &left, std::string &right);
int typeToInt(char type);

int main(){
    using namespace std;

    ifstream inputFile("input.txt");
    
    string input;
    string leftSide;
    string rightSide;
    char sameType;
    int sum = 0;

    while(getline(inputFile, input)){
        parseStrings(leftSide, rightSide, input);
        sameType = findSameType(leftSide, rightSide);
        sum += typeToInt(sameType);
        cout << sum << endl;
    }

    cout << "The sum of the same types is " << sum << ".\n";

    return 0;
}

void parseStrings(std::string &left, std::string &right, std::string input){
    int length = input.length();

    left.clear();
    right.clear();

    for(int i = 0; i < length/2; i++){
        left += input[i];
    }

    for(int i = (length/2); i < length; i++){
        right += input[i];
    }
}

char findSameType(std::string &left, std::string &right){
    for(int i = 0; i < left.length(); i++){
        for(int j = 0; j < right.length(); j++){
            if(left[i] == right[j]){
                return left[i];
            }
        }
    }
}

int typeToInt(char type){
    if(isupper(type)){
        return type - 38;
    }
    else{
        return type - 96;
    }
}