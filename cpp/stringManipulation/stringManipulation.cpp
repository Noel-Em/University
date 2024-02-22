#include <iostream>
#include <cstring> // Libreria per le funzioni di manipolazione delle stringhe

int main() {
    // Definizione e inizializzazione delle stringhe
    char stringa1[] = "Hello";
    char stringa2[20];

    // Copia la stringa1 nella stringa2
    strcpy(stringa2, stringa1); // Copia "Hello" in stringa2

    // Concatena " World" alla fine di stringa2
    strcat(stringa2, " World"); // Ora stringa2 contiene "Hello World"

    // Calcola la lunghezza di stringa2
    int lunghezza = strlen(stringa2); // lunghezza = 11

    // Confronta le due stringhe
    int confronto = strcmp(stringa1, stringa2); // confronto = -1, poiché "Hello" è considerato "minore" di "Hello World"

    // Stampa le stringhe e i risultati dei confronti
    std::cout << "Stringa1: " << stringa1 << std::endl;
    std::cout << "Stringa2: " << stringa2 << std::endl;
    std::cout << "Lunghezza di Stringa2: " << lunghezza << std::endl;
    std::cout << "Risultato del confronto: " << confronto << std::endl;

    return 0;
}