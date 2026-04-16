#ifndef COSTOSVEHICULO_H
#define COSTOSVEHICULO_H

#include <string>
using namespace std;

/*Estructura que representa los costos de un vehículo*/
struct CostosVehiculo
{
    int id;
    int vehiculoId;
    int clienteId;
    int grua,
        refacciones,
        hojalateria,
        pintura,
        manoDeObra,
        otros,
        total;
};
#endif // COSTOSVEHICULO_H