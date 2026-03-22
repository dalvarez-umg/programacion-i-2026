#include <iostream>
using namespace std;

int main() {
    int numero = 0;
    cout << "Ingrese un numero: ";
    cin >> numero;

    for (int contador = 1; contador <= 10; contador++) {
        cout << numero << " * " << contador << " = " << numero * contador << endl;
    }
    return 0;
}