#include "ProveedorServicio.h"
#include <sstream>
#include <vector>
#include <list>
#include <iterator>
#include <utility>

int ProveedorServicio::ultimoId = 2000;

ProveedorServicio::ProveedorServicio() : editorCSV("data/proveedores.csv", "id,nombre,contacto,direccion,telefono")
{
    editorCSV.crearArchivo();
    for(const Proveedor& proveedor: obtenerProveedores())
    {
        if(proveedor.id > ultimoId)
            ultimoId = proveedor.id;
    }
}

list<Proveedor> ProveedorServicio::obtenerProveedores()
{
    vector<string> filas = editorCSV.leerArchivo();
    list<Proveedor> proveedores;

    for(const string& fila: filas)
    {
        Proveedor proveedor;
        string campo;
        stringstream ss(fila);
        int indice = 0;

        while(getline(ss, campo, ','))
        {
            switch(indice)
            {
                case 0: proveedor.id        = stoi(campo); break;
                case 1: proveedor.nombre    = campo;       break;
                case 2: proveedor.contacto  = campo;       break;
                case 3: proveedor.direccion = campo;       break;
                case 4: proveedor.telefono  = campo;       break;
            }
            indice++;
        }
        proveedores.push_back(proveedor);
    }
    ordenarProveedores(proveedores);
    return proveedores;
}

void ProveedorServicio::validarProveedor(const Proveedor& proveedor)
{
    if(proveedor.nombre.empty())
        throw invalid_argument("El nombre del proveedor no puede estar vacio.");
    if(proveedor.contacto.empty())
        throw invalid_argument("El contacto no puede estar vacio.");
    if(proveedor.direccion.empty())
        throw invalid_argument("La direccion no puede estar vacia.");
    if(proveedor.telefono.empty())
        throw invalid_argument("El telefono no puede estar vacio.");
}

Proveedor ProveedorServicio::agregarProveedor(Proveedor proveedor)
{
    validarProveedor(proveedor);
    proveedor.id = ++ultimoId;

    string filaProveedor =
        to_string(proveedor.id) + "," +
        proveedor.nombre + "," +
        proveedor.contacto + "," +
        proveedor.direccion + "," +
        proveedor.telefono;
    editorCSV.guardarEnArchivo(filaProveedor);

    return proveedor;
}

Proveedor ProveedorServicio::obtenerProveedorPorId(int id)
{
    list<Proveedor> proveedores = obtenerProveedores();
    for(const Proveedor& proveedor: proveedores)
    {
        if(proveedor.id == id)
            return proveedor;
    }
    throw invalid_argument("No se encontro un proveedor con el ID especificado.");
}

Proveedor ProveedorServicio::eliminarProveedor(int id)
{
    list<Proveedor> proveedores = obtenerProveedores();
    Proveedor proveedorEliminado;
    bool encontrado = false;

    for(const Proveedor& proveedor: proveedores)
    {
        if(proveedor.id == id)
        {
            proveedorEliminado = proveedor;
            encontrado = true;
            break;
        }
    }

    if(!encontrado)
        throw invalid_argument("No se encontro un proveedor con el ID especificado.");

    vector<string> filasActualizadas;
    for(const Proveedor& proveedor: proveedores)
    {
        if(proveedor.id != id)
        {
            string fila =
                to_string(proveedor.id) + "," +
                proveedor.nombre + "," +
                proveedor.contacto + "," +
                proveedor.direccion + "," +
                proveedor.telefono;
            filasActualizadas.push_back(fila);
        }
    }
    editorCSV.reescribirArchivo(filasActualizadas);
    return proveedorEliminado;
}

void ProveedorServicio::ordenarProveedores(list<Proveedor>& proveedores)
{
    bool intercambio;
    do
    {
        intercambio = false;
        auto it = proveedores.begin();
        auto siguiente = next(it);
        while(siguiente != proveedores.end())
        {
            if(it->id > siguiente->id)
            {
                swap(*it, *siguiente);
                intercambio = true;
            }
            ++it;
            ++siguiente;
        }
    } while(intercambio);
}
