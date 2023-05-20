#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "structures.h"


void select_basicString_action(const std::string& basicString,std::string data, std::string f1){
    system("cls");
    std::string f2 = "W";
    std::string f3 = "R";
    if (f1 == f2)
    {
        system("cls");
        std::ofstream file(basicString + ".txt");
        file << data << std::endl;
        file.close();
    }
    if (f1 == f3)
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
        else std::cout << "Unable to open data";
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

                    std::cout << "Inventory system" << std::endl;
                    std::cout << "1: Keep records of employees" << std::endl;
                    std::cout << "2: Keep records of goods" << std::endl;
                    std::cout << "3: Keep records of shelves" << std::endl;
                    std::cout << "4: Data output" << std::endl;
                    std::cout << "Choose an action: ";

                    int answer = 0;
                    while (answer != 4)
                    {
                        std::cout << "Invalid answer" << std::endl;
                        std::cin >> answer;
                        if (answer == 1 || answer == 2|| answer == 3|| answer == 4)
                        {
                            break;
                        }
                    }

                    std::string basicString;
                    std::string data;

                    std::string Worker;
                    std::string name;
                    std::string workerSince;

                    std::string Item;
                    std::string dateSince;
                    std::string value;

                    std::string Shelf;
                    std::string sectionX;
                    std::string sectionY;
                    std::string sectionZ;

                    switch (answer)
                    {
                        case 1:
                            std::cout << "Selected keep records of employees" << std::endl;
                            std::cout << "Enter the employee's first and last name: " << std::endl;
                            std::cin >> name;
                            std::cout << "Enter the start date format SS/MM/HH/DD/MM/YY" << std::endl;
                            std::cin >> workerSince;
                            data = name + "/////" + workerSince;
                            select_basicString_action(Worker, data, "W");
                            break;
                        case 2:
                            std::cout << "Selected keep records of goods" << std::endl;
                            std::cout << "Enter the transfer end time and date format SS/MM/HH/DD/MM/YY: " << std::endl;
                            std::cin >> dateSince;
                            std::cout << "Enter the barcode of the product: " << std::endl;
                            std::cin >> value;
                            data = dateSince + "/////" + value;
                            select_basicString_action(Item, data, "W");
                            break;
                        case 3:
                            std::cout << "Selected keep records of shelves" << std::endl;
                            std::cout << "Enter a row of sections for the shelf: " << std::endl;
                            std::cin >> sectionX;
                            std::cout << "Enter the vertical row for the shelf: " << std::endl;
                            std::cin >> sectionY;
                            std::cout << "Enter the horizontal row for the shelf: " << std::endl;
                            std::cin >> sectionZ;
                            data = sectionX + "/////" + sectionY+ "/////" + sectionZ;
                            select_basicString_action(Shelf, data, "W");
                            break;
                        case 4:
                            std::cout << "Selected data output" << std::endl;
                            select_basicString_action(Worker, data, "R");
                            select_basicString_action(Item, data, "R");
                            select_basicString_action(Shelf, data, "R");
                            break;
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
