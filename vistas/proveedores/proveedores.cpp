#include "../../AutosJJ.h"

void Vista::proveedores()
{
	vector<string> opcionesMenu = {
		"Listar Proveedores",
		"Registrar Proveedor",
		"Buscar Proveedor (id)",
		"Eliminar Proveedor (id)",
		"Volver al Dashboard"
	};
	while(true)
	{
		IO::limpiarPantalla();
		IO::imprimirLinea("=== Proveedores ===");
		IO::imprimirMenu("Opciones disponibles:", opcionesMenu);
		int opcion = 0;
		try {
			opcion = stoi(IO::pedirDato("Seleccione una opcion: "));
		}
		catch(const std::exception&)
		{
			IO::imprimirLinea("Opcion no valida. Intente nuevamente.", TEXTO_ADVERTENCIA);
			continue;
		}
		switch(opcion)
		{
			case 1: Vista::listarProveedores();   break;
			case 2: Vista::registrarProveedor();  break;
			case 3: Vista::buscarProveedorId();   break;
			case 4: Vista::eliminarProveedor();   break;
			case 5: return;
			default:
				IO::imprimirLinea("Opcion no valida. Intente nuevamente.", TEXTO_ADVERTENCIA);
				break;
		}
	}
}
