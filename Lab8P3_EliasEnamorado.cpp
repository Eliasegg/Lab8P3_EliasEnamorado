#include <iostream>
#include "Usuario.h"
#include "Contenedor.h"

using namespace std;

int getOpcion(int max) {
    int opcion;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    while (opcion < 0 || opcion > max) {
        cout << "Opcion invalida. Ingrese una opcion: ";
        cin >> opcion;
    }
    return opcion;
}

bool validarCredenciales(string user, string contra, const Contenedor<Usuario>& contenedor) {
    for (const auto& usuario : contenedor.obtenerElementos()) {
        if (usuario.getUsername() == user && usuario.getPassword() == contra) {
            return true;
        }
    }
    return false;
}

void menuUsuario() {
    while (true) {
        cout << "1. Mostrar alineacion" << endl;
        cout << "2. Mostrar todos los equipos" << endl;
        cout << "3. Simular jornada" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        int opcion = getOpcion(3);

        switch (opcion) {
        case 1:
            cout << "Mostrando alineacion..." << endl;
            break;
        case 2:
            cout << "Mostrando todos los equipos..." << endl;
            break;
        case 3:
            cout << "Simulando jornada..." << endl;
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        }
    }
}

void iniciarSesion(const Contenedor<Usuario>& contenedor) {
    cout << "==== Sistema de Inicio de Sesion ====" << endl;
    while (true) {
        string usuario, contra;
        cout << "Usuario: ";
        cin >> usuario;
        cout << "Contrasena: ";
        cin >> contra;

        if (validarCredenciales(usuario, contra, contenedor)) {
            cout << "Inicio de sesion exitoso. Bienvenido, " + usuario + "!" << endl << endl;
            break;
        }

        cout << "Contrasena incorrecta. Prueba otra vez." << endl;
    }
    menuUsuario();
}

void menu(const Contenedor<Usuario>& contenedor) {
    iniciarSesion(contenedor);
}

int main() {
    Contenedor<Usuario> contenedor;
    contenedor.agregar(Usuario("Emilio", "emicantarero", "emi123", 0));
    contenedor.agregar(Usuario("Belen", "belenPosso", "be123", 0));
    contenedor.agregar(Usuario("Martin", "martinNelbren", "mn123", 0));
    contenedor.agregar(Usuario("Akeem", "akeemleong", "ak123", 0));

    menu(contenedor);
    return 0;
}
