#include <iostream>
#include <string>
#include <vector>
#include "structures.h"


int SecondScreen() {
    std::cout << "================= INVENTORY MANAGEMENT SYSTEM =================" << std::endl;
    std::cout << "1: Manage database..." << std::endl;
    std::cout << "2: Search/Filter options..." << std::endl;
    std::cout << "3: Display..." << std::endl;
    std::cout << "4: Logout" << std::endl;
    std::cout << "Select your action:";

    int answer;
    std::cin >> answer;
    while(std::cin.fail() or answer != 1 and answer != 2 and answer != 3 and answer !=4) { //checks if entered answer is integer and 1 or 2 or whatever number.
        std::cout << "Error" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> answer;
    }
    return answer;
}

int LoginScreen() {
    std::cout << "1. Register" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    int answer;
    std::cin >> answer;

    while(std::cin.fail() or answer != 1 and answer != 2 and answer != 3) { //checks if entered answer is integer and 1 or 2 or whatever number.
        std::cout << "Error" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> answer;
    }
    return answer;
}

int ManageDatabaseScreen() {
    std::cout << "================= MANAGE DATABASE =================" << std::endl;
    std::cout << "1: Add..." << std::endl;
    std::cout << "2: Delete..." << std::endl;
    std::cout << "3: Back" << std::endl;

    int answer;
    std::cin >> answer;

    while(std::cin.fail() or answer != 1 and answer != 2 and answer != 3) { //checks if entered answer is integer and 1 or 2 or whatever number.
        std::cout << "Error" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> answer;
    }
    return answer;

}

int AddToDatabaseScreen() {
    std::cout << "================= ADD TO DATABASE =================" << std::endl;
    std::cout << "1: Add to table \'Worker\'" << std::endl;
    std::cout << "2: Add to table \'Item\'" << std::endl;
    std::cout << "3: Add to table \'Shelf\'" << std::endl;
    std::cout << "4: Back" << std::endl;

    int answer;
    std::cin >> answer;

    while(std::cin.fail() or answer != 1 and answer != 2 and answer != 3 and answer != 4) { //checks if entered answer is integer and 1 or 2 or whatever number.
        std::cout << "Error" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> answer;
    }
    return answer;
}

int DeleteFromDatabaseScreen() {
    std::cout << "================= DELETE FROM DATABASE =================" << std::endl;
    std::cout << "1: Delete from table \'Worker\'" << std::endl;
    std::cout << "2: Delete from table \'Item\'" << std::endl;
    std::cout << "3: Delete from table \'Shelf\'" << std::endl;
    std::cout << "4: Drop database..." << std::endl;
    std::cout << "5: Back" << std::endl;

    int answer;
    std::cin >> answer;
    while(std::cin.fail() or answer != 1 and answer != 2 and answer != 3 and answer != 4 and answer != 5) { //checks if entered answer is integer and 1 or 2 or whatever number.
        std::cout << "Error" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> answer;
    }
    return answer;
}

int SearchOrFilterScreen() {
    std::cout << "================= SEARCH/FILTER =================" << std::endl;
    std::cout << "1: Filter by..." << std::endl;
    std::cout << "2: Search for..." << std::endl;
    std::cout << "3: Back" << std::endl;

    int answer;
    std::cin >> answer;

    while(std::cin.fail() or answer != 1 and answer != 2 and answer != 3) { //checks if entered answer is integer and 1 or 2 or whatever number.
        std::cout << "Error" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> answer;
    }
    return answer;
}

int DisplayTableScreen() {
    std::cout << "================= DISPLAY =================" << std::endl;
    std::cout << "1: Display table..." << std::endl;
    std::cout << "2: Back" << std::endl;

    int answer;
    std::cin >> answer;

    while(std::cin.fail() or answer != 1 and answer != 2) { //checks if entered answer is integer and 1 or 2.
        std::cout << "Error" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> answer;
    }
    return answer;
}

std::string spaceFormat(int number) { // for the formatting of user inputs
    std::string space(number, ' ');
    return space;
}


