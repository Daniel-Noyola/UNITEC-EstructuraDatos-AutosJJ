#ifndef COSTOSVEHICULO_H
#define COSTOSVEHICULO_H

#include <string>
using namespace std;

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