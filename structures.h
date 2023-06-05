#include <string>
#include <fstream>


// User class
struct User {
    std::string username;
    std::string password;
};

// Worker class
class Worker {
public:
    std::string id;
    std::string name;
    std::string surname;
    std::string hiringDate;

    // Constructor
    Worker(std::string id, std::string name, std::string surname, std::string hiringDate)
            : id(id), name(std::move(name)), surname(std::move(surname)), hiringDate(std::move(hiringDate)) {}

    std::string getID() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    std::string getSurname() const {
        return surname;
    }

    std::string getHiringDate() const {
        return hiringDate;
    }

};

// Item class
class Item {
public:
    std::string id;
    std::string name;
    std::string workerID;
    std::string price;
    std::string shelfID;
    std::string quantity;

    // Constructor
    Item(std::string id, std::string name, std::string workerID, std::string price, std::string shelfID, std::string quantity)
            : id(id), name(std::move(name)), workerID(workerID), price(price), shelfID(shelfID), quantity(quantity) {}

    std::string getID() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    std::string getWorkerID() const {
        return workerID;
    }

    std::string getPrice() const {
        return price;
    }

    std::string getShelfID() const {
        return shelfID;
    }

    std::string getQuantity() const {
        return quantity;
    }

};

// Shelf class
class Shelf {
public:
    std::string id;
    std::string locationX;
    std::string locationY;
    std::string locationZ;

    // Constructor
    Shelf(std::string id, std::string locationX, std::string locationY, std::string locationZ)
            : id(id), locationX(std::move(locationX)), locationY(std::move(locationY)), locationZ(std::move(locationZ)) {}

    std::string getID() const {
        return id;
    }

    std::string getLocationX() const {
        return locationX;
    }

    std::string getLocationY() const {
        return locationY;
    }

    std::string getLocationZ() const {
        return locationZ;
    }
};

void generateSummaryWorker(const std::vector<Worker>& Workers) {
    std::cout << "Summary of the Worker Database:" << std::endl;
    // Summary for the Worker table
    std::cout << "Workers:" << std::endl;
    for (const Worker& Worker : Workers) {
        std::cout << "Worker ID: " << Worker.getID() << std::endl;
        std::cout << "Name: " << Worker.getName() << std::endl;
        std::cout << "Surname: " << Worker.getSurname() << std::endl;
        std::cout << "Hiring Date: " << Worker.getHiringDate() << std::endl;
        std::cout << std::endl;
    }
}

void generateSummaryItem(const std::vector<Item>& items) {
    std::cout << "Summary of the Item Database:" << std::endl;
    // Summary for the Item table
    std::cout << "Items:" << std::endl;
    for (const Item& item : items) {
        std::cout << "Item ID: " << item.getID() << std::endl;
        std::cout << "Name: " << item.getName() << std::endl;
        std::cout << "Worker ID: " << item.getWorkerID() << std::endl;
        std::cout << "Price: " << item.getPrice() << std::endl;
        std::cout << "Shelf ID: " << item.getShelfID() << std::endl;
        std::cout << "Quantity: " << item.getQuantity() << std::endl;
        std::cout << std::endl;
    }
}

void generateSummaryShelf(const std::vector<Shelf>& shelves) {
    std::cout << "Summary of the Shelf Database:" << std::endl;
    // Summary for the Shelf table
    std::cout << "Shelves:" << std::endl;
    for (const Shelf& shelf : shelves) {
        std::cout << "Shelf ID: " << shelf.getID() << std::endl;
        std::cout << "LocationX: " << shelf.getLocationX() << std::endl;
        std::cout << "LocationY: " << shelf.getLocationY() << std::endl;
        std::cout << "LocationZ: " << shelf.getLocationZ() << std::endl;
        std::cout << std::endl;
    }
}

