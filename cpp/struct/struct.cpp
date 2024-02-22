#include <iostream>

// Definizione di una struct con membri public, private e protected
struct MyClass {
public:
    int publicVar;    // Membro accessibile da qualsiasi parte del programma
private:
    int privateVar;   // Membro accessibile solo dalla stessa classe o da funzioni amiche
protected:
    int protectedVar; // Membro accessibile solo dalla stessa classe o dalle sue classi derivate
};

int main() {
    MyClass obj;
    
    // Accesso ai membri pubblici
    obj.publicVar = 10;
    std::cout << "publicVar: " << obj.publicVar << std::endl;

    // Non è possibile accedere ai membri privati e protetti direttamente dal main
    // obj.privateVar = 20;  // Errore: privateVar è privato
    // obj.protectedVar = 30; // Errore: protectedVar è protetto

    return 0;
}