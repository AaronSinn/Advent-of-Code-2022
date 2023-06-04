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
    int partOneTotalScore = 0;
    int partTwoTotalScore = 0;

    while(getline(inputFile, input)){
        istringstream iss(input);

        iss >> leftCol;
        iss >> rightCol;

        switch(leftCol){
            //rock
            case 'A':
                if(rightCol == 'X'){        //draw with rock
                    partOneTotalScore += 4;
                }
                else if(rightCol == 'Y'){   //win with paper
                    partOneTotalScore += 8;
                }   
                else{                       //loss with scissors
                    partOneTotalScore += 3;
                }
                break;
            
            //paper
            case 'B':                       //loss with rock
                if(rightCol == 'X'){
                    partOneTotalScore += 1;
                }
                else if(rightCol == 'Y'){   //draw with paper
                    partOneTotalScore += 5;
                }
                else{                       //win with scissors
                    partOneTotalScore += 9;         
                }
                break;
            
            //scissors
            case 'C':
                if(rightCol == 'X'){        //win with rock
                    partOneTotalScore += 7;
                }
                else if(rightCol == 'Y'){   //loss with paper
                    partOneTotalScore += 2;
                }
                else{                       //draw with scissors
                    partOneTotalScore += 6;
                }
                break;
            
            default:
                break;
        }

        switch(rightCol){

            case 'X':
                if(leftCol == 'A'){         //loss with scissors
                    partTwoTotalScore += 3;
                }
                else if(leftCol == 'B'){    //loss with rock
                    partTwoTotalScore += 1;
                }
                else{                       //loss with paper
                    partTwoTotalScore += 2;
                }
                break;

            case 'Y':
                if(leftCol == 'A'){         //draw with rock
                    partTwoTotalScore += 4;
                }
                else if(leftCol == 'B'){    //draw with paper
                    partTwoTotalScore += 5;
                }
                else{                       //draw with scissors
                    partTwoTotalScore += 6;
                }
                break;

            case 'Z':
                if(leftCol == 'A'){         //win with paper
                    partTwoTotalScore += 8;
                }
                else if(leftCol == 'B'){    //win with scissors
                    partTwoTotalScore += 9;
                }
                else{                       //win with rock
                    partTwoTotalScore += 7;
                }
                break;

            default:
                break;
        }
    }

    cout << "Total score for part one is: " << partOneTotalScore << ".\n";
    cout << "Total score for part two is: " << partTwoTotalScore << ".\n";

    return 0;
}