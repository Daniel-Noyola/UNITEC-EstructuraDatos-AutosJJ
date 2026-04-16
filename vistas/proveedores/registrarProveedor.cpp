#include "../../AutosJJ.h"
#include "../../servicios/ProveedorServicio.h"

void Vista::registrarProveedor()
{
	ProveedorServicio proveedorServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Registrar Proveedor ===");
	try
	{
		/*Crea un nuevo proveedor*/
		Proveedor nuevoProveedor;
		nuevoProveedor.nombre    = IO::pedirDato("Ingrese el nombre del proveedor: ");
		nuevoProveedor.contacto  = IO::pedirDato("Ingrese el nombre del contacto: ");
		nuevoProveedor.direccion = IO::pedirDato("Ingrese la direccion: ");
		nuevoProveedor.telefono  = IO::pedirDato("Ingrese el telefono: ");

		/*Agrega el proveedor a la base de datos (CSV)*/
		Proveedor proveedorRegistrado = proveedorServicio.agregarProveedor(nuevoProveedor);
		IO::imprimirLinea("Proveedor registrado exitosamente con ID: " + to_string(proveedorRegistrado.id), TEXTO_EXITO);
	}
	catch(const exception& e)
	{
		IO::imprimirLinea("Error al registrar el proveedor: " + string(e.what()), TEXTO_ERROR);
	}

	/*Aplicacion alterna de recursion*/
	string opcion = IO::pedirDato("\nDeseas registrar otro proveedor? (s/N): ");
	if(opcion == "s" || opcion == "S")
	{
		registrarProveedor();
		return;
	}
}
