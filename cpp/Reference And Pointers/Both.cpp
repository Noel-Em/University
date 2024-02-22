#include <iostream>

using namespace std;

// Funzione per incrementare un numero utilizzando un puntatore
void incrementa_con_puntatore(int* ptr) {
    (*ptr)++; // Incrementa il valore puntato da ptr
}

// Funzione per moltiplicare un numero utilizzando una reference costante
void moltiplica_con_reference(const int& ref, int* risultato) {
    *risultato *= ref; // Moltiplica il valore puntato da risultato con ref
}

int main() {
    int numero = 5;
    int risultato = 10;

    cout << "Valore di numero prima dell'incremento: " << numero << endl;

    // Chiamata alla funzione incrementa_con_puntatore utilizzando un puntatore
    incrementa_con_puntatore(&numero);

    cout << "Valore di numero dopo l'incremento: " << numero << endl;

    cout << "Valore di risultato prima della moltiplicazione: " << risultato << endl;

    // Chiamata alla funzione moltiplica_con_reference utilizzando una reference costante
    moltiplica_con_reference(numero, &risultato);

    cout << "Valore di risultato dopo la moltiplicazione: " << risultato << endl;

    return 0;
}