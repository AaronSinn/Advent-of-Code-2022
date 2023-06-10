#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <array>
#include <algorithm>

bool checkIfDifferent(std::queue<char> queue);
bool checkIfDifferentPartTwo(std::queue<char> queue);

int main(){

    using namespace std;

    fstream inputFile("input.txt");
    string input;
    queue<char> fourLetterQueue;
    queue<char> fourteenLetterQueue;

    getline(inputFile, input);

    for(int i = 0; i < 4; i++){             //adds the first four letters to the queue
        fourLetterQueue.push(input[i]);
    }

    for(int i = 4; i < input.size(); ++i){

        if(!checkIfDifferent(fourLetterQueue)){
            cout <<"For part one, the first marker is after character " << i << ".\n";
            break;
        }

        fourLetterQueue.pop();
        fourLetterQueue.push(input[i]);

    }

    //PART TWO

    for(int i = 0; i < 14; i++){             //adds the first 14 letters to the queue
        fourteenLetterQueue.push(input[i]);
    }

    for(int i = 14; i < input.size(); ++i){

        if(!checkIfDifferentPartTwo(fourteenLetterQueue)){
            cout <<"For part two, the first marker is after character " << i << ".\n";
            break;
        }

        fourteenLetterQueue.pop();
        fourteenLetterQueue.push(input[i]);
    }

    return 0;
}   //end of main

bool checkIfDifferent(std::queue<char> queue){  //returns true if the queue has at least 2 same letters
    std::array<char, 4> array;

    for(int i = 0; queue.size() != 0; i++){     //adds the queue elements to the array
        array[i] = queue.front();
        queue.pop();
    }

    std::sort(array.begin(), array.end());

    for(int i = 0; i < array.size() -1; i++){
        if(array[i] == array[i+1]){
            return true;
        }
    }

    return false;
}

bool checkIfDifferentPartTwo(std::queue<char> queue){  //returns true if the queue has at least 2 same letters
    std::array<char, 14> array;

    for(int i = 0; queue.size() != 0; i++){     //adds the queue elements to the array
        array[i] = queue.front();
        queue.pop();
    }

    std::sort(array.begin(), array.end());

    for(int i = 0; i < array.size() -1; i++){
        if(array[i] == array[i+1]){
            return true;
        }
    }

    return false;
}