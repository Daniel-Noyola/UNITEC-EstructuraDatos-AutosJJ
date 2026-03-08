#include "AutosJJ.h"
#include "./includes/PantallaEnum.h"

using namespace std;

int main()
{
	//* Configuración incial de la consola
	cout << COLORES_BASE << LIMPIAR_PANTALLA;

	
	Pantalla pantalla = Pantalla::Inicio();

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
