#include "../../AutosJJ.h"

void Vista::ventas()
{
	vector<string> opcionesMenu = {
		"Registrar Venta",
		"Ver Historial de Ventas",
		"Volver al Dashboard"
	};
	while(true)
	{
		IO::limpiarPantalla();
		IO::imprimirLinea("=== Ventas ===");
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
			case 1: Vista::registrarVenta(); break;
			case 2: Vista::listarVentas();   break;
			case 3: return;
			default:
				IO::imprimirLinea("Opcion no valida. Intente nuevamente.", TEXTO_ADVERTENCIA);
				break;
		}
	}
}
