#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

struct Product {
    char name[200] = "";
    int quantity = 0;
};

struct Inventory {
    Product * productList = nullptr;
    int count = 0;
};

Inventory init() {
    Inventory nInv;
    nInv.productList = new Product[nInv.count];

    return nInv;
}

void drop(Inventory& inv) {
    delete[] inv.productList;
}


int search(Inventory& inv, const char * name) {
    for(int i = 0; i < inv.count; i++) {
        if( strcmp(inv.productList[i].name, name) == 0 )
        {
            return i;
        }
    }

    return -1;
}

int add(Inventory& inv, const char * name, int quantity) {
    bool exist = false;

    if(search(inv, name) != -1) {
        return -1;
    }

    Product* tmpList = new Product[inv.count + 1];
    for(int i = 0; i < inv.count; i++) {
        tmpList[i] = inv.productList[i];
    }

    strcpy(tmpList[inv.count].name, name);
    tmpList[inv.count].quantity = quantity;

    delete[] inv.productList;
    inv.productList = tmpList;
    inv.count = inv.count + 1;

    return inv.count;
}

void save_file(Inventory& inv, const char * fileName) {
    ofstream sFile;
    sFile.open(fileName, ios::out | ios::binary);
    
    if(sFile.is_open()) {
        sFile << inv.count << std::endl;
        for(int i = 0; i < inv.count; i++) {
            sFile << inv.productList[i].name << " " << inv.productList[i].quantity << std::endl;
        }
    }

    sFile.close();
}

int main() {
    Inventory mainInv;
    mainInv = init();
    cout << add(mainInv, "Goku", 3) << endl; 
    cout << add(mainInv, "Freezer", 5) << endl; 
    cout << mainInv.productList[0].name << " - " << mainInv.productList[0].quantity << endl;
    cout << mainInv.productList[1].name << " - " << mainInv.productList[1].quantity << endl;
    cout << add(mainInv, "Goku", 3) << endl; 

    save_file(mainInv, "data.dat");
}