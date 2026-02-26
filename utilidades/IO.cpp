#include "IO.h"
#include <iostream>
#include <conio.h>
#include "../includes/Constantes.h"

using namespace std;

void IO::imprimirLinea(string texto, string estilos, bool saltoLinea)
{
	cout << estilos << " " << texto << RESET_STYLE << COLORES_BASE;
	if (saltoLinea)
		cout << endl;
}

void IO::imprimirMenu(string texto, vector<string> opciones)
{
	IO::imprimirLinea(texto);

	// Imprime una linea por cada opcion del menu
	for (int i = 0; i < opciones.size(); i++)
	{
		string opcion = to_string(i + 1) + ". " + opciones[i];
		IO::imprimirLinea(opcion);
	}
}

string IO::pedirDato(string texto, bool esSecreto)
{
	string dato = "";
	imprimirLinea(texto, "", false);

	//* Si el dato es secreto, solo se escriben asteriscos cuando el usaurio escribe
	if (!esSecreto)
		getline(cin, dato);
	else
	{
		char caracter;
		while (true)
		{
			caracter = _getch();

			if (caracter == ASCII_ENTER)
			{
				cout << endl;
				break;
			}
			else if (caracter == ASCII_BACKSPACE)
			{
				if (dato.length() > 0)
				{
					dato.pop_back();
					cout << "\b \b";
				}
			}
			else
			{
				dato += caracter;
				cout << "*";
			}
		}
	}
	return dato;
}

void IO::limpiarPantalla()
{
	cout << LIMPIAR_PANTALLA;
}
