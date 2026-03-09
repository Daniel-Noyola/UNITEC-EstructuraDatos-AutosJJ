#include "../../AutosJJ.h"
#include "../../servicios/VehiculoServicio.h"

void Vista::buscarVehiculoId()
{
	VehiculoServicio vehiculoServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Buscar Vehiculo por ID ===");
	try
	{
		int id = stoi(IO::pedirDato("Ingrese el ID del vehiculo: "));
		Vehiculo vehiculoEncontrado = vehiculoServicio.obtenerVehiculoPorId(id);
		IO::imprimirLinea("Vehiculo encontrado con ID: " + to_string(vehiculoEncontrado.id), TEXTO_EXITO);
		IO::imprimirLinea("Anio: " + to_string(vehiculoEncontrado.anio) + ", Descripcion: " + vehiculoEncontrado.descripcion + ", Marca: " + vehiculoEncontrado.marca + ", Modelo: " + vehiculoEncontrado.modelo + ", Color: " + vehiculoEncontrado.color + ", Version: " + vehiculoEncontrado.version + ", Kilometraje: " + vehiculoEncontrado.kilometraje + ", Estado: " + vehiculoEncontrado.estado + ", Aseguradora: " + vehiculoEncontrado.aseguradora + ", Precio Cliente: " + to_string(vehiculoEncontrado.precioCliente));
	}
	catch (const exception& e)
	{
		IO::imprimirLinea("Error al buscar el vehiculo: " + string(e.what()), TEXTO_ERROR);
	}
	string opcion = IO::pedirDato("\nDeseas buscar otro vehiculo por ID? (s/n): ");
	if (opcion == "s" || opcion == "S")
	{
		buscarVehiculoId();
		return;
	}
}