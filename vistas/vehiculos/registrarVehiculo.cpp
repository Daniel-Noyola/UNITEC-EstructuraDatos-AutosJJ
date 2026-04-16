#include "../../AutosJJ.h"
#include "../../servicios/VehiculoServicio.h"

// Registra un nuevo vehiculo (compra) en el sistema.
void Vista::registrarVehiculo()
{
	VehiculoServicio vehiculoServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Registrar Vehiculo (Compra) ===");
	try
	{
		Vehiculo nuevoVehiculo;
		nuevoVehiculo.anio           = stoi(IO::pedirDato("Ingrese el anio del vehiculo: "));
		nuevoVehiculo.descripcion    = IO::pedirDato("Ingrese la descripcion del vehiculo: ");
		nuevoVehiculo.marca          = IO::pedirDato("Ingrese la marca del vehiculo: ");
		nuevoVehiculo.modelo         = IO::pedirDato("Ingrese el modelo del vehiculo: ");
		nuevoVehiculo.color          = IO::pedirDato("Ingrese el color del vehiculo: ");
		nuevoVehiculo.version        = IO::pedirDato("Ingrese la version del vehiculo: ");
		nuevoVehiculo.kilometraje    = IO::pedirDato("Ingrese el kilometraje del vehiculo: ");
		nuevoVehiculo.estado         = IO::pedirDato("Nivel de danio del siniestro (Leve/Moderado/Severo/Total): ");
		nuevoVehiculo.aseguradora    = IO::pedirDato("Ingrese la aseguradora del vehiculo: ");
		nuevoVehiculo.precioAdquisicion = stod(IO::pedirDato("Ingrese el precio de compra (adquisicion): $"));
		nuevoVehiculo.precioCliente  = stof(IO::pedirDato("Ingrese el precio sugerido para el cliente: $"));

		Vehiculo vehiculoRegistrado = vehiculoServicio.agregarVehiculo(nuevoVehiculo);
		IO::imprimirLinea("Vehiculo registrado exitosamente con ID: " + to_string(vehiculoRegistrado.id), TEXTO_EXITO);
		IO::imprimirLinea("Estado: En taller (pendiente de reparacion)", TEXTO_ADVERTENCIA);
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