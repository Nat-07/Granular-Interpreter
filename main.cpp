#include <iostream>
#include <cstdlib>
#include <string>
#include "functions.cpp"
using namespace std; 


int main(){
    bool invalid = false;
    string userInput;

    while(1){
        if(invalid == true){
           print("Invalid Syntax!");
        }
        
        invalid = true;
        
        // get user input
        getline(cin, userInput);

        if(userInput == "quit" || userInput == "clear"){
            exit(0);
        }
        
        // print function
        if(userInput.substr(0,5) == "print"){
            print(userInput.substr(6));
            invalid = false;
        }


    }
    

    return 0;
}