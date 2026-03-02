#include <iostream>
#include <string>
using namespace std;

struct Producto {
    int codigo;
    string nombre;
    double precio;
};

struct Nodo {
    Producto data;
    Nodo* siguiente;
};

int main() {
    cout << "Nombre: Edwin Oswaldo Cortez Tista" << endl;

    Nodo* cabeza = nullptr;
    Nodo* ultimo = nullptr;

    // Creamos 4 nodos dinámicamente
    for (int i = 1; i <= 4; i++) {
        Nodo* nuevo = new Nodo;
        nuevo->siguiente = nullptr;

        cout << "--- Producto " << i << " ---" << endl;
        cout << "Ingrese codigo: ";
        cin >> nuevo->data.codigo;
        cin.ignore();
        cout << "Ingrese nombre: ";
        getline(cin, nuevo->data.nombre);
        cout << "Ingrese precio: ";
        cin >> nuevo->data.precio;

        if (cabeza == nullptr) {
            cabeza = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }

    // Mostrando mi nombre:
    cout << "Nombre: Edwin Oswaldo Cortez Tista" << endl;

    // Recorremos e imprimimos con el puntero auxiliar
    Nodo* actual = cabeza;
    double total = 0;
    while (actual != nullptr) {
        cout << "Codigo: " << actual->data.codigo << endl;
        cout << "Nombre: " << actual->data.nombre << endl;
        cout << "Precio: Q" << actual->data.precio << endl;
        cout << "--------------------" << endl;
        total += actual->data.precio;
        actual = actual->siguiente;
    }

    cout << "Total acumulado: Q" << total << endl;

    // Liberamos la memoria

    actual = cabeza;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    cabeza = nullptr;

    return 0;
}