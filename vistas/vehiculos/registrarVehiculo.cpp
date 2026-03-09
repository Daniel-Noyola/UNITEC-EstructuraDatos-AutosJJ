#include "../../AutosJJ.h"
#include "../../servicios/VehiculoServicio.h"

void Vista::registrarVehiculo()
{
	VehiculoServicio vehiculoServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Registrar Vehiculo ===");
	try
	{
		int anio = stoi(IO::pedirDato("Ingrese el anio del vehiculo: "));
		string descripcion = IO::pedirDato("Ingrese la descripcion del vehiculo: ");
		string marca = IO::pedirDato("Ingrese la marca del vehiculo: ");
		string modelo = IO::pedirDato("Ingrese el modelo del vehiculo: ");
		string color = IO::pedirDato("Ingrese el color del vehiculo: ");
		string version = IO::pedirDato("Ingrese la version del vehiculo: ");
		string kilometraje = IO::pedirDato("Ingrese el kilometraje del vehiculo: ");
		string estado = IO::pedirDato("Ingrese el estado del vehiculo (nuevo/usado): ");
		string aseguradora = IO::pedirDato("Ingrese la aseguradora del vehiculo: ");
		string precioCliente = IO::pedirDato("Ingrese el precio para el cliente: ");
		Vehiculo nuevoVehiculo = vehiculoServicio.agregarVehiculo(anio, descripcion, marca, modelo, color, version, kilometraje, estado, aseguradora, precioCliente);
		IO::imprimirLinea("Vehiculo registrado exitosamente con ID: " + to_string(nuevoVehiculo.id), TEXTO_EXITO);
	}
	catch (const exception& e)
	{
		IO::imprimirLinea("Error al registrar el vehiculo: " + string(e.what()), TEXTO_ERROR);
	}
	string opcion = IO::pedirDato("\nDeseas registrar otro vehiculo? (s/n): ");
	if (opcion == "s" || opcion == "S")
	{
		registrarVehiculo();
		return;
	}
}