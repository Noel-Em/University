/*

    Name:           Pointer - Rubrica Telefonica
    Description:    Crea un programma che simula una rubrica telefonica, la rubrica deve permettere di
                        - Aggiungere contatti
                        - Visualizzare tutti i contatti
                        - Cercare un contatto per nome
                        - Eliminare un contatto
                    
                    Il contatto deve contenere un nome ed un numero.

*/


#include <iostream>
#include <cstring>

struct Contatto {
    char name[12];
    char number[10];
};

struct Rubrica {
    int contactSize = 0;
    Contatto* listaContatti = new Contatto[contactSize];
};

void aggiungiContatto(Rubrica& rubrica) {
    Contatto nuovoContatto;
    std::cout << "Nome contatto >> ";
    std::cin >> nuovoContatto.name;
    std::cout << "Numero contatto >> ";
    std::cin >> nuovoContatto.number;

    // Create a new temporary array with increased size
    Contatto* temp = new Contatto[rubrica.contactSize + 1];
    
    // Copy existing contacts to the new array
    for (int i = 0; i < rubrica.contactSize; ++i) {
        temp[i] = rubrica.listaContatti[i];
    }

    // Add the new contact to the new array
    temp[rubrica.contactSize] = nuovoContatto;

    // Delete the old array and update the address book
    delete[] rubrica.listaContatti;
    rubrica.listaContatti = temp;
    rubrica.contactSize += 1;
}

void visualizzaContatti(Rubrica& rubrica) {
    std::cout << rubrica.contactSize << std::endl;

    for(int i = 0; i < rubrica.contactSize; i++) {
        std::cout << rubrica.listaContatti[i].name << " - " << rubrica.listaContatti[i].number << std::endl;
    }

    std::system("PAUSE");
}

void menu(Rubrica& rubrica) {
    int select = 0;
    while(true) {
        std::system("CLS");
        std::cout << "1) Aggiungi un contatto" << std::endl;
        std::cout << "2) Visualizza tutti i contatti" << std::endl;
        std::cout << "3) Cerca contatto per nome" << std::endl;
        std::cout << "4) Elimina un contatto" << std::endl;
        std::cout << "Seleziona: ";
        std::cin >> select;
        std::cout << std::endl;
        std::system("CLS");
        if(select == 5) {
            break;
        }

        switch (select)
        {
        case 1:
            aggiungiContatto(rubrica);
            break;
        case 2:
            visualizzaContatti(rubrica);
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        }
    }
}

int main() {
    Rubrica rubrica;
    menu(rubrica);
}