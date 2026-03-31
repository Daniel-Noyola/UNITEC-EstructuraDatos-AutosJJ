#ifndef CLIENTESERVICIO_H
#define CLIENTESERVICIO_H
#include "../utilidades/EditorCSV.h"
#include "../modelos/Cliente.h"
#include <list>

struct ClienteServicio
{
	EditorCSV editorCSV;
	static int ultimoId;

	ClienteServicio();

	/*Obtiene la lista de clientes registrados*/
	list<Cliente> obtenerClientes();

	/*Agrega un nuevo cliente*/
	Cliente agregarCliente(const string& nombre, const string& direccion, const string& telefono, const string& correo, const string& fechaRegistro);

	/*Obtiene un cliente por su ID*/
	Cliente obtenerClientePorId(int id);

	/*Obtiene un cliente por su nombre (busqueda exacta)*/
	Cliente obtenerClientePorNombre(const string& nombre);

	/*Elimina un cliente por su ID y devuelve el cliente eliminado*/
	Cliente eliminarCliente(int id);

	/*Ordena la lista de clientes por ID usando bubble sort*/
	static void ordenarClientes(list<Cliente>& clientes);
};

#endif // CLIENTESERVICIO_H