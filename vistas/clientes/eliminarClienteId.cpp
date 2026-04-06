#include "../../AutosJJ.h"
#include "../../servicios/ClienteServicio.h"

void Vista::eliminarClienteId()
{
	ClienteServicio clienteServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Eliminar Cliente por ID ===");
	try
	{
		int id = stoi(IO::pedirDato("Ingresa el ID del cliente a eliminar: "));
		Cliente c = clienteServicio.eliminarCliente(id);
		IO::imprimirLinea("");
		IO::imprimirLinea("--- [ Cliente eliminado #" + to_string(c.id) + " ] ---", TEXTO_ITALIC);
		IO::imprimirLinea("  Nombre     : " + c.nombre);
		IO::imprimirLinea("  Direccion  : " + c.direccion);
		IO::imprimirLinea("  Telefono   : " + c.telefono);
		IO::imprimirLinea("  Correo     : " + c.correo);
	}
	catch (const exception& e)
	{
		IO::imprimirLinea("Error: " + string(e.what()), TEXTO_ERROR);
	}
	string op = IO::pedirDato("\nDeseas eliminar otro cliente? (s/n): ");
	if (op == "s" || op == "S") { eliminarClienteId(); return; }
}