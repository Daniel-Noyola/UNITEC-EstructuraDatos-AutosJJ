#include "GastoReparacionServicio.h"
#include <sstream>
#include <vector>

int GastoReparacionServicio::ultimoId = 0;

GastoReparacionServicio::GastoReparacionServicio() : editorCSV("data/gastos.csv", "id,vehiculoId,descripcion,monto")
{
    editorCSV.crearArchivo();
    for(const GastoReparacion& gasto: obtenerGastos())
    {
        if(gasto.id > ultimoId)
            ultimoId = gasto.id;
    }
}

list<GastoReparacion> GastoReparacionServicio::obtenerGastos()
{
    vector<string> filas = editorCSV.leerArchivo();
    list<GastoReparacion> gastos;

    for(const string& fila: filas)
    {
        GastoReparacion gasto;
        string campo;
        stringstream ss(fila);
        int indice = 0;

        while(getline(ss, campo, ','))
        {
            switch(indice)
            {
                case 0: gasto.id          = stoi(campo); break;
                case 1: gasto.vehiculoId  = stoi(campo); break;
                case 2: gasto.descripcion = campo;       break;
                case 3: gasto.monto       = stod(campo); break;
            }
            indice++;
        }
        gastos.push_back(gasto);
    }
    return gastos;
}

list<GastoReparacion> GastoReparacionServicio::obtenerGastosPorVehiculo(int vehiculoId)
{
    list<GastoReparacion> todos = obtenerGastos();
    list<GastoReparacion> resultado;
    for(const GastoReparacion& gasto: todos)
    {
        if(gasto.vehiculoId == vehiculoId)
            resultado.push_back(gasto);
    }
    return resultado;
}

GastoReparacion GastoReparacionServicio::agregarGasto(GastoReparacion gasto)
{
    if(gasto.descripcion.empty())
        throw invalid_argument("La descripcion del gasto no puede estar vacia.");
    if(gasto.monto <= 0)
        throw invalid_argument("El monto del gasto debe ser mayor a 0.");
    if(gasto.vehiculoId <= 0)
        throw invalid_argument("El ID del vehiculo no es valido.");

    gasto.id = ++ultimoId;

    string filaGasto =
        to_string(gasto.id) + "," +
        to_string(gasto.vehiculoId) + "," +
        gasto.descripcion + "," +
        to_string(gasto.monto);
    editorCSV.guardarEnArchivo(filaGasto);

    return gasto;
}

// FUNCION RECURSIVA: recorre la lista de gastos y acumula el total
double GastoReparacionServicio::calcularTotalGastos(
    list<GastoReparacion>::const_iterator it,
    list<GastoReparacion>::const_iterator fin)
{
    if(it == fin)
        return 0.0; // Caso base: lista vacía o fin alcanzado
    return it->monto + calcularTotalGastos(next(it), fin); // Suma recursiva
}
