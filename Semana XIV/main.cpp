#include <iostream>
#include <fstream>

using namespace std;

// ===============================
// STRUCT
// ===============================
struct Mascota {
    int id;
    char nombre[30];
    char especie[20];
    int edad;
    float peso;
};

// ===============================
// FUNCIONES
// ===============================

void registrarMascota();
void mostrarMascotas();
void menu();

// ===============================
// MAIN
// ===============================

int main() {
    menu();
    return 0;
}

// ===============================
// MENÚ
// ===============================

void menu() {
    int opcion;
    do {
        cout << "\n==============================";
        cout << "\n  SISTEMA DE MASCOTAS";
        cout << "\n==============================";

        cout << "\n1. Registrar mascota";
        cout << "\n2. Mostrar mascotas";
        cout << "\n3. Salir";
        cout << "\n\nSeleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                registrarMascota();
                break;
            case 2:
                mostrarMascotas();
                break;
            case 3:
                cout << "\nPrograma finalizado.\n";
                break;
            default:
                cout << "\nOpcion invalida.\n";
        }
    } while(opcion != 3);
}

// ===============================
// REGISTRAR MASCOTA
// ===============================

void registrarMascota() {
    Mascota mascota;
    ofstream archivo("mascotas.dat", ios::binary | ios::app);

    if(!archivo) {
        cout << "\nError al abrir el archivo.\n";
        return;
    }

    cout << "\n========== REGISTRO ==========";
    cout << "\nID: ";
    cin >> mascota.id;
    cin.ignore();

    cout << "Nombre: ";
    cin.getline(mascota.nombre, 30);
    cout << "Especie: ";
    cin.getline(mascota.especie, 20);
    cout << "Edad: ";
    cin >> mascota.edad;
    cout << "Peso: ";
    cin >> mascota.peso;

    // Escritura binaria
    archivo.write((char*)&mascota, sizeof(mascota));
    archivo.close();
    cout << "\nMascota registrada correctamente.\n";
}

// ===============================
// MOSTRAR MASCOTAS
// ===============================

void mostrarMascotas() {
    Mascota m;
    ifstream archivo("mascotas.dat", ios::binary);
    if(!archivo) {
        cout << "\nNo existe informacion almacenada.\n";
        return;
    }

    cout << "\n========== LISTADO ==========\n";
    while(archivo.read((char*)&m, sizeof(m))) {

        cout << "\n-------------------------";
        cout << "\nID: " << m.id;
        cout << "\nNombre: " << m.nombre;
        cout << "\nEspecie: " << m.especie;
        cout << "\nEdad: " << m.edad;
        cout << "\nPeso: " << m.peso << " lbs";
        cout << "\n-------------------------\n";
    }
    archivo.close();
}