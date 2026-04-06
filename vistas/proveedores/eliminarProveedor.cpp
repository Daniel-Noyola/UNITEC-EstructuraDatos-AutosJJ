#include "../../AutosJJ.h"
#include "../../servicios/ProveedorServicio.h"

void Vista::eliminarProveedor()
{
	ProveedorServicio proveedorServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Eliminar Proveedor ===");
	try
	{
		int id = stoi(IO::pedirDato("Ingrese el ID del proveedor a eliminar: "));
		Proveedor proveedorEliminado = proveedorServicio.eliminarProveedor(id);
		IO::imprimirLinea("Proveedor eliminado: " + proveedorEliminado.nombre + " (ID: " + to_string(proveedorEliminado.id) + ")", TEXTO_EXITO);
	}
	catch(const exception& e)
	{
		IO::imprimirLinea("Error: " + string(e.what()), TEXTO_ERROR);
	}
	string opcion = IO::pedirDato("\nDeseas eliminar otro proveedor? (s/n): ");
	if(opcion == "s" || opcion == "S")
	{
		eliminarProveedor();
		return;
	}
}
