#include <iostream>
using namespace std;

int main() {
    int edad = 20;

    if (edad >= 18) {
        edad = 20;
        cout << "Es mayor de edad" << endl;
        return 0;
    }
    cout << "Es menor de edad";

    return 0;
}