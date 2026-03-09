#include "../../AutosJJ.h"
#include "../../servicios/ClienteServicio.h"

void Vista::registrarCliente()
{
	ClienteServicio clienteServicio;
	string nombre, direccion, telefono, correo, fechaRegistro;
	
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Registrar Cliente ===");
	nombre = IO::pedirDato("Ingresa el nombre: ");
	direccion = IO::pedirDato("Ingresa la direccion: ");
	telefono = IO::pedirDato("Ingresa su numero de telefono: ");
	correo = IO::pedirDato("Ingresa su email: ");
	fechaRegistro = IO::pedirDato("Ingresa el anio de registro: ");

	Cliente nuevoCliente = clienteServicio.agregarCliente(nombre, direccion, telefono, correo, fechaRegistro);

	if (!nuevoCliente.nombre.empty())
	{
		IO::imprimirLinea("Cliente registrado exitosamente con ID: " + to_string(nuevoCliente.id), TEXTO_EXITO);
	}
	else
	{
		IO::imprimirLinea("Error al registrar el cliente. Por favor, intenta nuevamente.", TEXTO_ERROR);
	}

	string opcion = IO::pedirDato("Deseas registrar otro cliente? (s/n): ");
	if (opcion == "s" || opcion == "S")
	{
		registrarCliente();
		return;
	}
}