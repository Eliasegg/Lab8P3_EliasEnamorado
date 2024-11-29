#include "Usuario.h"
#include <iostream>

Usuario::Usuario(const string& nombre, const string& username, const string& password)
    : nombre(nombre), username(username), password(password) {}

Usuario::~Usuario() {
    for (auto jugador : alineacion) {
        delete jugador;
    }
}

string Usuario::getUsername() const {
    return username;
}

string Usuario::getPassword() const {
    return password;
}

void Usuario::setAlineacion(const vector<Jugador*>& jugadores) {
    alineacion = jugadores;
}

void Usuario::mostrarAlineacion() const {
    for (const auto& jugador : alineacion) {
        cout << jugador->toString() << endl;
    }
}

vector<Jugador*> Usuario::obtenerJugadores() const {
    return alineacion;
}

string Usuario::getEquipoRandom() {
	return extraEquipos[rand() % extraEquipos.size()];
}

int Usuario::calcularPuntaje() const {
    int puntajeTotal = 0;
    for (const auto& jugador : alineacion) {
        puntajeTotal += jugador->getPuntaje();
    }
    return puntajeTotal;
}

void Usuario::resetPuntaje() {
    for (auto& jugador : alineacion) {
        jugador->resetPuntaje();
    }
}

void Usuario::simularPartidos(const vector<Usuario*>& usuarios) {
    srand(time(0)); // Inicializa la semilla para números 

    // Selecciona un oponente aleatorio
    Usuario* oponente = nullptr;
    do {
        oponente = usuarios[rand() % usuarios.size()];
    } while (oponente == this);

    // Resetea el puntaje de los jugadores antes de la simulación
    this->resetPuntaje();
    oponente->resetPuntaje();

    cout << "--Encuentro principal de la jornada---" << endl;
    cout << endl;
	cout << this->username << " vs. " << oponente->getUsername() << endl;
    int i = 0;
	while (i < 3) {

        string equipo1 = this->obtenerJugadores()[rand() % this->obtenerJugadores().size()]->getEquipo();
        string equipo2;
        do {
            equipo2 = getEquipoRandom();
        } while (equipo1 == equipo2);

        // Simula las jugadas de cada jugador en ambos equipos
		cout << "---" << equipo1 << " vs. " << equipo2 << "---" << endl;
        for (int i = 0; i < 4; ++i) {
            for (auto jugador : this->obtenerJugadores()) {
				if (jugador->getEquipo() == equipo1) {
					jugador->hacerJugadas();
				}
            }
            for (auto jugador : oponente->obtenerJugadores()) {
                if (jugador->getEquipo() == equipo2) {
                    jugador->hacerJugadas();
                }
            }
        }
        i++;
    }

    // Calcula el puntaje total de cada equipo
    int puntajeUsuario = this->calcularPuntaje();
    int puntajeOponente = oponente->calcularPuntaje();

    // Muestra el resumen de las jugadas y el puntaje final
    cout << "---Resumen de la jornada---" << endl;
    cout << "Usuario: " << this->getUsername() << endl;
    cout << "Puntaje de la jornada: " << puntajeUsuario << endl;
    cout << endl;

    
	for (auto jugador : this->obtenerJugadores()) {
        cout << jugador->toString() << endl << endl << endl;
	}

    // Determina el ganador
    if (puntajeUsuario > puntajeOponente) {
        cout << "El ganador del partido principal fue: " << this->getUsername() << " con " << puntajeUsuario << " puntos " << endl;
    }
    else if (puntajeUsuario < puntajeOponente) {
        cout << "El ganador del partido principal fue: " << this->getUsername() << " con " << puntajeOponente << " puntos " << endl;
    }
    else {
        cout << "No hubo ganador. Hubo empate con " << puntajeUsuario << " puntos! " << endl;
    }
}