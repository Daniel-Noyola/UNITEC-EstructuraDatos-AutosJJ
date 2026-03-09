#include "../../AutosJJ.h"
#include "../../servicios/ClienteServicio.h"

void Vista::buscarClienteId()
{
	ClienteServicio clienteServicio;

	IO::limpiarPantalla();
	int id = stoi(IO::pedirDato("Ingresa el ID del cliente a buscar: "));
	IO::imprimirLinea("=== Buscar Cliente por ID ===");
	try
	{
		Cliente cliente = clienteServicio.obtenerClientePorId(id);
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
		buscarClienteId();
		return;
	}
}