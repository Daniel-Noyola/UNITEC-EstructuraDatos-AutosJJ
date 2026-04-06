#ifndef VENTA_H
#define VENTA_H

#include <string>
using namespace std;

struct Venta
{
    int id;
    int vehiculoId;
    int clienteId;
    double precioVenta;
    double precioAdquisicion;
    double totalGastos;
    double utilidad; // precioVenta - (precioAdquisicion + totalGastos)
};

#endif // VENTA_H
