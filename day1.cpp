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
    int itt = 0;

    while(getline(inputFile, number)){
        cout << number << endl;

        if(number == ""){
            cout << "empty line\n";
        }
    }

    return 0;
}