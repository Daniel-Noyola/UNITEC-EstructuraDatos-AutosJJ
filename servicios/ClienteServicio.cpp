#include "ClienteServicio.h"
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

void ClienteServicio::validarCliente(const Cliente& cliente)
{
	if (cliente.nombre.empty())
		throw invalid_argument("El nombre no puede estar vacio.");
	if (cliente.direccion.empty())
		throw invalid_argument("La direccion no puede estar vacia.");
	if (cliente.telefono.empty())
		throw invalid_argument("El telefono no puede estar vacio.");
	if (cliente.correo.empty())
		throw invalid_argument("El correo no puede estar vacio.");
	if (cliente.tiempoComoCliente < 0)
		throw invalid_argument("El anio de registro no es valido.");
}

Cliente ClienteServicio::agregarCliente(Cliente cliente)
{
	validarCliente(cliente);

	cliente.id = ++ultimoId;

	/*Guardar el nuevo cliente en el archivo CSV*/
	string filaCliente = 
		to_string(cliente.id) + "," +
		to_string(cliente.tiempoComoCliente) + "," +
		cliente.nombre + "," +
		cliente.direccion + "," +
		cliente.telefono + "," +
		cliente.correo;
	editorCSV.guardarEnArchivo(filaCliente);

	return cliente;
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