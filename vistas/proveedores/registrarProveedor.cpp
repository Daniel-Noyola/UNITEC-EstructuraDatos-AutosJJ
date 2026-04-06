#include "../../AutosJJ.h"
#include "../../servicios/ProveedorServicio.h"

void Vista::registrarProveedor()
{
	ProveedorServicio proveedorServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Registrar Proveedor ===");
	try
	{
		Proveedor nuevoProveedor;
		nuevoProveedor.nombre    = IO::pedirDato("Ingrese el nombre del proveedor: ");
		nuevoProveedor.contacto  = IO::pedirDato("Ingrese el nombre del contacto: ");
		nuevoProveedor.direccion = IO::pedirDato("Ingrese la direccion: ");
		nuevoProveedor.telefono  = IO::pedirDato("Ingrese el telefono: ");

		Proveedor proveedorRegistrado = proveedorServicio.agregarProveedor(nuevoProveedor);
		IO::imprimirLinea("Proveedor registrado exitosamente con ID: " + to_string(proveedorRegistrado.id), TEXTO_EXITO);
	}
	catch(const exception& e)
	{
		IO::imprimirLinea("Error al registrar el proveedor: " + string(e.what()), TEXTO_ERROR);
	}
	string opcion = IO::pedirDato("\nDeseas registrar otro proveedor? (s/n): ");
	if(opcion == "s" || opcion == "S")
	{
		registrarProveedor();
		return;
	}
}
