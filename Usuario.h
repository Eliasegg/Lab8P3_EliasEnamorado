#pragma once
#include <string>
#include <vector>
#include "Jugador.h"
using namespace std;

class Usuario {
    string nombre;
    string username;
    string password;
    vector<Jugador*> alineacion;
	vector<string> extraEquipos = { "New York Jets", "Miami Dolphins", "Cincinnati Bengals", "Cleveland Browns", "Pittsburgh Steelers", "Los Angeles Chargers", "Tennessee Titans", "Dallas Cowboys", "Washington Commanders", "Chicago Bears", "Los Angeles Rams", "Seattle Seahawks", "Carolina Panthers", "New Orlean Saints", "Tampa BayBuccanneers", "New York Giants" };

public:
    Usuario(const string& nombre, const string& username, const string& password);
    ~Usuario();

    string getUsername() const;
    string getPassword() const;
    void setAlineacion(const vector<Jugador*>& jugadores);
    void mostrarAlineacion() const;
    vector<Jugador*> obtenerJugadores() const;
    string getEquipoRandom();
    int calcularPuntaje() const; 
    void resetPuntaje(); 
	void simularPartidos(const vector<Usuario*>& usuarios);
};
