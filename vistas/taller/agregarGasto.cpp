#include "../../AutosJJ.h"
#include "../../servicios/GastoReparacionServicio.h"
#include "../../servicios/VehiculoServicio.h"

void Vista::agregarGasto()
{
	GastoReparacionServicio gastoServicio;
	VehiculoServicio vehiculoServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Agregar Gasto de Reparacion ===");
	try
	{
		int vehiculoId = stoi(IO::pedirDato("Ingrese el ID del vehiculo: "));

		// Verificar que el vehiculo existe
		Vehiculo vehiculo = vehiculoServicio.obtenerVehiculoPorId(vehiculoId);
		IO::imprimirLinea("Vehiculo: " + vehiculo.marca + " " + vehiculo.modelo + " (" + to_string(vehiculo.anio) + ")", TEXTO_EXITO);

		GastoReparacion nuevoGasto;
		nuevoGasto.vehiculoId  = vehiculoId;
		nuevoGasto.descripcion = IO::pedirDato("Ingrese la descripcion del gasto (ej. Hojalateria, Pintura): ");
		nuevoGasto.monto       = stod(IO::pedirDato("Ingrese el monto del gasto: $"));

		GastoReparacion gastoRegistrado = gastoServicio.agregarGasto(nuevoGasto);
		IO::imprimirLinea("Gasto registrado exitosamente con ID: " + to_string(gastoRegistrado.id), TEXTO_EXITO);
	}
	catch(const exception& e)
	{
		IO::imprimirLinea("Error: " + string(e.what()), TEXTO_ERROR);
	}
	string opcion = IO::pedirDato("\nDeseas agregar otro gasto? (s/n): ");
	if(opcion == "s" || opcion == "S")
	{
		agregarGasto();
		return;
	}
}
