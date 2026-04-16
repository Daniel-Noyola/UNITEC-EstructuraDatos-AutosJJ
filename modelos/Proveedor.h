#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include <string>
using namespace std;

/*Estructura que representa a un proveedor*/
struct Proveedor
{
    int id;
    string nombre;
    string contacto;
    string direccion;
    string telefono;
};

#endif // PROVEEDOR_H
