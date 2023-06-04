#include <iostream>
#include <fstream>
#include <string>

int main(){
    
    using namespace std;

    ifstream inputFile("input.txt");

    if(!inputFile.is_open()){   //prints an error message if the file dosen't open
        cerr << "The input file did not open :( \n";
        return 0;
    }

    string number;
    int firstCalCount = 0;  //stores the highest calorie count
    int secondCalCount = 0; //stores the second highest
    int thirdCalCount = 0;  //stores the thrid highest
    int currentCalCount = 0;

    while(getline(inputFile, number)){

       if(number == ""){
            if(currentCalCount > firstCalCount){
                secondCalCount = firstCalCount;
                firstCalCount = currentCalCount;
            }
            else if(currentCalCount > secondCalCount){
                thirdCalCount = secondCalCount;
                secondCalCount = currentCalCount;
            }
            else if(currentCalCount > thirdCalCount){
                thirdCalCount = currentCalCount;
            }
            currentCalCount = 0;
            //number = "0";     //can be used instead of the if statement below :)
       }
       if(number != ""){
            currentCalCount += stoi(number);
       }
    }

    cout << "The highest calorie count is " << firstCalCount << ".\n";
    cout << "The top 3 highest calorie counts combined are " << firstCalCount + secondCalCount + thirdCalCount << ".\n";

    return 0;
}