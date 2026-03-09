#include "../../AutosJJ.h"
#include "../../servicios/ClienteServicio.h"

void Vista::registrarCliente()
{
	ClienteServicio clienteServicio;
	Cliente nuevoCliente;
	string nombre, direccion, telefono, correo, fechaRegistro;
	
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Registrar Cliente ===");
	nombre = IO::pedirDato("Ingresa el nombre: ");
	direccion = IO::pedirDato("Ingresa la direccion: ");
	telefono = IO::pedirDato("Ingresa su numero de telefono: ");
	correo = IO::pedirDato("Ingresa su email: ");
	fechaRegistro = IO::pedirDato("Ingresa el anio de registro: ");

	try
	{
		nuevoCliente = clienteServicio.agregarCliente(nombre, direccion, telefono, correo, fechaRegistro);
		IO::imprimirLinea("Cliente registrado exitosamente con ID: " + to_string(nuevoCliente.id), TEXTO_EXITO);
	}
	catch (const exception& e)
	{
		IO::imprimirLinea("Error al registrar el cliente: " + string(e.what()), TEXTO_ERROR);
	}


	string opcion = IO::pedirDato("Deseas registrar otro cliente? (s/n): ");
	if (opcion == "s" || opcion == "S")
	{
		registrarCliente();
		return;
	}
}