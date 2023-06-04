#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//A,X = ROCK        | Score = 1
//B,Y = PAPER       | Score = 2
//C,Z = SCISSORS    | Score = 3
//Score for draw = 3, Score for win = 6


int main(){
    using namespace std;

    ifstream inputFile("input.txt");

    string input;
    char leftCol;
    char rightCol;
    int totalScore = 0;

    while(getline(inputFile, input)){
        istringstream iss(input);

        iss >> leftCol;
        iss >> rightCol;

        switch(leftCol){
            //rock
            case 'A':
                if(rightCol == 'X'){        //draw with rock
                    totalScore += 4;
                }
                else if(rightCol == 'Y'){   //win with paper
                    totalScore += 8;
                }   
                else{                       //loss with scissors
                    totalScore += 3;
                }
                break;
            
            //paper
            case 'B':                       //loss with rock
                if(rightCol == 'X'){
                    totalScore += 1;
                }
                else if(rightCol == 'Y'){   //draw with paper
                    totalScore += 5;
                }
                else{                       //win with scissors
                    totalScore += 9;         
                }
                break;
            
            //scissors
            case 'C':
                if(rightCol == 'X'){        //win with rock
                    totalScore += 7;
                }
                else if(rightCol == 'Y'){   //loss with paper
                    totalScore += 2;
                }
                else{                       //draw with scissors
                    totalScore += 6;
                }
                break;
            
            default:
                break;
        }
    }

    cout << "Total score is: " << totalScore << ".\n";

    return 0;
}