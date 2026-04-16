#include "../../AutosJJ.h"
#include "../../servicios/VehiculoServicio.h"

// Busca vehiculos por marca y muestra sus detalles.
void Vista::buscarVehiculoMarca()
{
	VehiculoServicio vehiculoServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Buscar Vehiculo por Marca ===");
	try
	{
		string marca = IO::pedirDato("Ingrese la marca del vehiculo: ");
		list<Vehiculo> vehiculos = vehiculoServicio.obtenerVehiculosPorMarca(marca);
		if(vehiculos.empty())
		{
			IO::imprimirLinea("No se encontraron vehiculos con la marca: " + marca, TEXTO_ERROR);
		}
		else
		{
			IO::imprimirLinea(to_string(vehiculos.size()) + " vehiculo(s) encontrado(s) con marca: " + marca, TEXTO_EXITO);
			IO::imprimirLinea("");
			for(const Vehiculo& v : vehiculos)
			{
				string reparado = v.reparado ? "LISTO PARA VENTA" : "EN TALLER";
				IO::imprimirLinea("--- [ Vehiculo #" + to_string(v.id) + " ] ---", TEXTO_BOLD);
				IO::imprimirLinea("  Marca         : " + v.marca + " " + v.modelo + " " + to_string(v.anio));
				IO::imprimirLinea("  Color         : " + v.color + "  |  Version: " + v.version);
				IO::imprimirLinea("  Kilometraje   : " + v.kilometraje + " km");
				IO::imprimirLinea("  Descripcion   : " + v.descripcion);
				IO::imprimirLinea("  Precio Adq.   : $" + to_string(v.precioAdquisicion));
				IO::imprimirLinea("  Reparacion    : " + reparado, v.reparado ? TEXTO_EXITO : TEXTO_ADVERTENCIA);
				IO::imprimirLinea("");
			}
		}
	}
	catch(const exception& e)
	{
		IO::imprimirLinea("Error: " + string(e.what()), TEXTO_ERROR);
	}
	string op = IO::pedirDato("\nDeseas buscar otra marca? (s/n): ");
	if(op == "s" || op == "S") { buscarVehiculoMarca(); return; }
}