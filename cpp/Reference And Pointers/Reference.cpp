#include <iostream>

using namespace std;

// Funzione che scambia i valori di due variabili utilizzando le reference
void scambia(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5;
    int y = 10;

    cout << "Prima dello scambio: " << endl;
    cout << "x = " << x << ", y = " << y << endl;

    // Chiamata alla funzione scambia utilizzando le reference
    scambia(x, y);

    cout << "Dopo lo scambio: " << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}