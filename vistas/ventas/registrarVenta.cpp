#include "../../AutosJJ.h"
#include "../../servicios/VentaServicio.h"
#include "../../servicios/VehiculoServicio.h"
#include "../../servicios/ClienteServicio.h"
#include "../../servicios/GastoReparacionServicio.h"

// Registra una venta de vehiculo disponible, calculando utilidad.
void Vista::registrarVenta()
{
	VentaServicio ventaServicio;
	VehiculoServicio vehiculoServicio;
	ClienteServicio clienteServicio;
	GastoReparacionServicio gastoServicio;

	IO::limpiarPantalla();
	IO::imprimirLinea("=== Registrar Venta ===");
	IO::imprimirLinea("Solo se pueden vender vehiculos con reparacion finalizada.", TEXTO_ADVERTENCIA);
	try
	{
		// Mostrar inventario disponible
		list<Vehiculo> disponibles = vehiculoServicio.obtenerVehiculosDisponibles();
		if(disponibles.empty())
		{
			IO::imprimirLinea("No hay vehiculos disponibles para la venta.", TEXTO_ERROR);
			IO::pedirDato("\nPresiona ENTER para volver...");
			return;
		}

		IO::imprimirLinea("Vehiculos disponibles:");
		for(const Vehiculo& v : disponibles)
		{
			IO::imprimirLinea("  [" + to_string(v.id) + "] " + v.marca + " " + v.modelo + " " + to_string(v.anio) + " | Adq: $" + to_string(v.precioAdquisicion));
		}

		Venta nuevaVenta;
		nuevaVenta.vehiculoId = stoi(IO::pedirDato("\nIngrese el ID del vehiculo a vender: "));

		// Verificar vehiculo disponible
		Vehiculo vehiculo = vehiculoServicio.obtenerVehiculoPorId(nuevaVenta.vehiculoId);
		if(!vehiculo.reparado)
			throw invalid_argument("El vehiculo seleccionado no esta listo para la venta.");

		nuevaVenta.precioAdquisicion = vehiculo.precioAdquisicion;

		// Obtener gastos de reparacion del vehiculo (suma recursiva)
		list<GastoReparacion> gastos = gastoServicio.obtenerGastosPorVehiculo(nuevaVenta.vehiculoId);
		nuevaVenta.totalGastos = GastoReparacionServicio::calcularTotalGastos(gastos.cbegin(), gastos.cend());
		IO::imprimirLinea("Costo total de reparacion: $" + to_string(nuevaVenta.totalGastos));
		IO::imprimirLinea("Precio de adquisicion:     $" + to_string(nuevaVenta.precioAdquisicion));
		IO::imprimirLinea("Costo total del vehiculo:  $" + to_string(nuevaVenta.precioAdquisicion + nuevaVenta.totalGastos));

		nuevaVenta.clienteId = stoi(IO::pedirDato("Ingrese el ID del cliente comprador: "));
		// Verificar que el cliente existe
		Cliente cliente = clienteServicio.obtenerClientePorId(nuevaVenta.clienteId);
		IO::imprimirLinea("Cliente: " + cliente.nombre, TEXTO_EXITO);

		nuevaVenta.precioVenta = stod(IO::pedirDato("Ingrese el precio de venta final: $"));

		Venta ventaRegistrada = ventaServicio.registrarVenta(nuevaVenta);
		IO::imprimirLinea("Venta registrada con ID: " + to_string(ventaRegistrada.id), TEXTO_EXITO);
		IO::imprimirLinea("Utilidad generada: $" + to_string(ventaRegistrada.utilidad),
			ventaRegistrada.utilidad >= 0 ? TEXTO_EXITO : TEXTO_ERROR);
	}
	catch(const exception& e)
	{
		IO::imprimirLinea("Error: " + string(e.what()), TEXTO_ERROR);
	}
	IO::pedirDato("\nPresiona ENTER para volver...");
}
