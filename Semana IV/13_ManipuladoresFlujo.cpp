#include <iomanip>
#include  <iostream>
using namespace std;

int main() {
    float precio = 12.45678;

    cout << fixed << setprecision(2);
    cout << "Precio: Q" << precio << endl;

    return 0;
}