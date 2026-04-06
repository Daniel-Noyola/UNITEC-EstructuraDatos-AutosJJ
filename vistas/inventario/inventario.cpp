#include "../../AutosJJ.h"
#include "../../servicios/VehiculoServicio.h"

void Vista::inventario()
{
	VehiculoServicio vehiculoServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Inventario - Vehiculos Disponibles para Venta ===");
	IO::imprimirLinea("(Ordenados por precio de adquisicion - Bubble Sort)", TEXTO_ADVERTENCIA);
	try
	{
		list<Vehiculo> disponibles = vehiculoServicio.obtenerVehiculosDisponibles();

		if(disponibles.empty())
		{
			IO::imprimirLinea("");
			IO::imprimirLinea("No hay vehiculos disponibles para la venta.", TEXTO_ADVERTENCIA);
			IO::imprimirLinea("  > Registra vehiculos en: Dashboard > Vehiculos > Registrar Vehiculo");
			IO::imprimirLinea("  > Marca como listos en : Dashboard > Vehiculos > Finalizar Reparacion");
		}
		else
		{
			// Ordenar por precio de adquisicion (Bubble Sort)
			VehiculoServicio::ordenarVehiculosPorPrecio(disponibles);

			IO::imprimirLinea(to_string(disponibles.size()) + " vehiculo(s) disponible(s).");
			IO::imprimirLinea("");
			int pos = 1;
			for(const Vehiculo& v : disponibles)
			{
				IO::imprimirLinea("--- [ #" + to_string(pos++) + " | Vehiculo ID " + to_string(v.id) + " ] ---", TEXTO_BOLD);
				IO::imprimirLinea("  Marca         : " + v.marca + " " + v.modelo + " " + to_string(v.anio));
				IO::imprimirLinea("  Color         : " + v.color + "  |  Version: " + v.version);
				IO::imprimirLinea("  Kilometraje   : " + v.kilometraje + " km");
				IO::imprimirLinea("  Precio Adq.   : $" + to_string(v.precioAdquisicion));
				IO::imprimirLinea("  Precio Cliente: $" + to_string(v.precioCliente));
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
