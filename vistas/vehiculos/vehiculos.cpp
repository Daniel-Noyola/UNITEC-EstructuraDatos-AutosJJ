#include "../../AutosJJ.h"

void Vista::vehiculos()
{
	vector<string> opcionesMenu = {
		"Registrar Vehiculo",
		"Buscar Vehiculo (id)",
		"Buscar Vehiculo (marca)",
		"Volver al Dashboard"
	};
	while (true)
	{
		IO::limpiarPantalla();
		IO::imprimirLinea("=== Vehiculos ===");
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
			case 1: Vista::registrarVehiculo(); break;
			case 2: Vista::buscarVehiculoId(); break;
			case 3: Vista::buscarVehiculoMarca(); break;
			case 4: return; break;
			default:
				IO::imprimirLinea("Opcion no valida. Intente nuevamente.", TEXTO_ADVERTENCIA);
				break;
		}
	}
}