#include <iostream>
#include <string>
#include <vector>
#include "structures.h"


int main() {
    std::vector<User> users = readUsersFromFile();
    std::vector<Worker> workers;
    readWorkersFromFile("worker.txt", workers);
    std::vector<Item> items;
    readItemFromFile("item.txt", items);
    std::vector<Shelf> shelfs;
    readShelfFromFile("shelf.txt", shelfs);
    login_screen:
    system("pause");
    system("cls");
    switch (LoginScreen()) {
        case 1:
            registerUser(users);
            goto login_screen;
        case 2:
            if (loginUser(users)) {
                std::cout << "Login successful!" << std::endl;
                second_screen:
                system("pause");
                system("cls");
                switch (SecondScreen()) {
                    case 1: {// User selected manage database
                        system("pause");
                        system("cls");
                        switch (ManageDatabaseScreen()) {
                            case 1:
                            add_to_database:
                                system("pause");
                                system("cls");
                                switch (AddToDatabaseScreen()) {
                                    case 1: { // ====================== WORKER TABLE ===============================
                                        std::cout << "WRITE TO WORKER TABLE (MAX QUERY LENGTH 22 CHAR)"
                                                  << std::endl;
                                        std::string query;
                                        std::string textWrite;
                                        std::string indent; // if input is odd

                                        std::cout << "Enter worker ID:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() > 22) {
                                            std::getline(std::cin, query);
                                        }
                                        query = "iD" + query;
                                        if (query.length() % 2 == 1) { indent = " "; }
                                        else { indent = ""; } // if query is odd, add an extra space on the left so the formatting is good
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                    spaceFormat((22 - query.length()) / 2) +
                                                    "||"; //  used for identifying the ID
                                        inputToFile("worker", "||" + textWrite);

                                        std::cout << "Enter worker name:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() > 22) {
                                            std::getline(std::cin, query);
                                        }
                                        if (query.length() % 2 == 1) { indent = " "; } else { indent = ""; }
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                    spaceFormat((22 - query.length()) / 2) + "||";
                                        inputToFile("worker", textWrite);

                                        std::cout << "Enter worker surname:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() > 22) {
                                            std::getline(std::cin, query);
                                        }
                                        if (query.length() % 2 == 1) { indent = " "; } else { indent = ""; }
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                    spaceFormat((22 - query.length()) / 2) + "||";
                                        inputToFile("worker", textWrite);

                                        std::cout << "Enter worker hiring date:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() > 22) {
                                            std::getline(std::cin, query);
                                        }
                                        if (query.length() % 2 == 1) { indent = " "; } else { indent = ""; }
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                    spaceFormat((22 - query.length()) / 2) + "||\n";
                                        inputToFile("worker", textWrite);

                                        std::cout << "Line successfully written to file!" << std::endl;
                                        goto add_to_database;
                                    }
                                    case 2: { // ========================= ITEM TABLE ============================
                                        std::string query;
                                        std::string textWrite;
                                        std::string indent; // if input is odd
                                        std::cout << "WRITE TO ITEM TABLE (MAX QUERY LENGTH 22 CHAR)" << std::endl;

                                        std::cout << "Enter item ID:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() >
                                                                      22) { // checks that the input will fit and is not empty
                                            std::getline(std::cin, query);
                                        }
                                        query = "iD" + query;
                                        if (query.length() % 2 == 1) { indent = " "; }
                                        else { indent = ""; } // if query is odd, add an extra space on the left so the formatting is good
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + "♯" + query +
                                                    spaceFormat((22 - query.length()) / 2) + "||";
                                        inputToFile("item", "||" + textWrite);

                                        std::cout << "Enter item name:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() > 22) {
                                            std::getline(std::cin, query);
                                        }
                                        if (query.length() % 2 == 1) { indent = " "; }
                                        else { indent = ""; }
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                    spaceFormat((22 - query.length()) / 2) + "||";
                                        inputToFile("item", textWrite);

                                        std::cout << "Enter ID of worker that stocked item:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() > 22) {
                                            std::getline(std::cin, query);
                                        }
                                        if (query.length() % 2 == 1) { indent = " "; }
                                        else { indent = ""; }
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                    spaceFormat((22 - query.length()) / 2) + "||";
                                        inputToFile("item", textWrite);

                                        std::cout << "Enter value of item:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() > 22) {
                                            std::getline(std::cin, query);
                                        }
                                        if (query.length() % 2 == 1) { indent = " "; }
                                        else { indent = ""; }
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                    spaceFormat((22 - query.length()) / 2) + "||";
                                        inputToFile("item", textWrite);

                                        std::cout << "Enter shelf ID of item:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() > 22) {
                                            std::getline(std::cin, query);
                                        }
                                        if (query.length() % 2 == 1) { indent = " "; }
                                        else { indent = ""; }
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                    spaceFormat((22 - query.length()) / 2) + "||";
                                        inputToFile("item", textWrite);

                                        std::cout << "Enter quantity of item:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() > 22) {
                                            std::getline(std::cin, query);
                                        }
                                        if (query.length() % 2 == 1) { indent = " "; }
                                        else { indent = ""; }
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                    spaceFormat((22 - query.length()) / 2) + "||\n";
                                        inputToFile("item", textWrite);

                                        goto add_to_database;
                                    }
                                    case 3: { // ============================= SHELF TABLE =======================
                                        std::string query;
                                        std::string textWrite;
                                        std::string indent; // if input is odd
                                        std::cout << "WRITE TO SHELF TABLE (MAX QUERY LENGTH 22 CHAR)" << std::endl;

                                        std::cout << "Enter shelf ID:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() >
                                                                      22) { // checks that the input will fit and is not empty
                                            std::getline(std::cin, query);
                                        }
                                        query = "iD" + query;
                                        if (query.length() % 2 == 1) { indent = " "; }
                                        else { indent = ""; } // if query is odd, add an extra space on the left so the formatting is good
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + "♯" + query +
                                                    spaceFormat((22 - query.length()) / 2) + "||";
                                        inputToFile("shelf", "||" + textWrite);

                                        std::cout << "Enter shelf location; X section:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() >
                                                                      22) { // checks that the input will fit and is not empty
                                            std::getline(std::cin, query);
                                        }
                                        if (query.length() % 2 == 1) { indent = " "; }
                                        else { indent = ""; } // if query is odd, add an extra space on the left so the formatting is good
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                    spaceFormat((22 - query.length()) / 2) + "||";
                                        inputToFile("shelf", textWrite);

                                        std::cout << "Enter shelf location; Y section:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() >
                                                                      22) { // checks that the input will fit and is not empty
                                            std::getline(std::cin, query);
                                        }
                                        if (query.length() % 2 == 1) { indent = " "; }
                                        else { indent = ""; } // if query is odd, add an extra space on the left so the formatting is good
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                    spaceFormat((22 - query.length()) / 2) + "||";
                                        inputToFile("shelf", textWrite);

                                        std::cout << "Enter shelf location; Z section:" << std::endl;
                                        query = "";
                                        while (query.length() == 0 or query.length() >
                                                                      22) { // checks that the input will fit and is not empty
                                            std::getline(std::cin, query);
                                        }
                                        if (query.length() % 2 == 1) { indent = " "; }
                                        else { indent = ""; } // if query is odd, add an extra space on the left so the formatting is good
                                        textWrite = indent + spaceFormat((22 - query.length()) / 2) + query +
                                                    spaceFormat((22 - query.length()) / 2) + "||\n";
                                        inputToFile("shelf", textWrite);

                                        goto add_to_database;
                                    }
                                    case 4:
                                        goto login_screen;
                                    default:
                                        std::cout << "Invalid selection" << std::endl;
                                        goto add_to_database;
                                }
                            case 2:
                            delete_from_database:
                                system("pause");
                                system("cls");
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
                                    }
                                    case 2: {
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
                                    }
                                    case 3: {
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
                                    }
                                    case 4: {
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
                                    }
                                    case 5:
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
                        system("pause");
                        system("cls");
                        switch (SearchOrFilterScreen()) {
                            case 1: {
                                system("pause");
                                system("cls");
                                filter_in:
                                std::cout
                                        << "Enter table to filter in (Worker/Item/Shelf) or write cancel to go back."
                                        << std::endl;
                                std::string filter;
                                std::cin >> filter;
                                if (filter.find("Worker") != std::string::npos or
                                    filter.find("WORKER") != std::string::npos or
                                    filter.find("worker") != std::string::npos) {
                                    std::cout << "TABLEWORKER" << std::endl;
                                    std::cout
                                            << "Enter section to filter in (Name/Surname/Hiring date) or write cancel to go back."
                                            << std::endl;
                                    std::string filterSection;
                                    std::cin >> filterSection;

                                    if (filterSection.find("Name") != std::string::npos or
                                        filterSection.find("NAME") != std::string::npos or
                                        filterSection.find("name") != std::string::npos) {
                                        std::cout << "Section name" << std::endl;
                                        std::cout << "Enter the filter for name section:" << std::endl;
                                        std::string name;
                                        std::cin >> name;

                                        std::vector<Worker> filteredItems = filterWorkersByName(workers, name);
                                        generateSummaryWorker(filteredItems);
                                        system("pause");
                                        system("cls");


                                    } else if (filterSection.find("Surname") != std::string::npos or
                                               filterSection.find("SURNAME") != std::string::npos or
                                               filterSection.find("surname") != std::string::npos) {
                                        std::cout << "Section surname" << std::endl;
                                        std::cout << "Enter the filter for surname section:" << std::endl;
                                        std::string surname;
                                        std::cin >> surname;

                                        std::vector<Worker> filteredItems = filterWorkersBySurname(workers, surname);
                                        generateSummaryWorker(filteredItems);
                                        system("pause");
                                        system("cls");


                                    } else if (filterSection.find("Hiring date") != std::string::npos or
                                               filterSection.find("HIRING DATE") != std::string::npos or
                                               filterSection.find("hiring Date") != std::string::npos) {
                                        std::cout << "Section hiring date" << std::endl;
                                        std::cout << "Enter the filter for hiring date section:" << std::endl;
                                        std::string hiringDate;
                                        std::cin >> hiringDate;


                                        std::vector<Worker> filteredItems = filterWorkersByHiringDate(workers,hiringDate);
                                        generateSummaryWorker(filteredItems);
                                        system("pause");
                                        system("cls");

                                    } else if (filter.find("Cancel") != std::string::npos or
                                               filter.find("CANCEL") != std::string::npos or
                                               filter.find("cancel") != std::string::npos) {
                                        std::cout << "Cancelling action..." << std::endl;
                                        goto second_screen;

                                    } else {
                                        std::cout << "Invalid table" << std::endl;
                                        goto filter_in;
                                    }

                                    goto filter_in;

                                } else if (filter.find("Item") != std::string::npos or
                                           filter.find("ITEM") != std::string::npos or
                                           filter.find("item") != std::string::npos) {
                                    std::cout << "TABLEITEM" << std::endl;

                                    std::cout
                                            << "Enter section to filter in (Name/Price/Quantity) or write cancel to go back."
                                            << std::endl;
                                    std::string filterSection;
                                    std::cin >> filterSection;

                                    if (filterSection.find("Name") != std::string::npos or
                                        filterSection.find("NAME") != std::string::npos or
                                        filterSection.find("name") != std::string::npos) {
                                        std::cout << "Section name" << std::endl;
                                        std::cout << "Enter the filter for name section:" << std::endl;
                                        std::string name;
                                        std::cin >> name;

                                        std::vector<Item> filteredItems = filterItemsByName(items, name);
                                        generateSummaryItem(filteredItems);
                                        system("pause");
                                        system("cls");


                                    } else if (filterSection.find("Price") != std::string::npos or
                                               filterSection.find("PRICE") != std::string::npos or
                                               filterSection.find("price") != std::string::npos) {
                                        std::cout << "Section price" << std::endl;
                                        std::cout << "Enter the filter for price section:" << std::endl;
                                        double price;
                                        std::cin >> price;

                                        std::vector<Item> filteredItems = filterItemsByPrice(items, price);
                                        generateSummaryItem(filteredItems);
                                        system("pause");
                                        system("cls");


                                    } else if (filterSection.find("Quantity") != std::string::npos or
                                               filterSection.find("QUANTITY") != std::string::npos or
                                               filterSection.find("quantity") != std::string::npos) {
                                        std::cout << "Section hiring date" << std::endl;
                                        std::cout << "Enter the filter for hiring date section:" << std::endl;
                                        int quantity;
                                        std::cin >> quantity;

                                        std::vector<Item> filteredItems = filterItemsByQuantity(items, quantity);
                                        generateSummaryItem(filteredItems);
                                        system("pause");
                                        system("cls");

                                    } else if (filter.find("Cancel") != std::string::npos or
                                               filter.find("CANCEL") != std::string::npos or
                                               filter.find("cancel") != std::string::npos) {
                                        std::cout << "Cancelling action..." << std::endl;
                                        goto second_screen;

                                    } else {
                                        std::cout << "Invalid table" << std::endl;
                                        goto filter_in;
                                    }

                                    goto filter_in;

                                } else if (filter.find("Shelf") != std::string::npos or
                                           filter.find("SHELF") != std::string::npos or
                                           filter.find("shelf") != std::string::npos) {
                                    std::cout << "TABLESHELF" << std::endl;

                                    std::cout
                                            << "Enter section to filter in (LocationX/LocationY/LocationZ) or write cancel to go back."
                                            << std::endl;
                                    std::string filterSection;
                                    std::cin >> filterSection;

                                    if (filterSection.find("LocationX") != std::string::npos or
                                        filterSection.find("LOCATIONX") != std::string::npos or
                                        filterSection.find("locationx") != std::string::npos) {
                                        std::cout << "Section LocationX" << std::endl;
                                        std::cout << "Enter the filter for LocationX section:" << std::endl;
                                        int locationx;
                                        std::cin >> locationx;

                                        std::vector<Shelf> filteredItems = filterShelfsByLocationX(shelfs, locationx);
                                        generateSummaryShelf(filteredItems);
                                        system("pause");
                                        system("cls");


                                    } else if (filterSection.find("LocationY") != std::string::npos or
                                               filterSection.find("LOCATIONY") != std::string::npos or
                                               filterSection.find("locationy") != std::string::npos) {
                                        std::cout << "Section LocationY" << std::endl;
                                        std::cout << "Enter the filter for LocationY section:" << std::endl;
                                        int locationy;
                                        std::cin >> locationy;

                                        std::vector<Shelf> filteredItems = filterShelfsByLocationY(shelfs, locationy);
                                        generateSummaryShelf(filteredItems);
                                        system("pause");
                                        system("cls");


                                    } else if (filterSection.find("LocationZ") != std::string::npos or
                                               filterSection.find("LOCATIONZ") != std::string::npos or
                                               filterSection.find("locationz") != std::string::npos) {
                                        std::cout << "Section LocationZ" << std::endl;
                                        std::cout << "Enter the filter for LocationZ section:" << std::endl;
                                        int locationz;
                                        std::cin >> locationz;

                                        std::vector<Shelf> filteredItems = filterShelfsByLocationZ(shelfs, locationz);
                                        generateSummaryShelf(filteredItems);
                                        system("pause");
                                        system("cls");

                                    } else if (filter.find("Cancel") != std::string::npos or
                                               filter.find("CANCEL") != std::string::npos or
                                               filter.find("cancel") != std::string::npos) {
                                        std::cout << "Cancelling action..." << std::endl;
                                        goto second_screen;

                                    } else {
                                        std::cout << "Invalid table" << std::endl;
                                        goto filter_in;
                                    }

                                    goto filter_in;

                                } else if (filter.find("Cancel") != std::string::npos or
                                           filter.find("CANCEL") != std::string::npos or
                                           filter.find("cancel") != std::string::npos) {
                                    std::cout << "Cancelling action..." << std::endl;
                                    goto second_screen;

                                } else {
                                    std::cout << "Invalid table" << std::endl;
                                    goto filter_in;
                                }
                            }

                            case 2: {
                                system("pause");
                                system("cls");
                                search_in:
                                system("cls");
                                std::cout
                                        << "Enter table to search in (Worker/Item/Shelf) or write cancel to go back."
                                        << std::endl;
                                std::string search;
                                std::cin >> search;
                                if (search.find("Worker") != std::string::npos or
                                    search.find("WORKER") != std::string::npos or
                                    search.find("worker") != std::string::npos) {
                                    std::cout << "TABLEWORKER" << std::endl;
                                    // Perform a search
                                    std::string searchID;
                                    std::cout << "Enter the ID to search: ";
                                    std::cin >> searchID;
                                    // Search for a worker
                                    Worker foundWorker = searchWorkerByID(workers, searchID);
                                    if (!foundWorker.getID().empty()) {
                                        std::cout
                                                << "=======================================DATABASE: WORKER.TXT======================================="
                                                << std::endl;
                                        std::cout
                                                << "=================================================================================================="
                                                << std::endl;
                                        std::cout
                                                << "||          ID          ||         NAME         ||       SUR-NAME       ||     WORKER SINCE     ||"
                                                << std::endl;
                                        std::cout
                                                << "=================================================================================================="
                                                << std::endl;
                                        std::cout << "||" << foundWorker.getID() << "||" << foundWorker.getName() << "||" << foundWorker.getSurname() << "||" << foundWorker.getHiringDate() << "||" << std::endl;
                                        system("pause");
                                        system("cls");
                                    } else {
                                        std::cout << "Worker not found." << std::endl;
                                    }
                                    goto search_in;
                                } else if (search.find("Item") != std::string::npos or
                                           search.find("ITEM") != std::string::npos or
                                           search.find("item") != std::string::npos) {
                                    std::cout << "TABLEITEM" << std::endl;
                                    // Perform a search
                                    std::string searchID;
                                    std::cout << "Enter the ID to search: ";
                                    std::cin >> searchID;
                                    // Search for an item
                                    Item foundItem = searchItemByID(items, searchID);
                                    if (!foundItem.getID().empty()) {
                                        std::cout
                                                << "================================================================DATABASE: ITEM.TXT================================================================"
                                                << std::endl;
                                        std::cout
                                                << "=================================================================================================================================================="
                                                << std::endl;
                                        std::cout
                                                << "||          ID          ||         NAME         ||      STOCKED BY      ||         VALUE        ||       SHELF ID       ||          QTY         ||"
                                                << std::endl;
                                        std::cout
                                                << "=================================================================================================================================================="
                                                << std::endl;
                                        std::cout << "||" << foundItem.getID() << "||" << foundItem.getName() << "||" << foundItem.getWorkerID() << "||" << foundItem.getPrice() << "||" << foundItem.getShelfID() << "||" << foundItem.getQuantity() << "||" << std::endl;
                                        system("pause");
                                        system("cls");
                                    } else {
                                        std::cout << "Item not found." << std::endl;
                                    }
                                    goto search_in;
                                } else if (search.find("Shelf") != std::string::npos or
                                           search.find("SHELF") != std::string::npos or
                                           search.find("shelf") != std::string::npos) {
                                    std::cout << "TABLESHELF" << std::endl;
                                    // Perform a search
                                    std::string searchID;
                                    std::cout << "Enter the ID to search: ";
                                    std::cin >> searchID;
                                    // Search for a shelf
                                    Shelf foundShelf = searchShelfByID(shelfs, searchID);
                                    if (!foundShelf.getID().empty()) {
                                        std::cout
                                                << "========================================DATABASE: SHELF.TXT======================================="
                                                << std::endl;
                                        std::cout
                                                << "=================================================================================================="
                                                << std::endl;
                                        std::cout
                                                << "||          ID          ||       SECTION.X      ||       SECTION.Y      ||       SECTION.Z      ||"
                                                << std::endl;
                                        std::cout
                                                << "=================================================================================================="
                                                << std::endl;
                                        std::cout << "||" << foundShelf.getID() << "||" << foundShelf.getLocationX() << "||" << foundShelf.getLocationY() << "||" << foundShelf.getLocationZ() << "||" << std::endl;
                                        system("pause");
                                        system("cls");
                                    } else {
                                        std::cout << "Shelf not found." << std::endl;
                                    }
                                    goto search_in;
                                } else if (search.find("Cancel") != std::string::npos or
                                           search.find("CANCEL") != std::string::npos or
                                           search.find("cancel") != std::string::npos) {
                                    std::cout << "Cancelling action..." << std::endl;
                                    goto second_screen;
                                } else {
                                    std::cout << "Invalid table" << std::endl;
                                    system("pause");
                                    system("cls");
                                    goto search_in;
                                }
                            }
                            case 3: {
                                system("pause");
                                system("cls");
                                sort_in:
                                std::cout
                                        << "Enter table to sort in (Worker/Item/Shelf) or write cancel to go back."
                                        << std::endl;
                                std::string sort;
                                std::cin >> sort;
                                if (sort.find("Worker") != std::string::npos or
                                    sort.find("WORKER") != std::string::npos or
                                    sort.find("worker") != std::string::npos) {
                                    std::cout << "TABLEWORKER" << std::endl;
                                    std::cout << "Enter the sort field for workers (name, surname, hiringDate): ";
                                    std::string sortField;
                                    std::cin >> sortField;
                                    sortWorkers(workers, sortField);
                                    generateSummaryWorker(workers);
                                    system("pause");
                                    system("cls");
                                    goto sort_in;

                                } else if (sort.find("Item") != std::string::npos or
                                           sort.find("ITEM") != std::string::npos or
                                           sort.find("item") != std::string::npos) {
                                    std::cout << "TABLEITEM" << std::endl;
                                    std::cout << "Enter the sort field for items (name, price, quantity): ";
                                    std::string sortField;
                                    std::cin >> sortField;
                                    sortItems(items, sortField);
                                    generateSummaryItem(items);
                                    system("pause");
                                    system("cls");
                                    goto sort_in;

                                } else if (sort.find("Shelf") != std::string::npos or
                                           sort.find("SHELF") != std::string::npos or
                                           sort.find("shelf") != std::string::npos) {
                                    std::cout << "TABLESHELF" << std::endl;
                                    std::cout << "Enter the sort field for shelfs (locationX, locationY, locationZ): ";
                                    std::string sortField;
                                    std::cin >> sortField;
                                    sortShelfs(shelfs, sortField);
                                    generateSummaryShelf(shelfs);
                                    system("pause");
                                    system("cls");
                                    goto sort_in;

                                } else if (sort.find("Cancel") != std::string::npos or
                                           sort.find("CANCEL") != std::string::npos or
                                           sort.find("cancel") != std::string::npos) {
                                    std::cout << "Cancelling action..." << std::endl;
                                    goto second_screen;

                                } else {
                                    std::cout << "Invalid table" << std::endl;
                                    goto sort_in;
                                }
                            }
                            case 4: {
                                system("pause");
                                system("cls");
                                goto second_screen;
                            }
                        }
                    }
                    case 3: { // User chose Display
                        system("pause");
                        system("cls");
                        switch (DisplayTableScreen()) {
                            case 1: {
                                display_table:
                                std::cout << "Enter table to display (Worker/Item/Shelf) or write cancel to cancel."
                                          << std::endl;
                                std::string display;
                                std::cin >> display;
                                if (display.find("Worker") != std::string::npos or
                                    display.find("WORKER") != std::string::npos or
                                    display.find("worker") != std::string::npos) {
                                    std::cout << "TABLEWORKER" << std::endl;
                                    displayDatabase("worker");
                                    goto display_table;
                                } else if (display.find("Item") != std::string::npos or
                                           display.find("ITEM") != std::string::npos or
                                           display.find("item") != std::string::npos) {
                                    std::cout << "TABLEITEM" << std::endl;
                                    displayDatabase("item");
                                    goto display_table;
                                } else if (display.find("Shelf") != std::string::npos or
                                           display.find("SHELF") != std::string::npos or
                                           display.find("shelf") != std::string::npos) {
                                    std::cout << "TABLESHELF" << std::endl;
                                    displayDatabase("shelf");
                                    goto display_table;
                                } else if (display.find("Cancel") != std::string::npos or
                                           display.find("CANCEL") != std::string::npos or
                                           display.find("cancel") != std::string::npos) {
                                    std::cout << "Cancelling action..." << std::endl;
                                    goto second_screen;
                                } else {
                                    std::cout << "Invalid table" << std::endl;
                                    goto display_table;
                                }
                            }
                            default:
                                goto second_screen;
                        }
                    }
                    case 4: {
                        goto login_screen;
                    }
                }
            } else {
                std::cout << "Invalid username or password." << std::endl;
                goto login_screen;
            }
        case 3:
            std::cout << "Exiting..." << std::endl;
            goto end_program;
    }
    end_program:
    return 0;
}