void readWorkersFromFile(const std::string& filename, std::vector<Worker>& workers) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    std::string line;
    for(int i = 0; i < 5; i++) {
        std::getline(file, line); // Skip the header line
    }
    while (std::getline(file, line)) {
        Worker worker("", "", "", "");
        std::string id, name, surname, hiringDate;

        // Extract data from the line using appropriate delimiters
        std::size_t start = line.find("||") + 2;
        std::size_t end = line.find("||", start);
        id = line.substr(start, end - start);
        id.erase(remove(id.begin(), id.end(), ' '), id.end());

        start = end + 2;
        end = line.find("||", start);
        name = line.substr(start, end - start);
        name.erase(remove(name.begin(), name.end(), ' '), name.end());

        start = end + 2;
        end = line.find("||", start);
        surname = line.substr(start, end - start);
        surname.erase(remove(surname.begin(), surname.end(), ' '), surname.end());

        start = end + 2;
        end = line.find("||", start);
        hiringDate = line.substr(start, end - start);
        hiringDate.erase(remove(hiringDate.begin(), hiringDate.end(), ' '), hiringDate.end());

        // Convert necessary data types
        worker.id = id;
        worker.name = name;
        worker.surname = surname;
        worker.hiringDate = hiringDate;

        // Add the worker to the vector
        workers.push_back(worker);
    }

    file.close();
}

void readItemFromFile(const std::string& filename, std::vector<Item>& items) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    std::string line;
    for(int i = 0; i < 5; i++) {
        std::getline(file, line); // Skip the header line
    }
    while (std::getline(file, line)) {
        Item item("", "", "", "", "", "");
        std::string id, name, workerID, price, shelfID, quantity;

        // Extract data from the line using appropriate delimiters
        std::size_t start = line.find("||") + 2;
        std::size_t end = line.find("||", start);
        id = line.substr(start, end - start);

        start = end + 2;
        end = line.find("||", start);
        name = line.substr(start, end - start);

        start = end + 2;
        end = line.find("||", start);
        workerID = line.substr(start, end - start);

        start = end + 2;
        end = line.find("||", start);
        price = line.substr(start, end - start);

        start = end + 2;
        end = line.find("||", start);
        shelfID = line.substr(start, end - start);

        start = end + 2;
        end = line.find("||", start);
        quantity = line.substr(start, end - start);

        // Convert necessary data types
        item.id = id;
        item.name = name;
        item.workerID = workerID;
        item.price = price;
        item.shelfID = shelfID;
        item.quantity = quantity;


        // Add the worker to the vector
        items.push_back(item);
    }

    file.close();
}

void readShelfFromFile(const std::string& filename, std::vector<Shelf>& shelfs) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    std::string line;
    for(int i = 0; i < 5; i++) {
        std::getline(file, line); // Skip the header line
    }
    while (std::getline(file, line)) {
        Shelf shelf("", "", "", "");
        std::string id, locationX, locationY, locationZ;

        // Extract data from the line using appropriate delimiters
        std::size_t start = line.find("||") + 2;
        std::size_t end = line.find("||", start);
        id = line.substr(start, end - start);

        start = end + 2;
        end = line.find("||", start);
        locationX = line.substr(start, end - start);

        start = end + 2;
        end = line.find("||", start);
        locationY = line.substr(start, end - start);

        start = end + 2;
        end = line.find("||", start);
        locationZ = line.substr(start, end - start);

        // Convert necessary data types
        shelf.id = id;
        shelf.locationX = locationX;
        shelf.locationY = locationY;
        shelf.locationZ = locationZ;

        // Add the worker to the vector
        shelfs.push_back(shelf);
    }

    file.close();
}

