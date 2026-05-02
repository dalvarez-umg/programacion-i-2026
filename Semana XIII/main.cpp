#include <iostream>
using namespace std;

struct Estudiante {
    string carne;
    string nombre;
    int edad;
    float nota1;
    float nota2;
    float nota3;
};

Estudiante registrarEstudiante() {
    Estudiante e;
    cout << "Ingrese carne: "; cin >> e.carne;
    cout << "Ingrese nombre: "; cin.ignore(); getline(cin, e.nombre);
    cout << "Ingrese edad: "; cin >> e.edad;
    cout << "Ingrese nota 1: "; cin >> e.nota1;
    cout << "Ingrese nota 2: "; cin >> e.nota2;
    cout << "Ingrese nota 3: "; cin >> e.nota3;
    return e;
}

void mostrarEstudiante(Estudiante e) {
    cout << "\n--- INFORMACION DEL ESTUDIANTE ---" << endl;
    cout << "Carne: " << e.carne << endl;
    cout << "Nombre: " << e.nombre << endl;
    cout << "Edad: " << e.edad << endl;
    cout << "Nota 1: " << e.nota1 << endl;
    cout << "Nota 2: " << e.nota2 << endl;
    cout << "Nota 3: " << e.nota3 << endl;
}

float calcularPromedio(Estudiante e) {
    return (e.nota1 + e.nota2 + e.nota3) / 3;
}

void mostrarResultado(Estudiante e) {
    float promedio = calcularPromedio(e);
    cout << "Promedio: " << promedio << endl;
    if (promedio >= 61) {
        cout << "Estado: Aprobado" << endl;
    } else {
        cout << "Estado: Reprobado" << endl;
    }
}

void modificarNota(Estudiante &e) {
    int opcion;
    float nuevaNota;

    cout << "\nQue nota desea modificar? ";
    cout << "\n1. Nota 1";
    cout << "\n2. Nota 2";
    cout << "\n3. Nota 3";
    cout << "\nOpcion: ";
    cin >> opcion;

    cout << "Ingrese nueva nota: ";
    cin >> nuevaNota;

    if (opcion == 1) {
        e.nota1 = nuevaNota;
    } else if (opcion == 2) {
        e.nota2 = nuevaNota;
    } else if (opcion == 3) {
        e.nota3 = nuevaNota;
    } else {
        cout << "Opcion invalida." << endl;
    }
}

int main() {
    Estudiante estudiante;
    int opcion;
    bool registrado = false;

    do {
        cout << "\n===== REGISTRO DE ESTUDIANTES =====" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Mostrar estudiante" << endl;
        cout << "3. Mostrar promedio y estado" << endl;
        cout << "4. Modificar nota" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                estudiante = registrarEstudiante();
                registrado = true;
                break;

            case 2:
                if (registrado) {
                    mostrarEstudiante(estudiante);
                } else {
                    cout << "Primero debe registrar un estudiante." << endl;
                }
                break;

            case 3:
                if (registrado) {
                    mostrarResultado(estudiante);
                } else {
                    cout << "Primero debe registrar un estudiante." << endl;
                }
                break;

            case 4:
                if (registrado) {
                    modificarNota(estudiante);
                } else {
                    cout << "Primero debe registrar un estudiante." << endl;
                }
                break;

            case 5:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 5);

    return 0;
}