#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
    if (f1 == 'W' || f1 == 'w')
    {
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
    if (f1 == 'R' || f1 == 'r')
    {
        system("cls");
        std::cout << "\n";
        std::string line;
        std::ifstream file (basicString + ".txt");
        if (file.is_open())
        {
            while ( getline (file,line))
            {
                std::cout << line << std::endl;
            }
            file.close();
        }
        else std::cout << "Unable to open posts";
    }
    system("pause");
    system("cls");
}


struct User {
    std::string username;
    std::string password;
};

void writeUsersToFile(std::vector<User> users) {
    std::ofstream file("users.txt");
    if (file.is_open()) {
        for (User user : users) {
            file << user.username << "coconut.png" << user.password << std::endl;
        }
        file.close();
    }
}

std::vector<User> readUsersFromFile() {
    std::vector<User> users;
    std::ifstream file("users.txt");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            User user;
            int spaceIndex = line.find("coconut.png");
            user.username = line.substr(0, spaceIndex);
            user.password = line.substr(spaceIndex + 1);
            users.push_back(user);
        }
        file.close();
    }
    return users;
}

void registerUser(std::vector<User>& users) {
    User user;
    std::cout << "Enter username: ";
    std::cin >> user.username;
    //erase(user.username, ' ');
    while (std::cin.fail() || user.username == "") {
        std::cout << "Invalid username. Please try again: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> user.username;
    }
    std::cout << "Enter password: ";
    std::cin >> user.password;
    while (std::cin.fail() || user.password == "") {
        std::cout << "Invalid password. Please try again: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> user.password;
    }
    for (User u : users) {
        if (u.username == user.username) {
            std::cout << "Username already exists. Please choose a different username." << std::endl;
            return;
        }
    }
    users.push_back(user);
    writeUsersToFile(users);
    std::cout << "Registration successful!" << std::endl;
}


bool loginUser(std::vector<User> users) {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    for (User user : users) {
        if (user.username == username && user.password == password) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<User> users = readUsersFromFile();
    int choice = 0;
    while (choice != 3) {
        std::cout << "1. Register" << std::endl;
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                registerUser(users);
                break;
            case 2:
                if (loginUser(users)) {
                    std::cout << "Login successful!" << std::endl;

                    std::cout << "Inventarizācijas sistēma" << std::endl;
                    std::cout << "1: Veikt darbinieku uzskaiti" << std::endl;
                    std::cout << "2: Veikt preces uzskaiti" << std::endl;
                    std::cout << "3: Veikt plauktu uzskaiti" << std::endl;
                    std::cout << "Izvēlieties darbību:";

                    int answer;
                    std::cin >> answer;
                    while (answer != 1 || answer != 2)
                    {
                        std::cout << "Invalid answer" << std::endl;
                        std::cin >> answer;
                        if (answer == 1 || answer == 2)
                        {
                            break;
                        }
                    }

                    switch (answer)
                    {
                        case 1:
                            std::cout << "Izvēlēta darbinieku uzskaite" << std::endl;
                            // funkcija
                        case 2:
                            std::cout << "Izvēlēta preces uzskaite" << std::endl;
                            // funkcija
                        case 3:
                            std::cout << "Izvēlēta plauktu uzskaite" << std::endl;
                            // funkcija
                        default:
                            std::cout << "Invalid choice" << std::endl;
                            break;
                    }

                } else {
                    std::cout << "Invalid username or password" << std::endl;
                }
                break;
            case 3:
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
                break;
        }
    }
    return 0;
}
