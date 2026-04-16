#ifndef GASTOREPARACION_H
#define GASTOREPARACION_H

#include <string>
using namespace std;

/*Estructura que representa un gasto de reparación*/
struct GastoReparacion
{
    int id;
    int vehiculoId;
    string descripcion;
    double monto;
};

#endif // GASTOREPARACION_H
