#include <string>

struct Worker {
    std::string name;
    std::string workerSince;
};

struct Item {
    std::string name;
    std::string dateSince;
    float value;
};

struct Shelf {
    int sectionX;
    int sectionY;
    int sectionZ;
};