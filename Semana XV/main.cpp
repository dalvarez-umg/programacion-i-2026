#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Estudiante {
    int carnet;
    char nombre[30];
    float nota;
    bool activo;
};

const char* ARCHIVO = "estudiantes.dat";

void menu();
void crearEstudiante();
void listarEstudiantes();
void buscarEstudiante();
void actualizarEstudiante();
void eliminarEstudiante();
bool existeEstudiante(int carnet);

int main() {
    menu();
    return 0;
}

void menu() {
    int opcion;

    do {
        cout << "\n===== CRUD DE ESTUDIANTES =====\n";
        cout << "1. Crear estudiante\n";
        cout << "2. Listar estudiantes\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Actualizar estudiante\n";
        cout << "5. Eliminar estudiante\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearEstudiante();
                break;
            case 2:
                listarEstudiantes();
                break;
            case 3:
                buscarEstudiante();
                break;
            case 4:
                actualizarEstudiante();
                break;
            case 5:
                eliminarEstudiante();
                break;
            case 6:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);
}

void crearEstudiante() {
    Estudiante e;

    cout << "\n--- Crear estudiante ---\n";
    cout << "Carnet: ";
    cin >> e.carnet;

    if (existeEstudiante(e.carnet)) {
        cout << "Ya existe un estudiante con ese carnet.\n";
        return;
    }

    cin.ignore();

    cout << "Nombre: ";
    cin.getline(e.nombre, 30);

    cout << "Nota: ";
    cin >> e.nota;

    e.activo = true;

    ofstream archivo(ARCHIVO, ios::binary | ios::app);

    if (!archivo) {
        cout << "Error al abrir el archivo.\n";
        return;
    }

    archivo.write(reinterpret_cast<char*>(&e), sizeof(Estudiante));
    archivo.close();

    cout << "Estudiante guardado correctamente.\n";
}

void listarEstudiantes() {
    Estudiante e;

    ifstream archivo(ARCHIVO, ios::binary);

    if (!archivo) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    cout << "\n--- Lista de estudiantes activos ---\n";
    cout << left << setw(10) << "Carnet"
         << setw(30) << "Nombre"
         << setw(10) << "Nota" << endl;

    cout << "--------------------------------------------------\n";

    while (archivo.read(reinterpret_cast<char*>(&e), sizeof(Estudiante))) {
        if (e.activo) {
            cout << left << setw(10) << e.carnet
                 << setw(30) << e.nombre
                 << setw(10) << e.nota << endl;
        }
    }

    archivo.close();
}

void buscarEstudiante() {
    Estudiante e;
    int carnetBuscado;
    bool encontrado = false;

    cout << "\n--- Buscar estudiante ---\n";
    cout << "Ingrese carnet: ";
    cin >> carnetBuscado;

    ifstream archivo(ARCHIVO, ios::binary);

    if (!archivo) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    while (archivo.read(reinterpret_cast<char*>(&e), sizeof(Estudiante))) {
        if (e.carnet == carnetBuscado && e.activo) {
            cout << "\nEstudiante encontrado:\n";
            cout << "Carnet: " << e.carnet << endl;
            cout << "Nombre: " << e.nombre << endl;
            cout << "Nota: " << e.nota << endl;

            encontrado = true;
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "Estudiante no encontrado.\n";
    }
}

void actualizarEstudiante() {
    Estudiante e;
    int carnetBuscado;
    bool encontrado = false;

    cout << "\n--- Actualizar estudiante ---\n";
    cout << "Ingrese carnet: ";
    cin >> carnetBuscado;

    fstream archivo(ARCHIVO, ios::binary | ios::in | ios::out);

    if (!archivo) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    while (archivo.read(reinterpret_cast<char*>(&e), sizeof(Estudiante))) {
        if (e.carnet == carnetBuscado && e.activo) {
            cout << "\nDatos actuales:\n";
            cout << "Nombre: " << e.nombre << endl;
            cout << "Nota: " << e.nota << endl;

            cin.ignore();

            cout << "\nNuevo nombre: ";
            cin.getline(e.nombre, 30);

            cout << "Nueva nota: ";
            cin >> e.nota;

            archivo.seekp(-static_cast<int>(sizeof(Estudiante)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&e), sizeof(Estudiante));

            encontrado = true;
            cout << "Estudiante actualizado correctamente.\n";
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "Estudiante no encontrado.\n";
    }
}

void eliminarEstudiante() {
    Estudiante e;
    int carnetBuscado;
    bool encontrado = false;

    cout << "\n--- Eliminar estudiante ---\n";
    cout << "Ingrese carnet: ";
    cin >> carnetBuscado;

    fstream archivo(ARCHIVO, ios::binary | ios::in | ios::out);

    if (!archivo) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    while (archivo.read(reinterpret_cast<char*>(&e), sizeof(Estudiante))) {
        if (e.carnet == carnetBuscado && e.activo) {
            e.activo = false;

            archivo.seekp(-static_cast<int>(sizeof(Estudiante)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&e), sizeof(Estudiante));

            encontrado = true;
            cout << "Estudiante eliminado correctamente.\n";
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "Estudiante no encontrado.\n";
    }
}

bool existeEstudiante(int carnet) {
    Estudiante e;

    ifstream archivo(ARCHIVO, ios::binary);

    if (!archivo) {
        return false;
    }

    while (archivo.read(reinterpret_cast<char*>(&e), sizeof(Estudiante))) {
        if (e.carnet == carnet && e.activo) {
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}