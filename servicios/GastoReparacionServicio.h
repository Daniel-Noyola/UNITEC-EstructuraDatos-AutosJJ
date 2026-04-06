#ifndef GASTOREPARACIONSERVICIO_H
#define GASTOREPARACIONSERVICIO_H
#include "../utilidades/EditorCSV.h"
#include "../modelos/GastoReparacion.h"
#include <list>

struct GastoReparacionServicio
{
    EditorCSV editorCSV;
    static int ultimoId;

    GastoReparacionServicio();

    /*Obtiene todos los gastos registrados*/
    list<GastoReparacion> obtenerGastos();

    /*Obtiene los gastos de un vehiculo especifico*/
    list<GastoReparacion> obtenerGastosPorVehiculo(int vehiculoId);

    /*Agrega un nuevo gasto de reparacion*/
    GastoReparacion agregarGasto(GastoReparacion gasto);

    /*Calcula el total de gastos de forma RECURSIVA sobre la lista*/
    static double calcularTotalGastos(list<GastoReparacion>::const_iterator it,
                                      list<GastoReparacion>::const_iterator fin);
};

#endif // GASTOREPARACIONSERVICIO_H
