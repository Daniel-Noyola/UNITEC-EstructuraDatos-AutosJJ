#ifndef PROVEEDORSERVICIO_H
#define PROVEEDORSERVICIO_H
#include "../utilidades/EditorCSV.h"
#include "../modelos/Proveedor.h"
#include <list>

struct ProveedorServicio
{
    EditorCSV editorCSV;
    static int ultimoId;

    ProveedorServicio();

    /*Obtiene la lista de proveedores registrados*/
    list<Proveedor> obtenerProveedores();

    /*Valida los campos de un proveedor antes de guardarlo*/
    static void validarProveedor(const Proveedor& proveedor);

    /*Agrega un nuevo proveedor*/
    Proveedor agregarProveedor(Proveedor proveedor);

    /*Obtiene un proveedor por su ID*/
    Proveedor obtenerProveedorPorId(int id);

    /*Elimina un proveedor por su ID*/
    Proveedor eliminarProveedor(int id);

    /*Ordena la lista de proveedores por ID usando bubble sort*/
    static void ordenarProveedores(list<Proveedor>& proveedores);
};

#endif // PROVEEDORSERVICIO_H
