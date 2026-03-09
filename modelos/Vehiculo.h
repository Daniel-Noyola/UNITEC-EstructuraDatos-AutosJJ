#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
using namespace std;

struct Vehiculo
{
    int id;
    int anio;
    string descripcion,
        marca,
        modelo,
        color,
        version,
        kilometraje,
        estado,
        aseguradora;
    float precioCliente;
};
#endif // !VEHICULO_H