struct User {
    std::string username;
    std::string password;
};
//Login system --v
void writeUsersToFile(const std::vector<User>& users) {
    std::ofstream file("users.txt");
    if (file.is_open()) {
        for (const User& user : users) {
            file << user.username << "|||" << user.password << std::endl;
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
            int spaceIndex = line.find("|||");
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
    erase(user.username, ' ');
    while (std::cin.fail() || user.username.empty()) {
        std::cout << "Invalid username. Please try again: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> user.username;
    }
    std::cout << "Enter password: ";
    std::cin >> user.password;
    erase(user.password, ' ');
    while (std::cin.fail() || user.password.empty()) {
        std::cout << "Invalid password. Please try again: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> user.password;
    }
    for (const User& u : users) {
        if (u.username == user.username) {
            std::cout << "Username already exists. Please choose a different username." << std::endl;
            return;
        }
    }
    users.push_back(user);
    writeUsersToFile(users);
    std::cout << "Registration successful!" << std::endl;
}


bool loginUser(const std::vector<User>& users) {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    for (const User& user : users) {
        if (user.username == username && user.password == password) {
            return true;
        }
    }
    return false;
}
// ^-- Login system

int main() {
    std::vector<User> users = readUsersFromFile();
    login_screen:
    switch (LoginScreen()) {
        case 1:
            registerUser(users);
            goto login_screen;
        case 2:
            if (loginUser(users)) {
                std::cout << "Login successful!" << std::endl;
                second_screen:
                    switch (SecondScreen()) {
                        case 1: {// User selected manage database
                            switch (ManageDatabaseScreen()) {
                                case 1:
                                add_to_database:
                                    switch (AddToDatabaseScreen()) {

                                        case 1: { // ====================== WORKER TABLE ===============================
                                            std::cout << "WRITE TO WORKER TABLE (MAX QUERY LENGTH 22 CHAR)" << std::endl;
                                            std::string query;
                                            std::string textWrite;
                                            std::string indent; // if input is odd

                                            std::cout << "Enter worker ID:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length()>22) {
                                                std::getline (std::cin, query);
                                            }
                                            query = "iD" + query;
                                            if (query.length()%2 == 1) {indent = " ";} else {indent = "";} // if query is odd, add an extra space on the left so the formatting is good
                                            textWrite = indent + spaceFormat((22-query.length())/2) + query + spaceFormat((22-query.length())/2) + "||"; //  used for identifying the ID
                                            inputToFile("worker", "||"+textWrite);

                                            std::cout << "Enter worker name:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length()>22) {
                                                std::getline (std::cin, query);
                                            }
                                            if (query.length()%2 == 1) {indent = " ";} else {indent = "";}
                                            textWrite = indent + spaceFormat((22-query.length())/2) + query + spaceFormat((22-query.length())/2) + "||";
                                            inputToFile("worker", textWrite);

                                            std::cout << "Enter worker surname:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length()>22) {
                                                std::getline (std::cin, query);
                                            }
                                            if (query.length()%2 == 1) {indent = " ";} else {indent = "";}
                                            textWrite = indent + spaceFormat((22-query.length())/2) + query + spaceFormat((22-query.length())/2) + "||";
                                            inputToFile("worker", textWrite);

                                            std::cout << "Enter worker hiring date:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length()>22) {
                                                std::getline (std::cin, query);
                                            }
                                            if (query.length()%2 == 1) {indent = " ";} else {indent = "";}
                                            textWrite = indent + spaceFormat((22-query.length())/2) + query + spaceFormat((22-query.length())/2) + "||\n";
                                            inputToFile("worker", textWrite);

                                            std::cout << "Line successfully written to file!" << std::endl;
                                            goto add_to_database;



                                        } case 2: { // ========================= ITEM TABLE ============================
                                            std::string query;
                                            std::string textWrite;
                                            std::string indent; // if input is odd
                                            std::cout << "WRITE TO ITEM TABLE (MAX QUERY LENGTH 22 CHAR)" << std::endl;

                                            std::cout << "Enter item ID:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length()>22) { // checks that the input will fit and is not empty
                                                std::getline (std::cin, query);
                                            }
                                            query = "iD" + query;
                                            if (query.length() % 2 == 1) { indent = " "; }
                                            else { indent = ""; } // if query is odd, add an extra space on the left so the formatting is good
                                            textWrite = indent + spaceFormat((22 - query.length()) / 2) + "♯" + query +
                                                        spaceFormat((22 - query.length()) / 2) + "||";
                                            inputToFile("item", "||" + textWrite);

                                            std::cout << "Enter item name:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length()>22) {
                                                std::getline (std::cin, query);
                                            }
                                            if (query.length() % 2 == 1) { indent = " "; }
                                            else { indent = ""; }
                                            textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                        spaceFormat((22 - query.length()) / 2) + "||";
                                            inputToFile("item", textWrite);

                                            std::cout << "Enter ID of worker that stocked item:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length()>22) {
                                                std::getline (std::cin, query);
                                            }
                                            if (query.length() % 2 == 1) { indent = " "; }
                                            else { indent = ""; }
                                            textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                        spaceFormat((22 - query.length()) / 2) + "||";
                                            inputToFile("item", textWrite);

                                            std::cout << "Enter value of item:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length()>22) {
                                                std::getline (std::cin, query);
                                            }
                                            if (query.length() % 2 == 1) { indent = " "; }
                                            else { indent = ""; }
                                            textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                        spaceFormat((22 - query.length()) / 2) + "||";
                                            inputToFile("item", textWrite);

                                            std::cout << "Enter shelf ID of item:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length()>22) {
                                                std::getline (std::cin, query);
                                            }
                                            if (query.length() % 2 == 1) { indent = " "; }
                                            else { indent = ""; }
                                            textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                        spaceFormat((22 - query.length()) / 2) + "||";
                                            inputToFile("item", textWrite);

                                            std::cout << "Enter quantity of item:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length()>22) {
                                                std::getline (std::cin, query);
                                            }
                                            if (query.length() % 2 == 1) { indent = " "; }
                                            else { indent = ""; }
                                            textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                        spaceFormat((22 - query.length()) / 2) + "||\n";
                                            inputToFile("item", textWrite);

                                            goto add_to_database;



                                        } case 3: { // ============================= SHELF TABLE =======================
                                            std::string query;
                                            std::string textWrite;
                                            std::string indent; // if input is odd
                                            std::cout << "WRITE TO SHELF TABLE (MAX QUERY LENGTH 22 CHAR)" << std::endl;

                                            std::cout << "Enter shelf ID:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length() > 22) { // checks that the input will fit and is not empty
                                                std::getline (std::cin, query);
                                            }
                                            query = "iD" + query;
                                            if (query.length() % 2 == 1) { indent = " "; }
                                            else { indent = ""; } // if query is odd, add an extra space on the left so the formatting is good
                                            textWrite = indent + spaceFormat((22 - query.length()) / 2) + "♯" + query +
                                                        spaceFormat((22 - query.length()) / 2) + "||";
                                            inputToFile("shelf", "||" + textWrite);

                                            std::cout << "Enter shelf location; X section:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length() > 22) { // checks that the input will fit and is not empty
                                                std::getline (std::cin, query);
                                            }
                                            if (query.length() % 2 == 1) { indent = " "; }
                                            else { indent = ""; } // if query is odd, add an extra space on the left so the formatting is good
                                            textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                        spaceFormat((22 - query.length()) / 2) + "||";
                                            inputToFile("shelf",  textWrite);

                                            std::cout << "Enter shelf location; Y section:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length() > 22) { // checks that the input will fit and is not empty
                                                std::getline (std::cin, query);
                                            }
                                            if (query.length() % 2 == 1) { indent = " "; }
                                            else { indent = ""; } // if query is odd, add an extra space on the left so the formatting is good
                                            textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                        spaceFormat((22 - query.length()) / 2) + "||";
                                            inputToFile("shelf",  textWrite);

                                            std::cout << "Enter shelf location; Z section:" << std::endl;
                                            query = "";
                                            while (query.length() == 0 or query.length() > 22) { // checks that the input will fit and is not empty
                                                std::getline (std::cin, query);
                                            }
                                            if (query.length() % 2 == 1) { indent = " "; }
                                            else { indent = ""; } // if query is odd, add an extra space on the left so the formatting is good
                                            textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                        spaceFormat((22 - query.length()) / 2) + "||\n";
                                            inputToFile("shelf",  textWrite);

                                            goto add_to_database;

                                        }case 4:
                                            goto login_screen;
                                        default:
                                            std::cout << "Invalid selection" << std::endl;
                                            goto add_to_database;

                                    }
                                case 2:
                                delete_from_database:
                                    switch (DeleteFromDatabaseScreen()) {

                                        case 1: {
                                            std::cout << "DELETE FROM WORKER" << std::endl;
                                            std::string ID;

                                            if (fileExists("worker.txt")) {
                                                std::cout << "Enter worker ID to delete" << std::endl;
                                                std::cin >> ID;
                                                deleteFromFile("worker", "iD" + ID); // iD to identify the id

                                            } else {
                                                std::cout << "Table doesn't exist.";
                                            }
                                            goto delete_from_database;
                                        } case 2: {
                                            std::cout << "DELETE FROM ITEM" << std::endl;
                                            std::string ID;

                                            if (fileExists("item.txt")) {
                                                std::cout << "Enter item ID to delete" << std::endl;
                                                std::cin >> ID;
                                                deleteFromFile("item", "iD" + ID); // iD to identify the id

                                            } else {
                                                std::cout << "Table doesn't exist.";
                                            }
                                            goto delete_from_database;
                                        } case 3: {
                                            std::cout << "DELETE FROM SHELF" << std::endl;
                                            std::string ID;

                                            if (fileExists("shelf.txt")) {
                                                std::cout << "Enter shelf ID to delete" << std::endl;
                                                std::cin >> ID;
                                                deleteFromFile("shelf", "iD" + ID); // iD to identify the id

                                            } else {
                                                std::cout << "Table doesn't exist.";
                                            }
                                            goto delete_from_database;
                                        } case 4: {
                                            drop_database:
                                            std::cout << "DROP DATABASE" << std::endl;
                                            std::cout
                                                    << "Enter table name (worker/item/shelf) or type cancel to go back:"
                                                    << std::endl;
                                            std::string nameDB;
                                            std::cin >> nameDB;
                                            if (nameDB.find("Worker") != std::string::npos or
                                                nameDB.find("WORKER") != std::string::npos or
                                                nameDB.find("worker") != std::string::npos) {
                                                dropDatabase("worker");
                                            } else if (nameDB.find("Item") != std::string::npos or
                                                       nameDB.find("ITEM") != std::string::npos or
                                                       nameDB.find("item") != std::string::npos) {
                                                dropDatabase("item");
                                                goto second_screen;
                                            } else if (nameDB.find("Shelf") != std::string::npos or
                                                       nameDB.find("SHELF") != std::string::npos or
                                                       nameDB.find("shelf") != std::string::npos) {
                                                dropDatabase("shelf");
                                                goto second_screen;
                                            } else if (nameDB.find("Cancel") != std::string::npos or
                                                       nameDB.find("CANCEL") != std::string::npos or
                                                       nameDB.find("cancel") != std::string::npos) {
                                                std::cout << "Cancelling action..." << std::endl;
                                                goto second_screen;
                                            } else {
                                                std::cout << "Invalid table" << std::endl;
                                                goto drop_database;
                                            }

                                        } case 5:
                                            goto second_screen;
                                        default:
                                            std::cout << "Invalid selection" << std::endl;
                                            goto delete_from_database;


                                    }
                                case 3:
                                    goto second_screen;
                            }
                        }
                        case 2: { // User chose Search/Filter
                            switch (SearchOrFilterScreen()) {
                                case 1: {
                                    filter_in:
                                    std::cout << "Enter table to filter in (Worker/Item/Shelf) or write cancel to go back." << std::endl;
                                    std::string filter;
                                    std::cin >> filter;
                                    if (filter.find("Worker") != std::string::npos or filter.find("WORKER") != std::string::npos or filter.find("worker") != std::string::npos) {
                                        std::cout << "TABLEWORKER" << std::endl;
                                        goto filter_in;
                                    } else if (filter.find("Item") != std::string::npos or filter.find("ITEM") != std::string::npos or filter.find("item") != std::string::npos) {
                                        std::cout << "TABLEITEM" << std::endl;
                                        goto filter_in;
                                    } else if (filter.find("Shelf") != std::string::npos or filter.find("SHELF") != std::string::npos or filter.find("shelf") != std::string::npos) {
                                        std::cout << "TABLESHELF" << std::endl;
                                        goto filter_in;
                                    } else if (filter.find("Cancel") != std::string::npos or filter.find("CANCEL") != std::string::npos or filter.find("cancel") != std::string::npos) {
                                        std::cout << "Cancelling action..." << std::endl;
                                        goto second_screen;
                                    } else {
                                        std::cout << "Invalid table" << std::endl;
                                        goto filter_in;
                                    }
                                }
                                case 2: {
                                    search_in:
                                    std::cout << "Enter table to search in (Worker/Item/Shelf) or write cancel to go back." << std::endl;
                                    std::string search;
                                    std::cin >> search;
                                    if (search.find("Worker") != std::string::npos or search.find("WORKER") != std::string::npos or search.find("worker") != std::string::npos) {
                                        std::cout << "TABLEWORKER" << std::endl;
                                        goto search_in;
                                    } else if (search.find("Item") != std::string::npos or search.find("ITEM") != std::string::npos or search.find("item") != std::string::npos) {
                                        std::cout << "TABLEITEM" << std::endl;
                                        goto search_in;
                                    } else if (search.find("Shelf") != std::string::npos or search.find("SHELF") != std::string::npos or search.find("shelf") != std::string::npos) {
                                        std::cout << "TABLESHELF" << std::endl;
                                        goto search_in;
                                    } else if (search.find("Cancel") != std::string::npos or search.find("CANCEL") != std::string::npos or search.find("cancel") != std::string::npos) {
                                        std::cout << "Cancelling action..." << std::endl;
                                        goto second_screen;
                                    } else {
                                        std::cout << "Invalid table" << std::endl;
                                        goto search_in;
                                    }
                                }
                                case 3: {
                                    goto second_screen;
                                }
                            }
                        }
                        case 3: { // User chose Display
                            switch (DisplayTableScreen()) {
                                case 1: {
                                    display_table:
                                    std::cout << "Enter table to display (Worker/Item/Shelf) or write cancel to cancel." << std::endl;
                                    std::string display;
                                    std::cin >> display;
                                    if (display.find("Worker") != std::string::npos or display.find("WORKER") != std::string::npos or display.find("worker") != std::string::npos) {
                                        std::cout << "TABLEWORKER" << std::endl;
                                        displayDatabase("worker");
                                        goto display_table;
                                    } else if (display.find("Item") != std::string::npos or display.find("ITEM") != std::string::npos or display.find("item") != std::string::npos) {
                                        std::cout << "TABLEITEM" << std::endl;
                                        displayDatabase("item");
                                        goto display_table;
                                    } else if (display.find("Shelf") != std::string::npos or display.find("SHELF") != std::string::npos or display.find("shelf") != std::string::npos) {
                                        std::cout << "TABLESHELF" << std::endl;
                                        displayDatabase("shelf");
                                        goto display_table;
                                    } else if (display.find("Cancel") != std::string::npos or display.find("CANCEL") != std::string::npos or display.find("cancel") != std::string::npos) {
                                        std::cout << "Cancelling action..." << std::endl;
                                        goto second_screen;
                                    }
                                    else {
                                        std::cout << "Invalid table" << std::endl;
                                        goto display_table;
                                    }
                                }
                                default:
                                    goto second_screen;
                            }
                        }

                }
            }
            else {
                std::cout << "Invalid username or password." << std::endl;
                goto login_screen;
            }
        case 3:
            std::cout << "Exiting..." <<std::endl;
            goto end_program;
    }
    end_program:
        return 0;
}
