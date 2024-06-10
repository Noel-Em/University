#include <string.h>
#include <iostream>

struct Book {
    char name[255];
    int copies = 0;
};

struct Library {
    Book * bookList;
    int bookCount = 0;
};

Library init() {
    Library nLib;
    nLib.bookList = new Book[nLib.bookCount];

    return nLib;
};

int add(Library& lib, const char* title, int copies) {
    Book * tmpList = new Book[lib.bookCount + 1];
    for(int i = 0; i < lib.bookCount; i++) {
        tmpList[i] = lib.bookList[i];
    }
    tmpList[lib.bookCount].copies = copies;
    strcpy(tmpList[lib.bookCount].name, title);
    delete[] lib.bookList;
    lib.bookList = tmpList;
    lib.bookCount = lib.bookCount + 1;

    return -1;
    
}

void display(Library& lib) {
    std::cout << "Nella libreria sono presenti " << lib.bookCount << " libri" << std::endl;
    for(int i = 0; i < lib.bookCount; i++) {
        std::cout << lib.bookList[i].name << " - Copie Disponibili: " << lib.bookList[i].copies <<  std::endl;
    }

    std::cout << "--------------------------------" << std::endl << std::endl;
}

int search(Library& lib, const char * title) {
    for(int i = 0; i < lib.bookCount; i++) {
        std::cout << lib.bookList[i].name << " - " << title << std::endl;
        if( strcmp(lib.bookList[i].name, title) == 0 ) {
            return i;
        }
    }

    return -1;
}

int update(Library& lib, const char * title, int copies) {
    int index = search(lib, title);
    if(index != -1) {
        lib.bookList[index].copies = copies;
    }

    return index;
}

int remove(Library& lib, const char * title) {
    int index = search(lib, title);
    if(index != -1) {

        Book * tmpList = new Book[lib.bookCount - 1];
        for(int i = 0; i < index; i++) {
            tmpList[i] = lib.bookList[i];
        }

        for(int i = index + 1; i < lib.bookCount; i++) {
            tmpList[i - 1] = lib.bookList[i];
        }

        delete[] lib.bookList;
        lib.bookList = tmpList;
        lib.bookCount = lib.bookCount - 1;

    }

    return index;
}

int main() {
    Library mainLib = init();
    add(mainLib, "Growsseth", 3);
    add(mainLib, "Seraph of the End", 2);
    add(mainLib, "Star Wars", 7);
    add(mainLib, "Godo", 5);
    display(mainLib);
    
    remove(mainLib, "Star Wars");
    display(mainLib);
    delete[] mainLib.bookList;
}