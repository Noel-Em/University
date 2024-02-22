#include <iostream>

using namespace std;

int main() {
    int numero = 10;
    int* puntatore_numero = &numero; // Puntatore a intero

    const int costante = 20;
    const int* puntatore_costante = &costante; // Puntatore a dati costanti
    int* const puntatore_costante_mutabile = &numero; // Puntatore costante

    cout << "Valore di numero: " << numero << endl;
    cout << "Indirizzo di numero: " << puntatore_numero << endl;
    cout << "Valore puntato da puntatore_numero: " << *puntatore_numero << endl;

    // Non possiamo modificare il valore puntato da puntatore_costante
    // *puntatore_costante = 30; // Errore: tentativo di modifica di dati costanti

    cout << "Valore di costante: " << costante << endl;
    cout << "Indirizzo di costante: " << puntatore_costante << endl;
    cout << "Valore puntato da puntatore_costante: " << *puntatore_costante << endl;

    // Possiamo modificare il valore puntato da puntatore_costante_mutabile
    *puntatore_costante_mutabile = 25;

    cout << "Nuovo valore di numero dopo la modifica tramite puntatore_costante_mutabile: " << numero << endl;

    // Non possiamo cambiare l'indirizzo puntato da puntatore_costante_mutabile
    // puntatore_costante_mutabile = nullptr; // Errore: tentativo di modificare un puntatore costante

    return 0;
}