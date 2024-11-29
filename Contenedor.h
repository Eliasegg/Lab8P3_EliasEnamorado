#pragma once
#include <vector>
using namespace std;

template <typename T>
class Contenedor {
private:
    vector<T> elementos;

public:
    void agregar(const T& elemento);
	const vector<T>& obtenerElementos() const;
};
