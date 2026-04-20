#include "../../AutosJJ.h"
#include "../../servicios/ClienteServicio.h"

void Vista::buscarClienteId()
{
	ClienteServicio clienteServicio;

	IO::limpiarPantalla();
	IO::imprimirLinea("=== Buscar Cliente por ID ===");
	try
	{
		int id = stoi(IO::pedirDato("Ingresa el ID del cliente a buscar: "));

		/*Obtiene el cliente por ID proporcinado por el usuario*/
		Cliente c = clienteServicio.obtenerClientePorId(id);
		IO::imprimirLinea("");
		IO::imprimirLinea("  --- [ Cliente #" + to_string(c.id) + " ] ---", TEXTO_ITALIC);
		IO::imprimirLinea(" | Nombre     : " + c.nombre);
		IO::imprimirLinea(" | Direccion  : " + c.direccion);
		IO::imprimirLinea(" | Telefono   : " + c.telefono);
		IO::imprimirLinea(" | Correo     : " + c.correo);
		IO::imprimirLinea(" | Antiguedad : " + to_string(c.tiempoComoCliente) + " anio(s)");
	}
	catch (const exception& e)
	{
		IO::imprimirLinea("Error: " + string(e.what()), TEXTO_ERROR);
	}

	/*Aplicacion alterna de recursion*/
	string op = IO::pedirDato("\nDeseas buscar otro cliente? (s/N): ");
	if (op == "s" || op == "S") { buscarClienteId(); return; }
}