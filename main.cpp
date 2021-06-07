#include <iostream>
#include <cstdlib>
#include <string>
#include "functions.cpp"
using namespace std; 

int main(){
    bool invalid = false;
    //bool invalidNum = false;
    string userInput;

    cout  << "Loading into Granular v0.1" << endl;
    cout << "Type 'help' for able commands" << endl;
    

    while(1){
        if(invalid == true){
           print("Invalid Syntax!");
        }

        invalid = true;
        
        // get user input
        getline(cin, userInput);

        if(userInput == "quit"){ // quit function
            exit(0);
        
        }else if(userInput == "clear"){
            clearTerminal();
            invalid = false;

        }else if(userInput.substr(0,4) == "help" || userInput.substr(0,1) == "?"){ // help function
            help();
            invalid = false;
        
        }else if(userInput.substr(0,3) == "ver" || userInput.substr(0,7) == "version"){ // version function
            ver('h');
            invalid = false;

        }else if(userInput.substr(0,5) == "print"){ // print function
            print(userInput.substr(6));
            invalid = false;

        }else if(userInput.substr(0,3) == "sum"){ // sum function
            if(sum(userInput.substr(4)) == false){
                invalid = false;
            }
            
        }else if(userInput.substr(0,4) == "diff"){ // sum function
            if(difference(userInput.substr(5)) == false){
                invalid = false;
            }
        }
    
    }

    return 0;
}
