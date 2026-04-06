#include "AutosJJ.h"
#include "./includes/PantallaEnum.h"
#include "./utilidades/Utils.h"

using namespace std;

int main()
{
	//* Configuracion inicial de la consola
	cout << COLORES_BASE << LIMPIAR_PANTALLA;

	//* Cargar datos de prueba si las tablas estan vacias
	cargarDatosDePrueba();

	Pantalla pantalla = Pantalla::Inicio;

	// Logica para mostrar la sección correspondiente
	while (pantalla != Pantalla::Salir)
	{
		IO::limpiarPantalla();
		switch (pantalla)
		{
			case Pantalla::Inicio:
				pantalla = Vista::inicio();
				break;
			case Pantalla::Login:
				pantalla = Vista::login();
				break;
			case Pantalla::Dashboard:
				pantalla = Vista::dashboard();
				break;
		}
	}

	return 0;
}
