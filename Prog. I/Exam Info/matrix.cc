#include <iostream>

struct Record {
    char * name;
};

struct RecordSet {
    Record ** records;
    int countX;
    int countY;
};

RecordSet init(int rows, int columns) {
    RecordSet rs;
    rs.countX = 0;
    rs.countY = 0;
    rs.records = new Record*[rows];
    rs.countX = rows;
    rs.countY = columns;
    for(int i = 0; i < rows; i++) {
        rs.records[i] = new Record[columns];
        rs.records[i]->name = nullptr;
    }
    return { rs };
}

int main() {
    RecordSet rs;
    rs = init(10, 15);

    std::cout << rs.countX << " - " << rs.countY << std::endl;
    for(int i = 0; i < rs.countX; i++) {
        delete[] rs.records[i];
    }

    delete[] rs.records;
}