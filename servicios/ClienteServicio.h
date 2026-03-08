#ifndef CLIENTESERVICIO_H
#define CLIENTESERVICIO_H
#include "../utilidades/EditorCSV.h"
#include "../modelos/Cliente.h"

struct ClienteServicio
{
	EditorCSV editor;

	ClienteServicio();

	/*Obtiene la lista de clientes registrados*/
	vector<Cliente> obtenerClientes();

	
};

#endif // CLIENTESERVICIO_H