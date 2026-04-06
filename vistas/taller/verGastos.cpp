#include "../../AutosJJ.h"
#include "../../servicios/GastoReparacionServicio.h"
#include "../../servicios/VehiculoServicio.h"

void Vista::verGastos()
{
	GastoReparacionServicio gastoServicio;
	VehiculoServicio vehiculoServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Gastos de Reparacion de un Vehiculo ===");
	try
	{
		int vehiculoId = stoi(IO::pedirDato("Ingrese el ID del vehiculo: "));

		Vehiculo v = vehiculoServicio.obtenerVehiculoPorId(vehiculoId);
		IO::imprimirLinea("");
		IO::imprimirLinea("--- [ Vehiculo #" + to_string(v.id) + ": " + v.marca + " " + v.modelo + " " + to_string(v.anio) + " ] ---", TEXTO_BOLD);
		IO::imprimirLinea("");

		list<GastoReparacion> gastos = gastoServicio.obtenerGastosPorVehiculo(vehiculoId);

		if(gastos.empty())
		{
			IO::imprimirLinea("  Sin gastos registrados para este vehiculo.", TEXTO_ADVERTENCIA);
		}
		else
		{
			int num = 1;
			for(const GastoReparacion& g : gastos)
			{
				IO::imprimirLinea("  Gasto #" + to_string(num++) + " (ID " + to_string(g.id) + ")");
				IO::imprimirLinea("    Descripcion : " + g.descripcion);
				IO::imprimirLinea("    Monto       : $" + to_string(g.monto));
				IO::imprimirLinea("");
			}

			// Total calculado de forma RECURSIVA
			double total = GastoReparacionServicio::calcularTotalGastos(gastos.cbegin(), gastos.cend());
			IO::imprimirLinea("  >>> TOTAL de gastos de reparacion: $" + to_string(total), TEXTO_EXITO);
		}
	}
	catch(const exception& e)
	{
		IO::imprimirLinea("Error: " + string(e.what()), TEXTO_ERROR);
	}
	IO::pedirDato("\nPresiona ENTER para volver...");
}
