#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

/*Estructura que representa a un cliente*/
struct Cliente
{
	int id;
	int tiempoComoCliente;
	string nombre;
	string direccion;
	string telefono;
	string correo;
};

#endif