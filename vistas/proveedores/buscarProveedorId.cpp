#include "../../AutosJJ.h"
#include "../../servicios/ProveedorServicio.h"

void Vista::buscarProveedorId()
{
	ProveedorServicio proveedorServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Buscar Proveedor por ID ===");
	try
	{
		int id = stoi(IO::pedirDato("Ingrese el ID del proveedor: "));

		/*Busca el proveedor en la base de datos (CSV)*/
		Proveedor proveedor = proveedorServicio.obtenerProveedorPorId(id);
		IO::imprimirLinea("Proveedor encontrado:", TEXTO_EXITO);
		IO::imprimirLinea("  ID       : " + to_string(proveedor.id));
		IO::imprimirLinea("  Nombre   : " + proveedor.nombre);
		IO::imprimirLinea("  Contacto : " + proveedor.contacto);
		IO::imprimirLinea("  Direccion: " + proveedor.direccion);
		IO::imprimirLinea("  Telefono : " + proveedor.telefono);
	}
	catch(const exception& e)
	{
		IO::imprimirLinea("Error: " + string(e.what()), TEXTO_ERROR);
	}

	/*Aplicacion alterna de recursion*/
	string opcion = IO::pedirDato("\nDeseas buscar otro proveedor? (s/N): ");
	if(opcion == "s" || opcion == "S")
	{
		buscarProveedorId();
		return;
	}
}
