#include <iostream>
using namespace std;

int main () {
    string nombre;
    cout << "Introduce tu nombre completo: ";
    getline(cin, nombre);

    cout << "Tu nombre es: " << nombre << endl;
    return 0;
}