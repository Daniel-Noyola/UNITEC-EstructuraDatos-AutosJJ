#include "../../AutosJJ.h"

void Vista::clientes()
{
	vector<string> opcionesMenu = {
		"Listar Clientes",
		"Registrar Cliente",
		"Buscar Cliente (id)",
		"Buscar Cliente (nombre)",
		"Eliminar Cliente (id)",
		"Volver al Dashboard"
	};

	while (true)
	{
		IO::limpiarPantalla();
		IO::imprimirLinea("=== Clientes ===");
		IO::imprimirMenu("Opciones disponibles:", opcionesMenu);
		int opcion = 0;
		try {
			opcion = stoi(IO::pedirDato("Seleccione una opcion: "));
		}
		catch (const std::exception&)
		{
			IO::imprimirLinea("Opcion no valida. Intente nuevamente.", TEXTO_ADVERTENCIA);
			continue;
		}
		switch (opcion)
		{
		case 1: Vista::listarClientes(); break;
		case 2: Vista::registrarCliente(); break;
		case 3: Vista::buscarClienteId(); break;
		case 4: Vista::buscarClienteNombre(); break;
		case 5: Vista::eliminarClienteId(); break;
		case 6: return; break;
		default:
			IO::imprimirLinea("Opcion no valida. Intente nuevamente.", TEXTO_ADVERTENCIA);
			break;
		}
	}
}