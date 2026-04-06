#include "../../AutosJJ.h"
#include "../../servicios/ClienteServicio.h"

void Vista::listarClientes()
{
	ClienteServicio clienteServicio;
	list<Cliente> clientes = clienteServicio.obtenerClientes();

	IO::limpiarPantalla();
	IO::imprimirLinea("=== Clientes Registrados ===");

	if (clientes.empty())
	{
		IO::imprimirLinea("No hay clientes registrados.", TEXTO_ADVERTENCIA);
	}
	else
	{
		IO::imprimirLinea(to_string(clientes.size()) + " cliente(s) encontrado(s).");
		IO::imprimirLinea("");
		for (const Cliente& c : clientes)
		{
			IO::imprimirLinea("--- [ Cliente #" + to_string(c.id) + " ] ---", TEXTO_ITALIC);
			IO::imprimirLinea("  Nombre     : " + c.nombre);
			IO::imprimirLinea("  Direccion  : " + c.direccion);
			IO::imprimirLinea("  Telefono   : " + c.telefono);
			IO::imprimirLinea("  Correo     : " + c.correo);
			IO::imprimirLinea("  Antiguedad : " + to_string(c.tiempoComoCliente) + " anio(s)");
			IO::imprimirLinea("");
		}
	}

	IO::pedirDato("Presiona ENTER para volver...");
}