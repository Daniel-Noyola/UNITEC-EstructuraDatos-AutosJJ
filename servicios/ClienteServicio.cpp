#include "ClienteServicio.h"
#include "../utilidades/Utils.h"
#include <sstream>

int ClienteServicio::ultimoId = 1000;

ClienteServicio::ClienteServicio() : editorCSV("data/clientes.csv", "ID,TiempoComoCliente,Nombre,Direccion,Telefono,Correo")
{
	editorCSV.crearArchivo();

	for (const Cliente& cliente : obtenerClientes())
	{
		if (cliente.id > ultimoId)
			ultimoId = cliente.id;
	}
}

list<Cliente> ClienteServicio::obtenerClientes()
{
	vector<string> filas = editorCSV.leerArchivo();
	list<Cliente> clientes;

	for (const string& fila : filas)
	{
		Cliente cliente;
		string campo;
		stringstream ss(fila);
		int indice = 0;

		while (getline(ss, campo, ','))
		{
			switch (indice)
			{
			case 0: cliente.id                = stoi(campo); break;
			case 1: cliente.tiempoComoCliente = stoi(campo); break;
			case 2: cliente.nombre            = campo;       break;
			case 3: cliente.direccion         = campo;       break;
			case 4: cliente.telefono          = campo;       break;
			case 5: cliente.correo            = campo;       break;
			}
			indice++;
		}
		clientes.push_back(cliente);
	}
	ordenarClientes(clientes);
	return clientes;
}

Cliente ClienteServicio::agregarCliente(const string& nombre, const string& direccion, const string& telefono, const string& correo, const string& fechaRegistro)
{
	int diferenciaTiempo;
	try
	{
		calcularDiferenciaDeTiempo(stoi(fechaRegistro), &diferenciaTiempo);
	}
	catch (const invalid_argument&)
	{
		throw invalid_argument("El anio de registro debe ser un numero valido.");
	}

	Cliente nuevoCliente;
	nuevoCliente.id = ++ultimoId;
	nuevoCliente.nombre = nombre;
	nuevoCliente.direccion = direccion;
	nuevoCliente.telefono = telefono;
	nuevoCliente.correo = correo;
	nuevoCliente.tiempoComoCliente = diferenciaTiempo;
	
	/*Guardar el nuevo cliente en el archivo CSV*/
	string filaCliente = 
		to_string(nuevoCliente.id) + "," +
		to_string(nuevoCliente.tiempoComoCliente) + "," +
		nuevoCliente.nombre + "," +
		nuevoCliente.direccion + "," +
		nuevoCliente.telefono + "," +
		nuevoCliente.correo;
	editorCSV.guardarEnArchivo(filaCliente);

	return nuevoCliente;
}

Cliente ClienteServicio::obtenerClientePorId(int id)
{
	list<Cliente> clientes = obtenerClientes();
	for (const Cliente& cliente : clientes)
	{
		if (cliente.id == id)
			return cliente;
	}
	throw invalid_argument("No se encontro un cliente con el ID especificado.");
}

Cliente ClienteServicio::obtenerClientePorNombre(const string& nombre)
{
	list<Cliente> clientes = obtenerClientes();
	for (const Cliente& cliente : clientes)
	{
		if (cliente.nombre == nombre)
			return cliente;
	}
	throw invalid_argument("No se encontro un cliente con el nombre especificado.");
}

Cliente ClienteServicio::eliminarCliente(int id)
{
	list<Cliente> clientes = obtenerClientes();
	Cliente clienteEliminado;
	bool encontrado = false;
	for (const Cliente& cliente : clientes)
	{
		if (cliente.id == id)
		{
			clienteEliminado = cliente;
			encontrado = true;
			break;
		}
	}

	if (!encontrado)
		throw invalid_argument("No se encontro un cliente con el ID especificado.");

	vector<string> filasActualizadas;
	for (const Cliente& cliente : clientes)
	{
		if (cliente.id != id)
		{
			string filaCliente = 
				to_string(cliente.id) + "," +
				to_string(cliente.tiempoComoCliente) + "," +
				cliente.nombre + "," +
				cliente.direccion + "," +
				cliente.telefono + "," +
				cliente.correo;
			filasActualizadas.push_back(filaCliente);
		}
	}
	editorCSV.reescribirArchivo(filasActualizadas);
	return clienteEliminado;
}

void ClienteServicio::ordenarClientes(list<Cliente>& clientes)
{
	bool intercambio;
	do
	{
		intercambio = false;
		auto it = clientes.begin();
		auto siguiente = next(it);
		while (siguiente != clientes.end())
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