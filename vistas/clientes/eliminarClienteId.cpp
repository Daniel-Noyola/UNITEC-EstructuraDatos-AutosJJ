#include "../../AutosJJ.h"
#include "../../servicios/ClienteServicio.h"

void Vista::eliminarClienteId()
{
	ClienteServicio clienteServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Eliminar Cliente por ID ===");
	string idStr = IO::pedirDato("Ingresa el ID del cliente a eliminar: ");

	try
	{
		int id = stoi(idStr);
		Cliente clienteEliminado = clienteServicio.eliminarCliente(id);

		IO::imprimirLinea("Cliente eliminado exitosamente:", TEXTO_EXITO);
		IO::imprimirLinea("ID: " + to_string(clienteEliminado.id));
		IO::imprimirLinea("Nombre: " + clienteEliminado.nombre);
		IO::imprimirLinea("Direccion: " + clienteEliminado.direccion);
		IO::imprimirLinea("Telefono: " + clienteEliminado.telefono);
		IO::imprimirLinea("Correo: " + clienteEliminado.correo);
	}
	catch (const exception& e)
	{
		IO::imprimirLinea("Error al eliminar el cliente: " + string(e.what()), TEXTO_ERROR);
	}
	string opcion = IO::pedirDato("\nDeseas eliminar otro cliente? (s/n): ");
	if (opcion == "s" || opcion == "S")
	{
		eliminarClienteId();
		return;
	}
}