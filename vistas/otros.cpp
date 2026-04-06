#include "../AutosJJ.h"

// Funcionalidades pendientes / no requeridas por el actionplan

void Vista::compras()
{
	IO::imprimirLinea("Usa el modulo Vehiculos / Compras para registrar nuevos vehiculos.", TEXTO_ADVERTENCIA);
	IO::pedirDato("\nPresiona ENTER para volver...");
}

void Vista::empleados()
{
	IO::imprimirLinea("Funcionalidad de Empleados no implementada.", TEXTO_ADVERTENCIA);
	IO::pedirDato("\nPresiona ENTER para volver...");
}
