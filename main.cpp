#include <iostream>
#include <fstream>
#include "structures.h"

char f1;

void select_basicString_action(std::string basicString){
    system("cls");
    std::cout << "\n";
    std::cout << "Do you wish to write or read data?\n ";
    std::cout << "For write press (W/w).\n ";
    std::cout << "For read press (R/r).\n ";
    std::cout << "If no press other letter: ";
    std::cin >> f1;
    if (f1 == 'W' || f1 == 'w') {
        system("cls");
        std::string input, main_input;
        std::cout << "\n";
        std::cout << "Write the post: " << std::endl;
        std::cin >> input;
        main_input = input;
        getline(std::cin, input);
        main_input = main_input + input;
        std::ofstream file(basicString + ".txt");
        file << main_input << std::endl;
        file.close();
    }
    if (f1 == 'R' || f1 == 'r') {
        system("cls");
        std::cout << "\n";
        std::string line;
        std::ifstream file (basicString + ".txt");
        if (file.is_open()){
            while ( getline (file,line) ){
                std::cout << line << std::endl;
            }
            file.close();
        }
        else std::cout << "Unable to open posts";
    }
    system("pause");
    system("cls");
}


int main() {
    std::cout << "Inventarizācijas sistēma";
    std::cout << "Izvēlieties darbību:";
    std::cout << "1: Veikt preces uzskaiti";
    std::cout << "2: ...";

    int answer;
    std::cin >> answer;
    while (answer != 1 || answer != 2) {
        std::cout << "Invalid answer";
        std::cin >> answer;
    } 

    switch (answer) {
        case 1: 
        std::cout << "Izvēlēta preces uzskaite";
        // funkcija
    }
}