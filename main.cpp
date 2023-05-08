#include <iostream>
#include "structures.h"


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