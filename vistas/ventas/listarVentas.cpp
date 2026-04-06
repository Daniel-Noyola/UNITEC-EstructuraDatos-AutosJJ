#include "../../AutosJJ.h"
#include "../../servicios/VentaServicio.h"

void Vista::listarVentas()
{
	VentaServicio ventaServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Historial de Ventas ===");
	try
	{
		list<Venta> ventas = ventaServicio.obtenerVentas();
		if(ventas.empty())
		{
			IO::imprimirLinea("No hay ventas registradas.", TEXTO_ADVERTENCIA);
		}
		else
		{
			IO::imprimirLinea(to_string(ventas.size()) + " venta(s) registrada(s).");
			IO::imprimirLinea("");
			for(const Venta& v : ventas)
			{
				string estiloUtil = v.utilidad >= 0 ? TEXTO_EXITO : TEXTO_ERROR;
				IO::imprimirLinea("--- [ Venta #" + to_string(v.id) + " ] ---", TEXTO_BOLD);
				IO::imprimirLinea("  Vehiculo ID   : " + to_string(v.vehiculoId));
				IO::imprimirLinea("  Cliente ID    : " + to_string(v.clienteId));
				IO::imprimirLinea("  Precio Venta  : $" + to_string(v.precioVenta));
				IO::imprimirLinea("  Precio Adq.   : $" + to_string(v.precioAdquisicion));
				IO::imprimirLinea("  Gastos Rep.   : $" + to_string(v.totalGastos));
				IO::imprimirLinea("  Costo Total   : $" + to_string(v.precioAdquisicion + v.totalGastos));
				IO::imprimirLinea("  Utilidad      : $" + to_string(v.utilidad), estiloUtil);
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
