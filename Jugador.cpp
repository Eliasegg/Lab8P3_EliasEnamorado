#include "Jugador.h"
#include <iostream>

Jugador::Jugador(const std::string& nombre, const std::string& equipo, int puntaje)
    : nombre(nombre), equipo(equipo), puntaje(puntaje) {}

Jugador::~Jugador() {}

std::string Jugador::getEquipo() const {
    return equipo;
}

// Receptor
Receptor::Receptor(const std::string& nombre, const std::string& equipo, int puntaje)
    : Jugador(nombre, equipo, puntaje) {}

std::string Receptor::toString() const {
    return "Nombre: " + nombre + "\nPosicion: " + retornarPosicion() + "\nPuntaje: " + std::to_string(puntaje);
}

std::string Receptor::retornarPosicion() const {
    return "Receptor";
}

void Receptor::hacerJugadas() {
    int jugada = rand() % 4;
    switch (jugada) {
    case 0:
        puntaje += 2; // Pase corto
        std::cout << this->nombre << " recibe un pase corto para un total de 6 yardas." << std::endl;
        break;
    case 1:
        puntaje += 5; // Pase medio
        std::cout << this->nombre << " recibe un pase medio para un total de 12 yardas." << std::endl;
        break;
    case 2:
        puntaje += 10; // Pase largo
        std::cout << this->nombre << " recibe un pase largo para un total de 20 yardas." << std::endl;
        break;
    case 3:
        puntaje -= 5; // Fumble
        std::cout << this->nombre << " hizo un fumble." << std::endl;
        break;
    }
}

// AlaCerrada
AlaCerrada::AlaCerrada(const std::string& nombre, const std::string& equipo, int puntaje)
    : Jugador(nombre, equipo, puntaje) {}

std::string AlaCerrada::toString() const {
    return "Nombre: " + nombre + "\nPosicion: " + retornarPosicion() + "\nPuntaje: " + std::to_string(puntaje);
}

std::string AlaCerrada::retornarPosicion() const {
    return "Ala Cerrada";
}

void AlaCerrada::hacerJugadas() {
    int jugada = rand() % 4;
    switch (jugada) {
    case 0:
        puntaje += 2; // Pase corto
        std::cout << this->nombre << " lanza un pase corto para un total de 6 yardas." << std::endl;
        break;
    case 1:
        puntaje += 5; // Pase medio
        std::cout << this->nombre << " lanza un pase medio para un total de 12 yardas." << std::endl;
        break;
    case 2:
        puntaje += 10; // Pase largo
        std::cout << this->nombre << " lanza un pase largo para un total de 20 yardas." << std::endl;
        break;
    case 3:
        puntaje -= 5; // Fumble
        std::cout << this->nombre << " hizo un fumble." << std::endl;
        break;
    }
}

// Pateador
Pateador::Pateador(const std::string& nombre, const std::string& equipo, int puntaje)
    : Jugador(nombre, equipo, puntaje) {}

std::string Pateador::toString() const {
    return "Nombre: " + nombre + "\nPosicion: " + retornarPosicion() + "\nPuntaje: " + std::to_string(puntaje);
}

std::string Pateador::retornarPosicion() const {
    return "Pateador";
}

void Pateador::hacerJugadas() {
    int jugada = rand() % 3;
    switch (jugada) {
    case 0:
        puntaje += 6; // Gol de campo
        std::cout << this->nombre << " anota un gol de campo." << std::endl;
        break;
    case 1:
        puntaje += 6; // Punto extra
        std::cout << this->nombre << " anota un punto extra." << std::endl;
        break;
    case 2:
        puntaje -= 3; // Gol de campo fallado
        std::cout << this->nombre << " falla un gol de campo." << std::endl;
        break;
    }
}

// Corredor
Corredor::Corredor(const std::string& nombre, const std::string& equipo, int puntaje)
    : Jugador(nombre, equipo, puntaje) {}

std::string Corredor::toString() const {
    return "Nombre: " + nombre + "\nPosicion: " + retornarPosicion() + "\nPuntaje: " + std::to_string(puntaje);
}

std::string Corredor::retornarPosicion() const {
    return "Corredor";
}

void Corredor::hacerJugadas() {
    int jugada = rand() % 4;
    switch (jugada) {
    case 0:
        puntaje += 3; // Acarreo de 0-25 yardas
        std::cout << this->nombre << " corre para un total de 10 yardas." << std::endl;
        break;
    case 1:
        puntaje += 6; // Acarreo de 26-70 yardas
        std::cout << this->nombre << " corre para un total de 40 yardas." << std::endl;
        break;
    case 2:
        puntaje += 9; // Acarreo de 71-100 yardas
        std::cout << this->nombre << " corre para un total de 80 yardas." << std::endl;
        break;
    case 3:
        puntaje -= 3; // Fumble
        std::cout << this->nombre << " hizo un fumble." << std::endl;
        break;
    }
}

// Quarterback
Quarterback::Quarterback(const std::string& nombre, const std::string& equipo, int puntaje)
    : Jugador(nombre, equipo, puntaje) {}

std::string Quarterback::toString() const {
    return "Nombre: " + nombre + "\nPosicion: " + retornarPosicion() + "\nPuntaje: " + std::to_string(puntaje);
}

std::string Quarterback::retornarPosicion() const {
    return "Quarterback";
}

void Quarterback::hacerJugadas() {
    int jugada = rand() % 4;
    switch (jugada) {
    case 0:
        puntaje += 2; // Pase corto
        std::cout << this->nombre << " lanza un pase corto para un total de 6 yardas." << std::endl;
        break;
    case 1:
        puntaje += 5; // Pase medio
        std::cout << this->nombre << " lanza un pase medio para un total de 12 yardas." << std::endl;
        break;
    case 2:
        puntaje += 10; // Pase largo
        std::cout << this->nombre << " lanza un pase largo para un total de 20 yardas." << std::endl;
        break;
    case 3:
        puntaje -= 10; // Intercepción
        std::cout << this->nombre << " le hacen una intervencion." << std::endl;
        break;
    }
}
