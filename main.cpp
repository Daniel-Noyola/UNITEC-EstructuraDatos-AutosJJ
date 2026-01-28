#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

// ---- Tipografía ----
const string TEXTO_BOLD = "\033[1m";
const string TEXTO_ITALIC = "\033[3m";
const string RESET_STYLE = "\033[0m";

// ---- Colores ----
const string COLOR_FONDO = "\033[48;2;0;112;192m";
const string TEXTO_BLANCO = "\033[97m";
const string COLORES_BASE = COLOR_FONDO + TEXTO_BLANCO;

const int ASCII_ENTER = 13;
const int ASCII_BACKSPACE = 8;

// ---- Login ----
const string LOGIN_USER = "admin";
const string LOGIN_PASSWORD = "123456";

// ---- Utilidades ----
void mostrarMenu(string texto, vector<string> opciones);
void imprimirLinea(string texto, string estilos = "", bool saltoLinea = true);
string pedirDato(string texto, bool esSecreto = false);

// ---- Vistas
void cargarVistaInicio();
void cargarVistaLogin();
void cargarVistaDashboard();

int main()
{
	// Configura los colores de la terminal
	cout << COLORES_BASE << "\033[2J\033[H";

	cargarVistaInicio();
	return 0;
}

// ------- Vistas --------
void cargarVistaInicio()
{
	system("cls");

	imprimirLinea("          Autos J&J");
	imprimirLinea("");
	imprimirLinea("Auditor:", TEXTO_ITALIC, false);
	imprimirLinea("Mtra. Noemi Torrez Rubio");

	imprimirLinea("Especialistas:", TEXTO_ITALIC);
	imprimirLinea("  - Jesus Joan Molina Gutierrez");
	imprimirLinea("  - Jesus Erick Reyes Sanchez");
	imprimirLinea("  - Daniel Alberto Noyola Monroy");
	imprimirLinea("");

	imprimirLinea("Vision de la empresa:");
	imprimirLinea("Ser la empresa de reparacion de autos siniestrados");
	imprimirLinea("");

	imprimirLinea("Presiona ENTER para continuar...");
	imprimirLinea("");
	cin.get();

	cargarVistaLogin();
}

void cargarVistaLogin()
{
	bool credencialesCorrectas = false;
	string mensaje = "";

	while (!credencialesCorrectas)
	{
		system("cls");

		imprimirLinea("Ingreso al sistema");
		imprimirLinea("");

		if (!mensaje.empty())
			imprimirLinea(mensaje, TEXTO_ITALIC);

		string usuario = pedirDato("Ingresa el usuario: ");
		string password = pedirDato("Ingresa la contrasena: ", true);

		if (usuario != LOGIN_USER || password != LOGIN_PASSWORD)
			mensaje = "Credenciales incorrectas, intenta de nuevo";
		else
			credencialesCorrectas = true;
	}

	cargarVistaDashboard();
}

void cargarVistaDashboard()
{
	vector<string> opciones = {
		"Clientes",
		"Ventas",
		"Compras",
		"Proveedores",
		"Empleados",
		"Inventario",
		"Salir"};

	system("cls");
	imprimirLinea("        Dashboard");
	mostrarMenu("Opciones disponibles", opciones);

	int opcion = stoi(pedirDato("Ingresa el numero de la opcion: "));
}

// ---- Utilidades ----
void imprimirLinea(string texto, string estilos, bool saltoLinea)
{
	cout << estilos << " " << texto << RESET_STYLE << COLORES_BASE;
	if (saltoLinea)
		cout << endl;
}

/*Imprime un menu con las opciones pasadas como parametro*/
void mostrarMenu(string texto, vector<string> opciones)
{
	imprimirLinea(texto);

	// Imprime una linea por cada opcion del menu
	for (int i = 0; i < opciones.size(); i++)
	{
		string opcion = to_string(i + 1) + ". " + opciones[i];
		imprimirLinea(opcion);
	}
}

string pedirDato(string texto, bool esSecreto)
{
	string dato = "";
	imprimirLinea(texto, "", false);

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