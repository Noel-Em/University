#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Record {
    char * name;
    int grade = 0;
};

struct RecordSet {
    int count = 0;
    Record* recordList = nullptr;
};

RecordSet init() {
    RecordSet record;
    record.count = 0;
    record.recordList = nullptr;
    return record;
}

void drop(RecordSet& rs) {
    delete [] rs.recordList;
}

int search(const RecordSet& rs, const char* name) {
    for(int i = 0; i < rs.count; i++) {
        if( strcmp(rs.recordList[i].name, name) == 0 ) {
            return i;
        }
    }

    return -1;
}

int insert(RecordSet& rs, const char* name, int grade) {
    int index = search(rs, name);
    if(index == -1) {
        Record * tmpRecord = new Record[rs.count + 1];
        for(int i = 0; i < rs.count; i++) {
            tmpRecord[i] = rs.recordList[i];
        }
        tmpRecord[rs.count].name = new char[strlen(name)];
        strcpy(tmpRecord[rs.count].name, name);
        tmpRecord[rs.count].grade = grade;
        delete[] rs.recordList;
        rs.recordList = tmpRecord;
        rs.count += 1;
        return rs.count - 1;
    }

    return -1;
}

int update(RecordSet& rs, const char* name, int grade) {
    int index = search(rs, name);
    if(index != -1) {
        rs.recordList[index].grade = grade;
    }

    return index;
}

int remove(RecordSet& rs, const char* name) {
    int index = search(rs, name);
    if(index != -1) {
        delete rs.recordList[index].name;
        rs.recordList[index].name = new char[strlen("CANCELLATO")];
        strcpy(rs.recordList[index].name, "CANCELLATO");
        rs.recordList[index].grade = -2;
    }

    return index;
}

int save(const RecordSet& rs, const char* filename) {
    ofstream myFile;
    myFile.open(filename, ios::out);
    if(!myFile.is_open()) {
        return -1;
    }

    myFile << rs.count << endl;
    for(int i = 0; i < rs.count; i++) {
        myFile << rs.recordList[i].name << " ";
        myFile << rs.recordList[i].grade << endl;
    }

    myFile.close();

    return 0;
}

void display(RecordSet& rs) {
    cout << "Nel record esistono: " << rs.count << " record" << endl;
    for(int i = 0; i < rs.count; i++) {
        cout << rs.recordList[i].name << " - " << rs.recordList[i].grade << endl;
    }
}

int main() {
    RecordSet set;
    set = init();
    display(set);
    insert(set, "Giacomo", 10);
    insert(set, "Kikkimunk", 28);
    update(set, "Giacomo", 31);
    remove(set, "Kikkimunk");
    display(set);

    save(set, "file.txt");

    drop(set);
}