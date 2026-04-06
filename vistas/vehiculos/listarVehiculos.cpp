#include "../../AutosJJ.h"
#include "../../servicios/VehiculoServicio.h"

void Vista::listarVehiculos()
{
	VehiculoServicio vehiculoServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Lista de Vehiculos ===");
	try
	{
		list<Vehiculo> vehiculos = vehiculoServicio.obtenerVehiculos();
		if(vehiculos.empty())
		{
			IO::imprimirLinea("No hay vehiculos registrados.", TEXTO_ADVERTENCIA);
		}
		else
		{
			IO::imprimirLinea(to_string(vehiculos.size()) + " vehiculo(s) registrado(s).");
			IO::imprimirLinea("");
			for(const Vehiculo& v : vehiculos)
			{
				string estado = v.reparado ? "LISTO PARA VENTA" : "EN TALLER";
				string estiloEstado = v.reparado ? TEXTO_EXITO : TEXTO_ADVERTENCIA;
				IO::imprimirLinea("--- [ Vehiculo #" + to_string(v.id) + " ] ---", TEXTO_ITALIC);
				IO::imprimirLinea("  Marca         : " + v.marca + " " + v.modelo + " " + to_string(v.anio));
				IO::imprimirLinea("  Color         : " + v.color + "  |  Version: " + v.version);
				IO::imprimirLinea("  Kilometraje   : " + v.kilometraje + " km");
				IO::imprimirLinea("  Estado fisico : " + v.estado);
				IO::imprimirLinea("  Aseguradora   : " + v.aseguradora);
				IO::imprimirLinea("  Descripcion   : " + v.descripcion);
				IO::imprimirLinea("  Precio Adq.   : $" + to_string(v.precioAdquisicion));
				IO::imprimirLinea("  Precio Cliente: $" + to_string(v.precioCliente));
				IO::imprimirLinea("  Reparacion    : " + estado, estiloEstado);
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
