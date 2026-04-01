#include "../../AutosJJ.h"
#include "../../servicios/VehiculoServicio.h"

void Vista::registrarVehiculo()
{
	VehiculoServicio vehiculoServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Registrar Vehiculo ===");
	try
	{
		Vehiculo nuevoVehiculo;
		nuevoVehiculo.anio = stoi(IO::pedirDato("Ingrese el anio del vehiculo: "));
		nuevoVehiculo.descripcion = IO::pedirDato("Ingrese la descripcion del vehiculo: ");
		nuevoVehiculo.marca = IO::pedirDato("Ingrese la marca del vehiculo: ");
		nuevoVehiculo.modelo = IO::pedirDato("Ingrese el modelo del vehiculo: ");
		nuevoVehiculo.color = IO::pedirDato("Ingrese el color del vehiculo: ");
		nuevoVehiculo.version = IO::pedirDato("Ingrese la version del vehiculo: ");
		nuevoVehiculo.kilometraje = IO::pedirDato("Ingrese el kilometraje del vehiculo: ");
		nuevoVehiculo.estado = IO::pedirDato("Ingrese el estado del vehiculo (nuevo/usado): ");
		nuevoVehiculo.aseguradora = IO::pedirDato("Ingrese la aseguradora del vehiculo: ");
		nuevoVehiculo.precioCliente = stof(IO::pedirDato("Ingrese el precio para el cliente: "));
		
		Vehiculo vehiculoRegistrado = vehiculoServicio.agregarVehiculo(nuevoVehiculo);
		IO::imprimirLinea("Vehiculo registrado exitosamente con ID: " + to_string(vehiculoRegistrado.id), TEXTO_EXITO);
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