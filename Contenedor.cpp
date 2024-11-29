#include "Contenedor.h"
#include "Usuario.h"

template <typename T>
void Contenedor<T>::agregar(const T& elemento) {
    elementos.push_back(elemento);
}

template <typename T>
const vector<T>& Contenedor<T>::obtenerElementos() const {
    return elementos;
}

template class Contenedor<Usuario>;