#include "../../AutosJJ.h"
#include "../../servicios/ProveedorServicio.h"

void Vista::listarProveedores()
{
	ProveedorServicio proveedorServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Lista de Proveedores ===");
	try
	{
		list<Proveedor> proveedores = proveedorServicio.obtenerProveedores();
		if(proveedores.empty())
		{
			IO::imprimirLinea("No hay proveedores registrados.", TEXTO_ADVERTENCIA);
		}
		else
		{
			IO::imprimirLinea(to_string(proveedores.size()) + " proveedor(es) registrado(s).");
			IO::imprimirLinea("");
			for(const Proveedor& p : proveedores)
			{
				IO::imprimirLinea("  --- [ Proveedor #" + to_string(p.id) + " ] ---", TEXTO_BOLD);
				IO::imprimirLinea(" | Nombre       : " + p.nombre);
				IO::imprimirLinea(" | Contacto     : " + p.contacto);
				IO::imprimirLinea(" | Direccion    : " + p.direccion);
				IO::imprimirLinea(" | Telefono     : " + p.telefono);
				IO::imprimirLinea("");
			}
		}
	}
	catch(const exception& e)
	{
		IO::imprimirLinea("Error: " + string(e.what()), TEXTO_ERROR);
	}
	IO::pedirDato("Presiona ENTER para volver...");
}
