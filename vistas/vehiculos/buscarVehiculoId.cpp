#include "../../AutosJJ.h"
#include "../../servicios/VehiculoServicio.h"

// Busca un vehiculo por su ID y muestra sus detalles.
void Vista::buscarVehiculoId()
{
	VehiculoServicio vehiculoServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Buscar Vehiculo por ID ===");
	try
	{
		int id = stoi(IO::pedirDato("Ingrese el ID del vehiculo: "));
		Vehiculo v = vehiculoServicio.obtenerVehiculoPorId(id);
		string estado = v.reparado ? "LISTO PARA VENTA" : "EN TALLER";
		string estiloEstado = v.reparado ? TEXTO_EXITO : TEXTO_ADVERTENCIA;
		IO::imprimirLinea("");
		IO::imprimirLinea("--- [ Vehiculo #" + to_string(v.id) + " ] ---", TEXTO_EXITO);
		IO::imprimirLinea("  Marca         : " + v.marca + " " + v.modelo + " " + to_string(v.anio));
		IO::imprimirLinea("  Color         : " + v.color + "  |  Version: " + v.version);
		IO::imprimirLinea("  Kilometraje   : " + v.kilometraje + " km");
		IO::imprimirLinea("  Nivel de danio: " + v.estado);
		IO::imprimirLinea("  Aseguradora   : " + v.aseguradora);
		IO::imprimirLinea("  Descripcion   : " + v.descripcion);
		IO::imprimirLinea("  Precio Adq.   : $" + to_string(v.precioAdquisicion));
		IO::imprimirLinea("  Precio Cliente: $" + to_string(v.precioCliente));
		IO::imprimirLinea("  Reparacion    : " + estado, estiloEstado);
	}
	catch (const exception& e)
	{
		IO::imprimirLinea("Error: " + string(e.what()), TEXTO_ERROR);
	}
	string op = IO::pedirDato("\nDeseas buscar otro vehiculo? (s/n): ");
	if (op == "s" || op == "S") { buscarVehiculoId(); return; }
}