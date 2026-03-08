#include "ClienteServicio.h"
#include "../modelos/Cliente.h"
#include <sstream>
#include <vector>

ClienteServicio::ClienteServicio() : editor("data/clientes.csv")
{
	editor.crearArchivo("ID,TiempoComoCliente,Nombre,Direccion,Telefono,Correo");
}

vector<Cliente> ClienteServicio::obtenerClientes()
{
	vector<string> filas = editor.leerArchivo();
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
