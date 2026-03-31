#include "VehiculoServicio.h"
#include <sstream>

int VehiculoServicio::ultimoId = 100;

VehiculoServicio::VehiculoServicio() : editorCSV("data/vehiculos.csv", "id,anio,descripcion,marca,modelo,color,version,kilometraje,estado,aseguradora,precioCliente")
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
        string campo;
        stringstream ss(fila);
        int indice = 0;

        while(getline(ss, campo, ','))
        {
            switch(indice)
            {
                case 0: vehiculo.id = stoi(campo); break;
                case 1: vehiculo.anio = stoi(campo); break;
                case 2: vehiculo.descripcion = campo; break;
                case 3: vehiculo.marca = campo; break;
                case 4: vehiculo.modelo = campo; break;
                case 5: vehiculo.color = campo; break;
                case 6: vehiculo.version = campo; break;
                case 7: vehiculo.kilometraje = campo; break;
                case 8: vehiculo.estado = campo; break;
                case 9: vehiculo.aseguradora = campo; break;
                case 10: vehiculo.precioCliente = stof(campo); break;
            }
            indice++;
        }
        vehiculos.push_back(vehiculo);
    }
    ordenarVehiculos(vehiculos);
    return vehiculos;
}

Vehiculo VehiculoServicio::agregarVehiculo(int anio, const string& descripcion, const string& marca, const string& modelo, const string& color, const string& version, const string& kilometraje, const string& estado, const string& aseguradora, const string& precioCliente)
{
    Vehiculo nuevoVehiculo;
    nuevoVehiculo.id = ++ultimoId;
    nuevoVehiculo.anio = anio;
    nuevoVehiculo.descripcion = descripcion;
    nuevoVehiculo.marca = marca;
    nuevoVehiculo.modelo = modelo;
    nuevoVehiculo.color = color;
    nuevoVehiculo.version = version;
    nuevoVehiculo.kilometraje = kilometraje;
    nuevoVehiculo.estado = estado;
    nuevoVehiculo.aseguradora = aseguradora;
    nuevoVehiculo.precioCliente = stof(precioCliente);

    string filaVehiculo = 
        to_string(nuevoVehiculo.id) + "," +
        to_string(nuevoVehiculo.anio) + "," +
        nuevoVehiculo.descripcion + "," +
        nuevoVehiculo.marca + "," +
        nuevoVehiculo.modelo + "," +
        nuevoVehiculo.color + "," +
        nuevoVehiculo.version + "," +
        nuevoVehiculo.kilometraje + "," +
        nuevoVehiculo.estado + "," +
        nuevoVehiculo.aseguradora + "," +
        to_string(nuevoVehiculo.precioCliente);
    editorCSV.guardarEnArchivo(filaVehiculo);

    return nuevoVehiculo;
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
