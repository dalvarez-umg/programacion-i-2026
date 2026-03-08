#include <iostream>
using namespace std;

int main() {
    string nombre;
    int edad;
    float estatura;
    cout << "Introduce tu nombre: ";
    getline(cin, nombre);
    cout << "Introduce edad: ";
    cin >> edad;
    cout << "Introduce estatura: ";
    cin >> estatura;

    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Estatura: " << estatura << endl;

    return 0;
}