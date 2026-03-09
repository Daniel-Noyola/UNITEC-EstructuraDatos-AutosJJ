#ifndef CLIENTESERVICIO_H
#define CLIENTESERVICIO_H
#include "../utilidades/EditorCSV.h"
#include "../modelos/Cliente.h"

struct ClienteServicio
{
	EditorCSV editorCSV;
	static int ultimoId;

	ClienteServicio();

	/*Obtiene la lista de clientes registrados*/
	vector<Cliente> obtenerClientes();

	/*Agrega un nuevo cliente*/
	Cliente agregarCliente(const string& nombre, const string& direccion, const string& telefono, const string& correo, const string& fechaRegistro);

	/*Obtiene un cliente por su ID*/
	Cliente obtenerClientePorId(int id);

	/*Obtiene un cliente por su nombre (busqueda exacta)*/
	Cliente obtenerClientePorNombre(const string& nombre);

	
};

#endif // CLIENTESERVICIO_H