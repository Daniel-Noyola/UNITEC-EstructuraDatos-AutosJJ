#include "../../AutosJJ.h"
#include "../../servicios/ClienteServicio.h"

void Vista::buscarClienteNombre()
{
	ClienteServicio clienteServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Buscar Cliente por Nombre ===");
	try
	{
		string nombre = IO::pedirDato("Ingresa el nombre del cliente a buscar: ");
		
		/*Obtiene el cliente por nombre proporcinado por el usuario*/
		Cliente c = clienteServicio.obtenerClientePorNombre(nombre);
		IO::imprimirLinea("");
		IO::imprimirLinea("  --- [ Cliente #" + to_string(c.id) + " ] ---", TEXTO_ITALIC);
		IO::imprimirLinea(" | Nombre      : " + c.nombre);
		IO::imprimirLinea(" | Direccion   : " + c.direccion);
		IO::imprimirLinea(" | Telefono    : " + c.telefono);
		IO::imprimirLinea(" | Correo      : " + c.correo);
		IO::imprimirLinea(" | Antiguedad  : " + to_string(c.tiempoComoCliente) + " anio(s)");
	}
	catch (const exception& e)
	{
		IO::imprimirLinea("Error: " + string(e.what()), TEXTO_ERROR);
	}

	/*Aplicacion alterna de recursion*/
	string op = IO::pedirDato("\nDeseas buscar otro cliente? (s/N): ");
	if (op == "s" || op == "S") { buscarClienteNombre(); return; }
}