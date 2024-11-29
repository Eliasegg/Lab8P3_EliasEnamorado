#include "Jugador.h"
#include <iostream>

Jugador::Jugador(const std::string& nombre, const std::string& equipo, int puntaje)
    : nombre(nombre), equipo(equipo), puntaje(puntaje) {}

Jugador::~Jugador() {}

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
    std::cout << nombre << " está haciendo jugadas como Receptor." << std::endl;
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
    std::cout << nombre << " está haciendo jugadas como Ala Cerrada." << std::endl;
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
    std::cout << nombre << " está haciendo jugadas como Pateador." << std::endl;
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
    std::cout << nombre << " está haciendo jugadas como Corredor." << std::endl;
}

// QB
Quarterback::Quarterback(const std::string& nombre, const std::string& equipo, int puntaje)
    : Jugador(nombre, equipo, puntaje) {}

std::string Quarterback::toString() const {
    return "Nombre: " + nombre + "\nPosicion: " + retornarPosicion() + "\nPuntaje: " + std::to_string(puntaje);
}

std::string Quarterback::retornarPosicion() const {
    return "Quarterback";
}

void Quarterback::hacerJugadas() {
    std::cout << nombre << " está haciendo jugadas como Quarterback." << std::endl;
}
