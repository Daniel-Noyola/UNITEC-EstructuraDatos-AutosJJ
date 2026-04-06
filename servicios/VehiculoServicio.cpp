#include "VehiculoServicio.h"
#include <sstream>
#include <vector>

int VehiculoServicio::ultimoId = 100;

VehiculoServicio::VehiculoServicio() : editorCSV("data/vehiculos.csv", "id,anio,descripcion,marca,modelo,color,version,kilometraje,estado,aseguradora,precioCliente,precioAdquisicion,reparado")
{
    editorCSV.crearArchivo();
    for(const Vehiculo& vehiculo: obtenerVehiculos())
    {
        if(vehiculo.id > ultimoId)
        {
            ultimoId = vehiculo.id;
        }
    }
}

list<Vehiculo> VehiculoServicio::obtenerVehiculos()
{
    vector<string> filas = editorCSV.leerArchivo();
    list<Vehiculo> vehiculos;

    for(const string& fila: filas)
    {
        Vehiculo vehiculo;
        vehiculo.precioAdquisicion = 0.0;
        vehiculo.reparado = false;
        string campo;
        stringstream ss(fila);
        int indice = 0;

        while(getline(ss, campo, ','))
        {
            switch(indice)
            {
                case 0:  vehiculo.id                = stoi(campo);         break;
                case 1:  vehiculo.anio              = stoi(campo);         break;
                case 2:  vehiculo.descripcion       = campo;               break;
                case 3:  vehiculo.marca             = campo;               break;
                case 4:  vehiculo.modelo            = campo;               break;
                case 5:  vehiculo.color             = campo;               break;
                case 6:  vehiculo.version           = campo;               break;
                case 7:  vehiculo.kilometraje       = campo;               break;
                case 8:  vehiculo.estado            = campo;               break;
                case 9:  vehiculo.aseguradora       = campo;               break;
                case 10: vehiculo.precioCliente     = stof(campo);         break;
                case 11: vehiculo.precioAdquisicion = stod(campo);         break;
                case 12: vehiculo.reparado          = (campo == "1");      break;
            }
            indice++;
        }
        vehiculos.push_back(vehiculo);
    }
    ordenarVehiculos(vehiculos);
    return vehiculos;
}

void VehiculoServicio::validarVehiculo(const Vehiculo& vehiculo)
{
    if(vehiculo.anio < 1886)
        throw invalid_argument("El anio del vehiculo no es valido.");
    if(vehiculo.descripcion.empty())
        throw invalid_argument("La descripcion no puede estar vacia.");
    if(vehiculo.marca.empty())
        throw invalid_argument("La marca no puede estar vacia.");
    if(vehiculo.modelo.empty())
        throw invalid_argument("El modelo no puede estar vacio.");
    if(vehiculo.color.empty())
        throw invalid_argument("El color no puede estar vacio.");
    if(vehiculo.kilometraje.empty())
        throw invalid_argument("El kilometraje no puede estar vacio.");
    if(vehiculo.estado.empty() || (vehiculo.estado != "nuevo" && vehiculo.estado != "usado" && vehiculo.estado != "Nuevo" && vehiculo.estado != "Usado"))
        throw invalid_argument("El estado debe ser 'nuevo' o 'usado'.");
    if(vehiculo.precioCliente <= 0)
        throw invalid_argument("El precio del cliente debe ser mayor a 0.");
    if(vehiculo.precioAdquisicion < 0)
        throw invalid_argument("El precio de adquisicion no puede ser negativo.");
}

Vehiculo VehiculoServicio::agregarVehiculo(Vehiculo vehiculo)
{
    validarVehiculo(vehiculo);

    vehiculo.id = ++ultimoId;
    vehiculo.reparado = false; // Todo vehiculo nuevo entra como no reparado

    string filaVehiculo =
        to_string(vehiculo.id) + "," +
        to_string(vehiculo.anio) + "," +
        vehiculo.descripcion + "," +
        vehiculo.marca + "," +
        vehiculo.modelo + "," +
        vehiculo.color + "," +
        vehiculo.version + "," +
        vehiculo.kilometraje + "," +
        vehiculo.estado + "," +
        vehiculo.aseguradora + "," +
        to_string(vehiculo.precioCliente) + "," +
        to_string(vehiculo.precioAdquisicion) + "," +
        (vehiculo.reparado ? "1" : "0");
    editorCSV.guardarEnArchivo(filaVehiculo);

    return vehiculo;
}

