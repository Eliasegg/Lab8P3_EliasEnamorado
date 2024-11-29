#include "Usuario.h"
#include <iostream>

Usuario::Usuario(const std::string& nombre, const std::string& username, const std::string& password, int puntaje)
    : nombre(nombre), username(username), password(password), puntaje(puntaje) {}

Usuario::~Usuario() {
    for (auto jugador : alineacion) {
        delete jugador;
    }
}

void Usuario::setAlineacion(vector<Jugador*> vector) {
    this->alineacion = vector;
}

vector<Jugador*> Usuario::obtenerJugadores() {
    return this->alineacion;
}

string Usuario::getUsername() const {
    return username;
}

string Usuario::getPassword() const {
    return password;
}

void Usuario::mostrarAlineacion() const {
    for (auto jugador : this->alineacion) {
        cout << jugador->toString() << endl;
    }
}
