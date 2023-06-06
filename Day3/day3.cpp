#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

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
    
    //part two variables
    int elfGroupSum = 0;
    int loopCount = 0;
    stringstream ss;
    string firstString;
    string secondString;
    string thirdString;
    char elfGroupLetter; 


    while(getline(inputFile, input)){
        parseStrings(leftSide, rightSide, input);
        sameType = findSameType(leftSide, rightSide);
        sum += typeToInt(sameType);

        ss << input;
        ss << ' ';
        loopCount++;

        if(loopCount == 3){
            loopCount = 0;
            ss >> firstString;
            ss >> secondString;
            ss >> thirdString;

            cout << firstString << " " << secondString << " " << thirdString << "\n";
            
            for(int i = 0; i < firstString.length(); i++){
                for(int j = 0; j < secondString.length(); j++){
                    for(int k = 0; k < thirdString.length(); k++){
                        if(thirdString[k] == secondString[j] && thirdString[k] == firstString[i]){
                            elfGroupLetter = thirdString[k];
                            cout << "letter is " << elfGroupLetter << "\n";
                        }
                    }
                }
            }
            elfGroupSum += typeToInt(elfGroupLetter);
        }
    }

    cout << "The sum of the same types is " << sum << ".\n";
    cout << "The sum of the group letters is " << elfGroupSum << ".\n";



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