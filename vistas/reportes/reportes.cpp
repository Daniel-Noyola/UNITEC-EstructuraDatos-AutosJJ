#include "../../AutosJJ.h"
#include "../../servicios/VentaServicio.h"
#include "../../servicios/VehiculoServicio.h"
#include "../../servicios/GastoReparacionServicio.h"

void Vista::reportes()
{
	VentaServicio ventaServicio;
	VehiculoServicio vehiculoServicio;
	GastoReparacionServicio gastoServicio;

	IO::limpiarPantalla();
	IO::imprimirLinea("=== Reportes Financieros ===");
	IO::imprimirLinea("(Los totales se calculan de forma RECURSIVA sobre las listas)", TEXTO_ADVERTENCIA);

	try
	{
		/*Ganancia neta total de ventas (Funcion recursiva)*/
		list<Venta> ventas = ventaServicio.obtenerVentas();
		double gananciaTotal = VentaServicio::calcularGananciaTotal(ventas.cbegin(), ventas.cend());

		IO::imprimirLinea("");
		IO::imprimirLinea(">>> VENTAS <<<");
		IO::imprimirLinea("Total de ventas realizadas : " + to_string(ventas.size()));
		IO::imprimirLinea("Ganancia neta total        : $" + to_string(gananciaTotal),
			gananciaTotal >= 0 ? TEXTO_EXITO : TEXTO_ERROR);

		/*Vehiculos no vendidos aun*/
		list<Vehiculo> vehiculos = vehiculoServicio.obtenerVehiculos();
		double capitalEnStock = 0.0;
		int vehiculosEnTaller = 0;
		int vehiculosDisponibles = 0;

		for(const Vehiculo& v : vehiculos)
		{
			capitalEnStock += v.precioAdquisicion;
			if(v.reparado)
				vehiculosDisponibles++;
			else
				vehiculosEnTaller++;
		}

		IO::imprimirLinea("");
		IO::imprimirLinea(">>> STOCK <<<");
		IO::imprimirLinea("Total de vehiculos en stock: " + to_string(vehiculos.size()));
		IO::imprimirLinea("  - En taller (pendientes) : " + to_string(vehiculosEnTaller));
		IO::imprimirLinea("  - Listos para venta      : " + to_string(vehiculosDisponibles));
		IO::imprimirLinea("Capital total invertido    : $" + to_string(capitalEnStock));

		/*Total de gastos de reparacion (Funcion recursiva)*/
		list<GastoReparacion> todosLosGastos = gastoServicio.obtenerGastos();
		double totalGastosRep = GastoReparacionServicio::calcularTotalGastos(todosLosGastos.cbegin(), todosLosGastos.cend());

		IO::imprimirLinea("");
		IO::imprimirLinea(">>> TALLER <<<");
		IO::imprimirLinea("Total de gastos de reparacion registrados: $" + to_string(totalGastosRep));
		IO::imprimirLinea("Cantidad de registros de gasto: " + to_string(todosLosGastos.size()));
	}
	catch(const exception& e)
	{
		IO::imprimirLinea("Error al generar reportes: " + string(e.what()), TEXTO_ERROR);
	}

	IO::pedirDato("\nPresiona ENTER para volver...");
}
