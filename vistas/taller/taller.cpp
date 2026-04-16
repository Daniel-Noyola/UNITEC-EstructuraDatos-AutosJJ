#include "../../AutosJJ.h"

void Vista::taller()
{
	/*Menu de opciones del taller*/
	vector<string> opcionesMenu = {
		"Agregar Gasto de Reparacion",
		"Ver Gastos de un Vehiculo",
		"Volver al Dashboard"
	};
	while(true)
	{
		IO::limpiarPantalla();
		IO::imprimirLinea("=== Taller - Gastos de Reparacion ===");
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
			case 1: Vista::agregarGasto(); break;
			case 2: Vista::verGastos();    break;
			case 3: return;
			default:
				IO::imprimirLinea("Opcion no valida. Intente nuevamente.", TEXTO_ADVERTENCIA);
				break;
		}
	}
}