Vehiculo VehiculoServicio::obtenerVehiculoPorId(int id)
{
    list<Vehiculo> vehiculos = obtenerVehiculos();
    for(const Vehiculo& vehiculo: vehiculos)
    {
        if(vehiculo.id == id)
            return vehiculo;
    }
    throw invalid_argument("No se encontro un vehiculo con el ID especificado.");
}

list<Vehiculo> VehiculoServicio::obtenerVehiculosPorMarca(const string& marca)
{
    list<Vehiculo> vehiculos = obtenerVehiculos();
    list<Vehiculo> vehiculosPorMarca;
    for(const Vehiculo& vehiculo: vehiculos)
    {
        if(vehiculo.marca == marca)
            vehiculosPorMarca.push_back(vehiculo);
    }
    ordenarVehiculos(vehiculosPorMarca);
    return vehiculosPorMarca;
}

list<Vehiculo> VehiculoServicio::obtenerVehiculosDisponibles()
{
    list<Vehiculo> vehiculos = obtenerVehiculos();
    list<Vehiculo> disponibles;
    for(const Vehiculo& vehiculo: vehiculos)
    {
        if(vehiculo.reparado)
            disponibles.push_back(vehiculo);
    }
    return disponibles;
}

Vehiculo VehiculoServicio::marcarComoReparado(int id)
{
    list<Vehiculo> vehiculos = obtenerVehiculos();
    bool encontrado = false;
    Vehiculo vehiculoActualizado;

    for(Vehiculo& vehiculo: vehiculos)
    {
        if(vehiculo.id == id)
        {
            vehiculo.reparado = true;
            vehiculoActualizado = vehiculo;
            encontrado = true;
            break;
        }
    }

    if(!encontrado)
        throw invalid_argument("No se encontro un vehiculo con el ID especificado.");

    vector<string> filasActualizadas;
    for(const Vehiculo& vehiculo: vehiculos)
    {
        string fila =
            to_string(vehiculo.id) + "," +
            to_string(vehiculo.anio) + "," +
            vehiculo.descripcion + "," +
            vehiculo.marca + "," +
            vehiculo.modelo + "," +
            vehiculo.color + "," +
            vehiculo.version + "," +
            vehiculo.kilometraje + "," +
            vehiculo.estado + "," +
            vehiculo.aseguradora + "," +
            to_string(vehiculo.precioCliente) + "," +
            to_string(vehiculo.precioAdquisicion) + "," +
            (vehiculo.reparado ? "1" : "0");
        filasActualizadas.push_back(fila);
    }
    editorCSV.reescribirArchivo(filasActualizadas);

    return vehiculoActualizado;
}

void VehiculoServicio::ordenarVehiculos(list<Vehiculo>& vehiculos)
{
    bool intercambio;
    do
    {
        intercambio = false;
        auto it = vehiculos.begin();
        auto siguiente = next(it);
        while (siguiente != vehiculos.end())
        {
            if (it->id > siguiente->id)
            {
                swap(*it, *siguiente);
                intercambio = true;
            }
            ++it;
            ++siguiente;
        }
    } while (intercambio);
}

void VehiculoServicio::ordenarVehiculosPorPrecio(list<Vehiculo>& vehiculos)
{
    // Bubble Sort por precio de adquisicion (de menor a mayor)
    bool intercambio;
    do
    {
        intercambio = false;
        auto it = vehiculos.begin();
        auto siguiente = next(it);
        while (siguiente != vehiculos.end())
        {
            if (it->precioAdquisicion > siguiente->precioAdquisicion)
            {
                swap(*it, *siguiente);
                intercambio = true;
            }
            ++it;
            ++siguiente;
        }
    } while (intercambio);
}
