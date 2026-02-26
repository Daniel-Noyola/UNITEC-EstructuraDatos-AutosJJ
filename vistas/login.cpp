#pragma once
#include "../AutosJJ.h"

Pantalla Vista::login()
{
	bool credencialesCorrectas = false;
	string mensaje = "";

	//* Ciclo de validacion de credenciales
	do
	{
		IO::limpiarPantalla();
		IO::imprimirLinea("     Ingreso al sistema");
		IO::imprimirLinea("");

		if (!mensaje.empty())
			IO::imprimirLinea(mensaje, TEXTO_ADVERTENCIA);
		else
			IO::imprimirLinea("");

		string usuario = IO::pedirDato("Ingresa el usuario: ");
		string password = IO::pedirDato("Ingresa la contrasena: ", true);

		if (usuario != LOGIN_USER || password != LOGIN_PASSWORD)
			mensaje = "Credenciales incorrectas, intenta de nuevo";
		else
			credencialesCorrectas = true;
	} while (!credencialesCorrectas);

	return Pantalla::Dashboard;
}