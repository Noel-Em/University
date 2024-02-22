#include <iostream>
using namespace std;

// Definizione di una struttura base
struct Base {
    virtual ~Base() {} // Assicura che il distruttore sia virtuale per la polimorfia
};

// Definizione di una struttura derivata
struct Derived : Base {
    int derivedValue;
};

int main() {
    Base* basePtr = new Derived(); // Puntatore a Derived assegnato a un puntatore a Base

    // Utilizzando dynamic_cast per convertire il puntatore da Base a Derived
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    
    if (derivedPtr) {
        derivedPtr->derivedValue = 10; // Accesso al membro specifico di Derived
        cout << "Valore derivato: " << derivedPtr->derivedValue << endl;
    } else {
        cout << "Conversione non riuscita!" << endl;
    }

    delete basePtr; // Deallocazione della memoria

    return 0;
}