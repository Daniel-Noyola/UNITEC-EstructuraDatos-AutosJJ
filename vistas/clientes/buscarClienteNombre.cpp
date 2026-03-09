#include "../../AutosJJ.h"
#include "../../servicios/ClienteServicio.h"

void Vista::buscarClienteNombre()
{
	ClienteServicio clienteServicio;
	IO::limpiarPantalla();
	string nombre = IO::pedirDato("Ingresa el nombre del cliente a buscar: ");
	IO::imprimirLinea("=== Buscar Cliente por Nombre ===");
	try
	{
		Cliente cliente = clienteServicio.obtenerClientePorNombre(nombre);
		IO::imprimirLinea("Cliente encontrado:", TEXTO_EXITO);
		IO::imprimirLinea("ID: " + to_string(cliente.id));
		IO::imprimirLinea("Nombre: " + cliente.nombre);
		IO::imprimirLinea("Direccion: " + cliente.direccion);
		IO::imprimirLinea("Telefono: " + cliente.telefono);
		IO::imprimirLinea("Correo: " + cliente.correo);
		IO::imprimirLinea("Tiempo como cliente: " + to_string(cliente.tiempoComoCliente) + " anios");
	}
	catch (const exception& e)
	{
		IO::imprimirLinea("Error al buscar el cliente: " + string(e.what()), TEXTO_ERROR);
	}
	string opcion = IO::pedirDato("\nDeseas buscar otro cliente? (s/n): ");
	if (opcion == "s" || opcion == "S")
	{
		buscarClienteNombre();
		return;
	}
}