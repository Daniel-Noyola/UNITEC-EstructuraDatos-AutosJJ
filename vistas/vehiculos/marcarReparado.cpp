#include "../../AutosJJ.h"
#include "../../servicios/VehiculoServicio.h"

void Vista::marcarReparado()
{
	VehiculoServicio vehiculoServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Finalizar Reparacion de Vehiculo ===");
	try
	{
		int id = stoi(IO::pedirDato("Ingrese el ID del vehiculo reparado: "));
		Vehiculo vehiculo = vehiculoServicio.marcarComoReparado(id);
		IO::imprimirLinea("Vehiculo ID " + to_string(vehiculo.id) + " (" + vehiculo.marca + " " + vehiculo.modelo + ") marcado como LISTO PARA VENTA.", TEXTO_EXITO);
	}
	catch(const exception& e)
	{
		IO::imprimirLinea("Error: " + string(e.what()), TEXTO_ERROR);
	}
	string opcion = IO::pedirDato("\nDeseas marcar otro vehiculo como reparado? (s/n): ");
	if(opcion == "s" || opcion == "S")
	{
		marcarReparado();
		return;
	}
}
