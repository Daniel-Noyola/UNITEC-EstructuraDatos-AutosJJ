#include "../../AutosJJ.h"
#include "../../servicios/ClienteServicio.h"

void Vista::listarClientes()
{
	ClienteServicio clienteServicio;
	vector<Cliente> clientes = clienteServicio.obtenerClientes();

	IO::limpiarPantalla();
	IO::imprimirLinea("=== Clientes Registrados ===");

	if (clientes.empty())
	{
		IO::imprimirLinea("No hay clientes registrados.", TEXTO_ADVERTENCIA);
	}
	else
	{
		for (const Cliente& cliente : clientes)
		{
			string textoCliente = 
				"ID: " 
				+ to_string(cliente.id) 
				+ " | Nombre: " + cliente.nombre 
				+ " | Telefono: " + cliente.telefono 
				+ " | Email: " + cliente.correo 
				+ " | Tiempo Como Cliente: " + to_string(cliente.tiempoComoCliente) + " anios";
			IO::imprimirLinea(textoCliente);
		}
	}

	IO::imprimirLinea("Presiona ENTER para volver al dashboard...", "", false);
	cin.get();
}