#include "../../AutosJJ.h"
#include "../../servicios/ClienteServicio.h"
#include "../../utilidades/utils.h"

void Vista::registrarCliente()
{
	ClienteServicio clienteServicio;
	IO::limpiarPantalla();
	IO::imprimirLinea("=== Registrar Cliente ===");
	try
	{
		/*Crea un nuevo cliente*/
		Cliente nuevoCliente;
		nuevoCliente.nombre = IO::pedirDato("Ingresa el nombre: ");
		nuevoCliente.direccion = IO::pedirDato("Ingresa la direccion: ");
		nuevoCliente.telefono = IO::pedirDato("Ingresa su numero de telefono: ");
		nuevoCliente.correo = IO::pedirDato("Ingresa su email: ");

		int anioRegistro = stoi(IO::pedirDato("Ingresa el anio en que se registro como cliente: "));

		/* -- Aqui se aplica la funcion que utiliza punteros para modificar el valor de la variable -- */
		int *tiempoClientePtr = &nuevoCliente.tiempoComoCliente;
		calcularDiferenciaDeTiempo(anioRegistro, tiempoClientePtr);

		/*Agrega el cliente a la base de datos (CSV)*/
		Cliente clienteRegistrado = clienteServicio.agregarCliente(nuevoCliente);
		IO::imprimirLinea("Cliente registrado exitosamente con ID: " + to_string(clienteRegistrado.id), TEXTO_EXITO);
	}
	catch (const exception& e)
	{
		IO::imprimirLinea("Error al registrar el cliente: " + string(e.what()), TEXTO_ERROR);
	}

	/*Aplicacion alterna de recursion*/
	string opcion = IO::pedirDato("\nDeseas registrar otro cliente? (s/N): ");
	if (opcion == "s" || opcion == "S")
	{
		registrarCliente();
		return;
	}
}