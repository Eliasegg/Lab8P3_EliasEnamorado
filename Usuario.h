#include <vector>
#include <string>
#include "Jugador.h"

class Usuario {
private:
    string nombre;
    string username;
    string password;
    int puntaje;
    vector<Jugador*> alineacion;

public:
    Usuario(const string& nombre, const string& username, const string& password, int puntaje = 0);
    ~Usuario();

    string getUsername() const;
    string getPassword() const;

    void setAlineacion(vector<Jugador*> vector);
    vector<Jugador*> obtenerJugadores();
    void mostrarAlineacion() const;
};
