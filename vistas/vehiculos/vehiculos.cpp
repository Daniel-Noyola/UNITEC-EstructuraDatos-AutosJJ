#include "../../AutosJJ.h"

// Menú principal para gestionar vehiculos y compras.
void Vista::vehiculos()
{
	vector<string> opcionesMenu = {
		"Registrar Vehiculo (Compra)",
		"Listar Vehiculos",
		"Buscar Vehiculo (id)",
		"Buscar Vehiculo (marca)",
		"Finalizar Reparacion",
		"Volver al Dashboard"
	};
	while (true)
	{
		IO::limpiarPantalla();
		IO::imprimirLinea("=== Vehiculos / Compras ===");
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
			case 2: Vista::listarVehiculos();   break;
			case 3: Vista::buscarVehiculoId();  break;
			case 4: Vista::buscarVehiculoMarca(); break;
			case 5: Vista::marcarReparado();    break;
			case 6: return;
			default:
				IO::imprimirLinea("Opcion no valida. Intente nuevamente.", TEXTO_ADVERTENCIA);
				break;
		}
	}
}