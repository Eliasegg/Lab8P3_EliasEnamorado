#pragma once
#include <iostream>
#include <string>
using namespace std;

class Usuario {
private:
    string nombre;
    string username;
    string password;
    int puntaje;

public:
    Usuario() : nombre(""), username(""), password(""), puntaje(0) {}
    Usuario(string nombre, string username, string password, int puntaje)
        : nombre(nombre), username(username), password(password), puntaje(puntaje) {}
    ~Usuario() {}

    string getUsername() const { return username; }
    string getPassword() const { return password; }
};
