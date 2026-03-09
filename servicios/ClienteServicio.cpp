#include "ClienteServicio.h"
#include "../modelos/Cliente.h"
#include "../utilidades/Utils.h"
#include <sstream>
#include <vector>

int ClienteServicio::ultimoId = 1000;

ClienteServicio::ClienteServicio() : editorCSV("data/clientes.csv")
{
	editorCSV.crearArchivo("ID,TiempoComoCliente,Nombre,Direccion,Telefono,Correo");
}

vector<Cliente> ClienteServicio::obtenerClientes()
{
	vector<string> filas = editorCSV.leerArchivo();
	vector<Cliente> clientes;

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
	return clientes;
}

Cliente ClienteServicio::agregarCliente(const string& nombre, const string& direccion, const string& telefono, const string& correo, const string& fechaRegistro)
{
	int diferenciaTiempo;
	calcularDiferenciaDeTiempo(stoi(fechaRegistro), &diferenciaTiempo);

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
