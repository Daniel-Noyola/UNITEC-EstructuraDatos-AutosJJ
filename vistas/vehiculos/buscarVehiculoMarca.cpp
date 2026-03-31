#include "../../AutosJJ.h"
#include "../../servicios/VehiculoServicio.h"

void Vista::buscarVehiculoMarca()
{
	VehiculoServicio vehiculoServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Buscar Vehiculo por Marca ===");
	string marca = IO::pedirDato("Ingrese la marca del vehiculo: ");
	list<Vehiculo> vehiculosEncontrados = vehiculoServicio.obtenerVehiculosPorMarca(marca);
	if (vehiculosEncontrados.empty())
	{
		IO::imprimirLinea("No se encontraron vehiculos con la marca: " + marca, TEXTO_ERROR);
	}
	else
	{
		IO::imprimirLinea("Vehiculos encontrados con la marca: " + marca, TEXTO_EXITO);
		for (const auto& vehiculo : vehiculosEncontrados)
		{
			IO::imprimirLinea("ID: " + to_string(vehiculo.id) + ", Anio: " + to_string(vehiculo.anio) + ", Descripcion: " + vehiculo.descripcion + ", Modelo: " + vehiculo.modelo + ", Color: " + vehiculo.color + ", Version: " + vehiculo.version + ", Kilometraje: " + vehiculo.kilometraje + ", Estado: " + vehiculo.estado + ", Aseguradora: " + vehiculo.aseguradora + ", Precio Cliente: " + to_string(vehiculo.precioCliente));
		}
	}
	string opcion = IO::pedirDato("\nDeseas buscar otro vehiculo por marca? (s/n): ");
	if (opcion == "s" || opcion == "S")
	{
		buscarVehiculoMarca();
		return;
	}
}