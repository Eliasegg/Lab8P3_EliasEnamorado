#include <iostream>
#include <vector>
#include "Usuario.h"

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

template <typename Container>
bool validarCredenciales(string user, string contra, const Container& usuarios) {
    for (const auto& usuario : usuarios) {
        if (usuario->getUsername() == user && usuario->getPassword() == contra) {
            return true;
        }
    }
    return false;
}

void mostrarTodosLosEquipos(const vector<Usuario*>& usuarios) {
    cout << "---Equipos de la liga Fantasy---" << endl;
    for (const auto& usuario : usuarios) {
		cout << "---Alineacion del usuario " << usuario->getUsername() << "---" << endl;
        cout << "Usuario: " << usuario->getUsername() << endl;
        usuario->mostrarAlineacion();
        cout << endl;
    }
}

void menuUsuario(Usuario* usuario, const vector<Usuario*>& usuarios) {
    while (true) {
        cout << "1. Mostrar alineacion" << endl;
        cout << "2. Mostrar todos los equipos" << endl;
        cout << "3. Simular jornada" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        int opcion = getOpcion(3);

        switch (opcion) {
        case 1:
            usuario->mostrarAlineacion();
            cout << endl;
            break;
        case 2:
            mostrarTodosLosEquipos(usuarios);
            break;
        case 3:
            cout << "Simulando jornada..." << endl;
            break;
        case 0:
            cout << "Saliendo..." << endl;
            return;
        }
    }
}

void iniciarSesion(vector<Usuario*> usuarios) {
    cout << "==== Sistema de Inicio de Sesion ====" << endl;
    while (true) {
        string usuario, contra;
        cout << "Usuario: ";
        cin >> usuario;
        cout << "Contrasena: ";
        cin >> contra;

        if (validarCredenciales(usuario, contra, usuarios)) {
            cout << "Inicio de sesion exitoso. Bienvenido, " + usuario + "!" << endl << endl;
            for (auto user : usuarios) {
                if (user->getUsername() == usuario) {
                    menuUsuario(user, usuarios);
                    return;
                }
            }
        }
        else {
            cout << "Contrasena incorrecta. Prueba otra vez." << endl;
        }
    }
}

void menu(vector<Usuario*> usuarios) {
    iniciarSesion(usuarios);
}

int main() {
    vector<Usuario*> usuarios;
    vector<Jugador*> jugadores1, jugadores2, jugadores3, jugadores4;

    Usuario* emilio = new Usuario("Emilio", "emicantarero", "emi123");
    jugadores1.push_back(new Quarterback("Patrick Mahomes", "Kansas City Chiefs"));
    jugadores1.push_back(new Receptor("Justin Jefferson", "Minnesota Vikings"));
    jugadores1.push_back(new Corredor("Christian McCaffrey", "San Francisco 49ers"));
    jugadores1.push_back(new AlaCerrada("Travis Kelce", "Kansas City Chiefs"));
    jugadores1.push_back(new Pateador("Matt Pratter", "Arizona Cardinals"));
    emilio->setAlineacion(jugadores1);
    usuarios.push_back(emilio);

    Usuario* belen = new Usuario("Belen", "belenPosso", "be123");
    jugadores2.push_back(new Quarterback("Josh Allen", "Buffalo Bills"));
    jugadores2.push_back(new Receptor("Amari Cooper", "Buffalo Bills"));
    jugadores2.push_back(new Corredor("Derrick Henry", "Baltimore Ravens"));
    jugadores2.push_back(new AlaCerrada("TJ Hockenson", "Detroit Lions"));
    jugadores2.push_back(new Pateador("Joey Slye", "NE Patriots"));
    belen->setAlineacion(jugadores2);
    usuarios.push_back(belen);

    Usuario* martin = new Usuario("Martin", "martinNelbren", "mn123");
    jugadores3.push_back(new Quarterback("Mac Jones", "Jacksonville Jaguars"));
    jugadores3.push_back(new Corredor("Saquon Barkley", "Philadelphia Eagles"));
    jugadores3.push_back(new AlaCerrada("Dalton Schultz", "Houston Texans"));
    jugadores3.push_back(new Pateador("Younghoe Koo", "Atlanta Falcons"));
    martin->setAlineacion(jugadores3);
    usuarios.push_back(martin);

    Usuario* akeem = new Usuario("Akeem", "akeemleong", "ak123");
    jugadores4.push_back(new Quarterback("Gardner Minshew", "Las Vegas Raiders"));
    jugadores4.push_back(new Receptor("Jakobi Meyers", "Las Vegas Raiders"));
    jugadores4.push_back(new Corredor("Aaron Jones", "Green Bay Packers"));
    jugadores4.push_back(new AlaCerrada("Adam Trautman", "Denver Broncos"));
    jugadores4.push_back(new Pateador("Matt Gay", "Indianapolis Colts"));
    akeem->setAlineacion(jugadores4);
    usuarios.push_back(akeem);

    menu(usuarios);
    return 0;
}
