// functions cpp file for granular
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std; 

// prototyped functions
void print(string wordToPrint);
void print(string wordToPrint, string value);
void ver(char circumstance);
bool properSyntaxCheck(string value, char operation);
bool sum(string value);
bool difference(string value);
void clearTerminal();

// ---------------------------------------------------------------------------

// overloaded print functions
void print(string wordToPrint){
    cout << wordToPrint << endl;
}

void print(string wordToPrint, string value){
    cout << wordToPrint << value << endl;
}

// ---------------------------------------------------------------------------
// helper function

void help(){
    print("____________________________________________");
    ver('h');
    print("Able commands:");
    print("'quit' or 'clear'    Quit out of the Granular environment");
    print("'sum'    Calculate the summation (addition) of numbers (e.g. 'sum 38+65+1' or 'sum 38 65 1' will output 104)");
    print("____________________________________________\n");
}

// ---------------------------------------------------------------------------

void clearTerminal(){
    system("clear");
    ver('c');
    print("Type 'help' for able commands\n");
}

// ---------------------------------------------------------------------------

void ver(char circumstance){

    string version = "v0.2";

    switch(circumstance){
    case 'h':
        print("Version: ", version);
        break;
    
    case 'c':
        print("Granular version ", version);
        break;
    
    default:
        print("Current version: ", version);
        break;
    }
}

// ---------------------------------------------------------------------------
// helper function
// checks for proper syntax with mathmatical operations
bool properSyntaxCheck(string value, char operation){

    for(int i = 0; i < value.size(); i++){
        if(!isdigit(value[i]) && value[i] != operation && value[i] != ' ' && value[i] != '.' && value[i] != 13){
            return true;
        }
    }
    
    return false;
}

// ---------------------------------------------------------------------------

bool sum(string value){

    if(properSyntaxCheck(value, '+') == true){
        return true;
    }


    long double sumVal = 0;
    int start = 0;
    

    for(int i = 0; i < value.size(); i++){
        
        if(value[i] == '+' || value[i] == ' ' || value[i+1] == '\0'){

            sumVal += atoi(value.substr(start, i).c_str());

            start = i;

        }
    }

    print("sum: ", to_string(sumVal));

    return false;
}

bool difference(string value){

    long double diffVal = 0;
    int start = 0;

    if(properSyntaxCheck(value, '-') == true){
        return true;
    }

   for(int i = 0; i < value.size(); i++){
        
        if(value[i] == '-' || value[i] == ' ' || value[i+1] == '\0'){

            diffVal += atoi(value.substr(start, i).c_str());

            start = i;

        }
    }

    print("difference: ", to_string(diffVal));

    return false;
}