bool fileExists (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

void createFile(const std::string name) {
    if (name == "worker") {
        std::fstream workerF ("worker.txt", std::ios::out);
        if (workerF.is_open()) {
            workerF << "=======================================DATABASE: WORKER.TXT=======================================" << std::endl;
            workerF << "==================================================================================================" << std::endl;
            workerF << "||          ID          ||         NAME         ||       SUR-NAME       ||     WORKER SINCE     ||" << std::endl;
            workerF << "==================================================================================================" << std::endl;
            workerF.close();
        } else {
            std::cout << "Error; worker file didn't open" << std::endl;
        }
    }
    if (name == "item") {
        std::fstream itemF ("item.txt", std::ios::out);
        if (itemF.is_open()) {
            itemF << "================================================================DATABASE: ITEM.TXT================================================================" << std::endl;
            itemF << "==================================================================================================================================================" << std::endl;
            itemF << "||          ID          ||         NAME         ||      STOCKED BY      ||         VALUE        ||       SHELF ID       ||          QTY         ||" << std::endl;
            itemF << "==================================================================================================================================================" << std::endl;
            itemF.close();
        } else {
            std::cout << "Error; item file didn't open" << std::endl;
        }
    }
    if (name == "shelf") {
        std::fstream shelfF ("shelf.txt", std::ios::out);
        if (shelfF.is_open()) {
            shelfF << "========================================DATABASE: SHELF.TXT=======================================" << std::endl;
            shelfF << "==================================================================================================" << std::endl;
            shelfF << "||          ID          ||       SECTION.X      ||       SECTION.Y      ||       SECTION.Z      ||" << std::endl;
            shelfF << "==================================================================================================" << std::endl;
            shelfF.close();
        } else {
            std::cout << "Error; shelf file didn't open" << std::endl;
        }
    }
};

void inputToFile(std::string fileName, std::string query) {
    add_to_file:
    if (fileExists(fileName + ".txt")) {
        std::fstream fileF (fileName + ".txt", std::ios::app);
        fileF << query;
        fileF.close();
    } else {
        createFile(fileName);
        goto add_to_file;
    }
}

void deleteFromFile (std::string fileName, std::string ID) {
    fileName = fileName + ".txt";
    std::fstream fileF (fileName, std::ios::in);
    std::string line;
    std::string tempFileName = "temp.tmp";
    std::ofstream tempFile(tempFileName); // make temp file to write contents to

    bool deleted = false;

    while (std::getline(fileF, line)) {
        if (line.find(ID) == std::string::npos) { // write to temp file if ID not found in line
            tempFile << line << std::endl;
        } else {
            deleted = true;
        }
    }

    fileF.close();
    tempFile.close();

    if (deleted) {
        remove(fileName.c_str());
        rename(tempFileName.c_str(), fileName.c_str());
        std::cout << "Worker successfully deleted from table." << std::endl;
    } else {
        std::cout << "Worker ID not found." << std::endl;
    }

}

void dropDatabase(std::string fileName) {
    fileName = fileName + ".txt";
    std::cout << "Are you sure you want to delete table " + fileName + "?" << std::endl;
    std::cout << "type \'confirm\' to confirm deletion." << std::endl;
    std::string answer;
    std::cin >> answer;
    if (answer == "confirm") {
        remove(fileName.c_str());
        std::cout << "Table successfully deleted." << std::endl;
    }
    else {
        std::cout << "Deletion cancelled..." << std::endl;
    }
}

void displayDatabase(std::string fileName) {
    std::fstream fileF (fileName + ".txt", std::ios::in);
    std::string line;

    if(fileExists(fileName + ".txt")) {
        while (std::getline(fileF, line)) {
            std::cout << line << std::endl;
        }
    }
    else {
        std::cout << "Error: table doesn't exist" << std::endl;
    }
}

void writeUsersToFile(const std::vector<User>& users) {
    std::ofstream file("users.txt", std::ios::out);
    if (file.is_open()) {
        for (const User& user : users) {
            file << user.username << "||" << user.password << std::endl;
        }
        file.close();
    }
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


std::vector<Worker> filterWorkersByName(const std::vector<Worker>& workers, const std::string& name) {
    std::vector<Worker> filteredWorkers;
    for (const auto& worker : workers) {
        if (worker.name == name) {
            filteredWorkers.push_back(worker);
        }
    }
    return filteredWorkers;
}

std::vector<Worker> filterWorkersBySurname(const std::vector<Worker>& workers, const std::string& surname) {
    std::vector<Worker> filteredWorkers;
    for (const auto& worker : workers) {
        if (worker.surname == surname) {
            filteredWorkers.push_back(worker);
        }
    }
    return filteredWorkers;
}

std::vector<Worker> filterWorkersByHiringDate(const std::vector<Worker>& workers, const std::string& hiringDate) {
    std::vector<Worker> filteredWorkers;
    for (const auto& worker : workers) {
        if (worker.hiringDate == hiringDate) {
            filteredWorkers.push_back(worker);
        }
    }
    return filteredWorkers;
}

std::vector<Item> filterItemsByName(const std::vector<Item>& items, const std::string& name) {
    std::vector<Item> filteredItems;
    for (const auto& item : items) {
        if (item.name == name) {
            filteredItems.push_back(item);
        }
    }
    return filteredItems;
}

std::vector<Item> filterItemsByPrice(const std::vector<Item>& items, double maxPrice) {
    std::vector<Item> filteredItems;
    for (const auto& item : items) {
        if (std::stod(item.price) <= maxPrice) {
            filteredItems.push_back(item);
        }
    }
    return filteredItems;
}

std::vector<Item> filterItemsByQuantity(const std::vector<Item>& items, int quantity) {
    std::vector<Item> filteredItems;
    for (const auto& item : items) {
        if (std::stoi(item.quantity) == quantity) {
            filteredItems.push_back(item);
        }
    }
    return filteredItems;
}

std::vector<Shelf> filterShelfsByLocationX(const std::vector<Shelf>& shelfs, int locationX) {
    std::vector<Shelf> filteredItems;
    for (const auto& shelf : shelfs) {
        if (std::stoi(shelf.locationX) == locationX) {
            filteredItems.push_back(shelf);
        }
    }
    return filteredItems;
}

std::vector<Shelf> filterShelfsByLocationY(const std::vector<Shelf>& shelfs, int locationY) {
    std::vector<Shelf> filteredItems;
    for (const auto& shelf : shelfs) {
        if (std::stoi(shelf.locationY) == locationY) {
            filteredItems.push_back(shelf);
        }
    }
    return filteredItems;
}

std::vector<Shelf> filterShelfsByLocationZ(const std::vector<Shelf>& shelfs, int locationZ) {
    std::vector<Shelf> filteredItems;
    for (const auto& shelf : shelfs) {
        if (std::stoi(shelf.locationZ) == locationZ) {
            filteredItems.push_back(shelf);
        }
    }
    return filteredItems;
}

void sortWorkers(std::vector<Worker>& workers, const std::string& sortField) {
    if (sortField == "name") {
        std::sort(workers.begin(), workers.end(), [](const Worker& a, const Worker& b) {
            return a.name < b.name;
        });
    } else if (sortField == "age") {
        std::sort(workers.begin(), workers.end(), [](const Worker& a, const Worker& b) {
            return a.surname < b.surname;
        });
    } else if (sortField == "Hiring date") {
        std::sort(workers.begin(), workers.end(), [](const Worker& a, const Worker& b) {
            return a.hiringDate < b.hiringDate;
        });
    } else {
        std::cout << "Invalid sort field!" << std::endl;
    }
}

void sortItems(std::vector<Item>& items, const std::string& sortField) {
    if (sortField == "name") {
        std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.name < b.name;
        });
    } else if (sortField == "price") {
        std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.price < b.price;
        });
    } else if (sortField == "quantity") {
        std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.quantity < b.quantity;
        });
    } else {
        std::cout << "Invalid sort field!" << std::endl;
    }
}

void sortShelfs(std::vector<Shelf>& shelfs, const std::string& sortField) {
    if (sortField == "locationX") {
        std::sort(shelfs.begin(), shelfs.end(), [](const Shelf& a, const Shelf& b) {
            return a.locationX < b.locationX;
        });
    } else if (sortField == "locationY") {
        std::sort(shelfs.begin(), shelfs.end(), [](const Shelf& a, const Shelf& b) {
            return a.locationY < b.locationY;
        });
    } else if (sortField == "locationZ") {
        std::sort(shelfs.begin(), shelfs.end(), [](const Shelf& a, const Shelf& b) {
            return a.locationZ < b.locationZ;
        });
    } else {
        std::cout << "Invalid sort field!" << std::endl;
    }
}
