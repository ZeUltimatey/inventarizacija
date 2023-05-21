#include <string>
#include <fstream>

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
