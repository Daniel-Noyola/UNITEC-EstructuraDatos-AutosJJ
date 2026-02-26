#include "../../AutosJJ.h"

void Vista::listarClientes()
{
	IO::imprimirLinea("=== Clientes Registrados ===");
	IO::imprimirLinea("Presiona ENTER para volver al dashboard...", "", false);
	cin.get();
}