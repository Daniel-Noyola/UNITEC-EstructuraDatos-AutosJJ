#include "VentaServicio.h"
#include <sstream>
#include <vector>
using namespace std;


int VentaServicio::ultimoId = 0;

VentaServicio::VentaServicio() : editorCSV("data/ventas.csv", "id,vehiculoId,clienteId,precioVenta,precioAdquisicion,totalGastos,utilidad")
{
    editorCSV.crearArchivo();
    for(const Venta& venta: obtenerVentas())
    {
        if(venta.id > ultimoId)
            ultimoId = venta.id;
    }
}

list<Venta> VentaServicio::obtenerVentas()
{
    vector<string> filas = editorCSV.leerArchivo();
    list<Venta> ventas;

    for(const string& fila: filas)
    {
        Venta venta;
        string campo;
        stringstream ss(fila);
        int indice = 0;

        while(getline(ss, campo, ','))
        {
            switch(indice)
            {
                case 0: venta.id               = stoi(campo); break;
                case 1: venta.vehiculoId        = stoi(campo); break;
                case 2: venta.clienteId         = stoi(campo); break;
                case 3: venta.precioVenta       = stod(campo); break;
                case 4: venta.precioAdquisicion = stod(campo); break;
                case 5: venta.totalGastos       = stod(campo); break;
                case 6: venta.utilidad          = stod(campo); break;
            }
            indice++;
        }
        ventas.push_back(venta);
    }
    return ventas;
}

Venta VentaServicio::registrarVenta(Venta venta)
{
    if(venta.vehiculoId <= 0)
        throw invalid_argument("El ID del vehiculo no es valido.");
    if(venta.clienteId <= 0)
        throw invalid_argument("El ID del cliente no es valido.");
    if(venta.precioVenta <= 0)
        throw invalid_argument("El precio de venta debe ser mayor a 0.");

    // Calcular la utilidad
    venta.utilidad = venta.precioVenta - (venta.precioAdquisicion + venta.totalGastos);
    venta.id = ++ultimoId;

    string filaVenta =
        to_string(venta.id) + "," +
        to_string(venta.vehiculoId) + "," +
        to_string(venta.clienteId) + "," +
        to_string(venta.precioVenta) + "," +
        to_string(venta.precioAdquisicion) + "," +
        to_string(venta.totalGastos) + "," +
        to_string(venta.utilidad);
    editorCSV.guardarEnArchivo(filaVenta);

    return venta;
}

// FUNCION RECURSIVA: recorre la lista de ventas y acumula la ganancia total
double VentaServicio::calcularGananciaTotal(
    list<Venta>::const_iterator it,
    list<Venta>::const_iterator fin)
{
    if(it == fin)
        return 0.0; // Caso base
    return it->utilidad + calcularGananciaTotal(next(it), fin); // Suma recursiva
}
