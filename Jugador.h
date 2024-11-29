#pragma once
#include <string>
using namespace std;

class Jugador {
protected:
    std::string nombre;
    std::string equipo;
    int puntaje = 0;

public:
    Jugador(const std::string& nombre, const std::string& equipo, int puntaje = 0);
    virtual ~Jugador();

    virtual std::string toString() const = 0;
    virtual std::string retornarPosicion() const = 0;
    virtual void hacerJugadas() = 0;
};

// Receptor
class Receptor : public Jugador {
public:
    Receptor(const std::string& nombre, const std::string& equipo, int puntaje = 0);
    std::string toString() const override;
    std::string retornarPosicion() const override;
    void hacerJugadas() override;
};

// AlaCerrada
class AlaCerrada : public Jugador {
public:
    AlaCerrada(const std::string& nombre, const std::string& equipo, int puntaje = 0);
    std::string toString() const override;
    std::string retornarPosicion() const override;
    void hacerJugadas() override;
};

// Pateador
class Pateador : public Jugador {
public:
    Pateador(const std::string& nombre, const std::string& equipo, int puntaje = 0);
    std::string toString() const override;
    std::string retornarPosicion() const override;
    void hacerJugadas() override;
};

// Corredor
class Corredor : public Jugador {
public:
    Corredor(const std::string& nombre, const std::string& equipo, int puntaje = 0);
    std::string toString() const override;
    std::string retornarPosicion() const override;
    void hacerJugadas() override;
};

// QB
class Quarterback : public Jugador {
public:
    Quarterback(const std::string& nombre, const std::string& equipo, int puntaje = 0);
    std::string toString() const override;
    std::string retornarPosicion() const override;
    void hacerJugadas() override;
};