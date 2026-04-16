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

		/*Elimina el proveedor de la base de datos (CSV)*/
		Proveedor proveedorEliminado = proveedorServicio.eliminarProveedor(id);
		IO::imprimirLinea("Proveedor eliminado: " + proveedorEliminado.nombre + " (ID: " + to_string(proveedorEliminado.id) + ")", TEXTO_EXITO);
	}
	catch(const exception& e)
	{
		IO::imprimirLinea("Error: " + string(e.what()), TEXTO_ERROR);
	}

	/*Aplicacion alterna de recursion*/
	string opcion = IO::pedirDato("\nDeseas eliminar otro proveedor? (s/N): ");
	if(opcion == "s" || opcion == "S")
	{
		eliminarProveedor();
		return;
	}
}
