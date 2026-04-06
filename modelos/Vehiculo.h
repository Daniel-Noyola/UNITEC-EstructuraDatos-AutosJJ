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
    double precioAdquisicion; // Precio al que se compró el vehículo siniestrado
    bool reparado;            // true si ya está listo para la venta
};
#endif // !VEHICULO_H
