#include <iostream>
#include <cstdlib>
#include <string>
#include "functions.cpp"
using namespace std; 


int main(){

    string userInput;

    while(1){
        getline(cin, userInput);
        if(userInput == "quit" || "clear"){
            exit(0);
        }

        if(userInput.substr(0,5) == "print"){
            print(userInput.substr(6));
        }
    }
    

    return 0;
}