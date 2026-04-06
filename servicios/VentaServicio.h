#ifndef VENTASERVICIO_H
#define VENTASERVICIO_H
#include "../utilidades/EditorCSV.h"
#include "../modelos/Venta.h"
#include <list>

struct VentaServicio
{
    EditorCSV editorCSV;
    static int ultimoId;

    VentaServicio();

    /*Obtiene la lista de ventas registradas*/
    list<Venta> obtenerVentas();

    /*Registra una nueva venta*/
    Venta registrarVenta(Venta venta);

    /*Calcula la ganancia total RECURSIVAMENTE sobre la lista de ventas*/
    static double calcularGananciaTotal(list<Venta>::const_iterator it,
                                        list<Venta>::const_iterator fin);
};

#endif // VENTASERVICIO_H
