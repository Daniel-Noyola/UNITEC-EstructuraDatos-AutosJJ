#pragma once
#include "../AutosJJ.h"

Pantalla Vista::inicio()
{
	IO::imprimirLinea("          Autos J&J");
	IO::imprimirLinea("");
	IO::imprimirLinea("Auditor:", TEXTO_ITALIC, false);
	IO::imprimirLinea("Mtra. Noemi Torrez Rubio");

	IO::imprimirLinea("Especialistas:", TEXTO_ITALIC);
	IO::imprimirLinea("  - Jesus Joan Molina Gutierrez");
	IO::imprimirLinea("  - Jesus Erick Reyes Sanchez");
	IO::imprimirLinea("  - Daniel Alberto Noyola Monroy");
	IO::imprimirLinea("");

	IO::imprimirLinea("Vision de la empresa:", TEXTO_ITALIC);
	IO::imprimirLinea("Consolidarnos como el referente indiscutible en la Zona Metropolitana de Mexico, transformando el mercado de autos siniestrados a traves de la transparencia, la excelencia tecnica y la seguridad garantizada en cada unidad.");
	IO::imprimirLinea("");

	IO::imprimirLinea("Presiona ENTER para continuar...", "", false);
	cin.get();

	return Pantalla::Login;
}