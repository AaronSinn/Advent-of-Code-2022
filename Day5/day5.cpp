#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>

void getNumberFromString(std::string s, std::vector<int>& instructionList);

int main(){

    using namespace std;

    stack<char> s1; stack<char> s2; stack<char> s3; stack<char> s4; stack<char> s5; stack<char> s6; stack<char> s7; stack<char> s8; stack<char> s9;
    string message = "";
    vector<stack<char>> stackList;
    vector<int> instructionList;
    vector<char> cratesList;        //used in part 2 to store multiple crates
    string input;
    ifstream inputFile("input.txt");

    int crateCount = 0;     //amount of crates being moved
    int stackFrom = 0;      //stack the crates are being moved from
    int stackTo = 0;        //stack the creates are being moved to

    // [B]                     [N]     [H]
    // [V]         [P] [T]     [V]     [P]
    // [W]     [C] [T] [S]     [H]     [N]
    // [T]     [J] [Z] [M] [N] [F]     [L]
    // [Q]     [W] [N] [J] [T] [Q] [R] [B]
    // [N] [B] [Q] [R] [V] [F] [D] [F] [M]
    // [H] [W] [S] [J] [P] [W] [L] [P] [S]
    // [D] [D] [T] [F] [G] [B] [B] [H] [Z]
    //  1   2   3   4   5   6   7   8   9

    s1.push('D'); s1.push('H'); s1.push('N'); s1.push('Q'); s1.push('T'); s1.push('W'); s1.push('V'); s1.push('B');
    s2.push('D'); s2.push('W'); s2.push('B');
    s3.push('T'); s3.push('S'); s3.push('Q'); s3.push('W'); s3.push('J'); s3.push('C');
    s4.push('F'); s4.push('J'); s4.push('R'); s4.push('N'); s4.push('Z'); s4.push('T'); s4.push('P');
    s5.push('G'); s5.push('P'); s5.push('V'); s5.push('J'); s5.push('M'); s5.push('S'); s5.push('T');
    s6.push('B'); s6.push('W'); s6.push('F'); s6.push('T'); s6.push('N');
    s7.push('B'); s7.push('L'); s7.push('D'); s7.push('Q'); s7.push('F'); s7.push('H'); s7.push('V'); s7.push('N');
    s8.push('H'); s8.push('P'); s8.push('F'); s8.push('R');
    s9.push('Z'); s9.push('S'); s9.push('M'); s9.push('B'); s9.push('L'); s9.push('N'); s9.push('P'); s9.push('H');

    stackList.push_back(s1); stackList.push_back(s2); stackList.push_back(s3); stackList.push_back(s4); stackList.push_back(s5); stackList.push_back(s6); stackList.push_back(s7);
    stackList.push_back(s8); stackList.push_back(s9);

    while(getline(inputFile, input)){
        
        getNumberFromString(input, instructionList);

        //cout << instructionList[0] << " " << instructionList[1] << " " << instructionList[2] << "\n";

        crateCount = instructionList[0];
        stackFrom = instructionList[1];
        stackTo = instructionList[2];
        instructionList.clear();

        /*          FOR PART ONE         */
        // for(int i = 0; i < crateCount; i++){
        //     stackList[stackTo - 1].push(stackList[stackFrom - 1].top());
        //     stackList[stackFrom - 1].pop();
        // }

        for(int i = 0; i < crateCount; i++){
            cratesList.push_back(stackList[stackFrom - 1].top());
            stackList[stackFrom - 1].pop();
        }

        for(int i = 0; i < crateCount; i++){
            stackList[stackTo - 1].push(cratesList.back());
            cratesList.pop_back();
        }
    }

    for(stack<char> stack : stackList){
        message += stack.top();
    }

    cout << "The crates at the top of the stacks are " << message << "." << endl;

    return 0;
}

void getNumberFromString(std::string s, std::vector<int>& instructionList) {
   std::stringstream str_strm;
   str_strm << s; //convert the string s into stringstream
   std::string temp_str;
   int temp_int;
   while(!str_strm.eof()) {
      str_strm >> temp_str; //take words into temp_str one by one
      if(std::stringstream(temp_str) >> temp_int) { //try to convert string to int
         instructionList.push_back(temp_int);
      }
      temp_str = ""; //clear temp string
      temp_str.clear();
   }
}