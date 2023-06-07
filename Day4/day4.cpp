#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(){

    using namespace std;

    ifstream inputFile("input.txt");

    int fullRangeCount = 0;
    string input;
    string buffer;  //used to hold the parsed string before it goes into the string stream
    string left;    //left side of the input string (the 23-46 part of 23-46,44-78)
    string right;   //right side of the input string (44-78)
    int overlapCount = 0;   //for part 2;

    //the value in the strings below get casted into these ints 
    int lowerLeft;
    int upperLeft;
    int lowerRight;
    int upperRight;

    //strings that receive a number from the iss and get casted into a int
    string lowerLeftStr;
    string upperLeftStr;
    string lowerRightStr;
    string upperRightStr;
    
    while(getline(inputFile, input)){
        istringstream iss(input);   

        while (getline(iss, buffer)) {

            //The string gets divided and casted into integers
            istringstream issParse(buffer);
            getline(issParse, left, ',');
            getline(issParse, right);
            issParse.str("");
            issParse.clear();

            issParse.str(left);
            getline(issParse, lowerLeftStr, '-');
            getline(issParse, upperLeftStr);
            lowerLeft = stoi(lowerLeftStr);
            upperLeft = stoi(upperLeftStr);
            issParse.str("");
            issParse.clear();

            issParse.str(right);
            getline(issParse, lowerRightStr, '-');
            getline(issParse, upperRightStr);
            lowerRight = stoi(lowerRightStr);
            upperRight = stoi(upperRightStr);
            issParse.str("");
            issParse.clear();

            if(lowerLeft <= lowerRight && upperLeft >= upperRight){     //left side fully contains right side
                fullRangeCount++;
                //cout << lowerLeft << "-" << upperLeft << "," << lowerRight << "-" << upperRight<< "    L" << endl;
            }
            else if(lowerRight <= lowerLeft && upperRight >= upperLeft){     //left side fully contains right side
                fullRangeCount++;
                //cout << lowerLeft << "-" << upperLeft << "," << lowerRight << "-" << upperRight << "    R" << endl;
            }

            if(upperLeft >= lowerRight && lowerLeft <= upperRight){
                overlapCount++;
            } 
        }   
    }

    cout << fullRangeCount << " pairs fully contain another.\n";
    cout << overlapCount << " pairs are overlapping one another.\n";

    return 0;
}