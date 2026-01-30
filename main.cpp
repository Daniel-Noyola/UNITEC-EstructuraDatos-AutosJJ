#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

//& ---- Tipografía ----
const string TEXTO_BOLD = "\033[1m";
const string TEXTO_ITALIC = "\033[3m";
const string RESET_STYLE = "\033[0m";

//& ---- Colores ----
const string COLOR_FONDO = "\033[48;2;0;112;192m";
const string TEXTO_BLANCO = "\033[97m";
const string TEXTO_NARANJA = "\033[38;5;214m";

const string TEXTO_ADVERTENCIA = TEXTO_ITALIC + TEXTO_NARANJA;
const string COLORES_BASE = COLOR_FONDO + TEXTO_BLANCO;

const int ASCII_ENTER = 13;
const int ASCII_BACKSPACE = 8;

//& ---- Login ----
const string LOGIN_USER = "admin";
const string LOGIN_PASSWORD = "123456";

//& ---- Utilidades ----
void mostrarMenu(string texto, vector<string> opciones);
void imprimirLinea(string texto, string estilos = "", bool saltoLinea = true);
string pedirDato(string texto, bool esSecreto = false);

//& ---- Vistas
void cargarVistaInicio();
void cargarVistaLogin();
void cargarVistaDashboard();
//& ---- Vistas Menu Principal ----
void cargarVistaClientes();
void cargarVistaVentas();
void cargarVistaCompras();
void cargarVistaProveedores();
void cargarVistaEmpleados();
void cargarVistaInventario();

int main()
{
	// Configura los colores de la terminal
	cout << COLORES_BASE << "\033[2J\033[H";

	cargarVistaInicio();
	return 0;
}

//? ------- Vistas --------
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

	imprimirLinea("Vision de la empresa:", TEXTO_ITALIC);
	imprimirLinea("Consolidarnos como el referente indiscutible en la Zona Metropolitana de Mexico, transformando el mercado de autos siniestrados a traves de la transparencia, la excelencia tecnica y la seguridad garantizada en cada unidad.");
	imprimirLinea("");

	imprimirLinea("Presiona ENTER para continuar...", "", false);
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

		imprimirLinea("     Ingreso al sistema");
		imprimirLinea("");

		!mensaje.empty()
			? imprimirLinea(mensaje, TEXTO_ADVERTENCIA)
			: imprimirLinea("");

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
	//* Opciones del menu principal
	vector<string> opciones = {
		"Clientes",
		"Ventas",
		"Compras",
		"Proveedores",
		"Empleados",
		"Inventario",
		"Salir"};

	int opcion;
	string mensaje;
	while (true)
	{
		system("cls");
		imprimirLinea("        Dashboard");
		mensaje.empty()
			? imprimirLinea("")
			: imprimirLinea(mensaje, TEXTO_ADVERTENCIA);

		mostrarMenu("Opciones disponibles", opciones);
		try
		{
			opcion = stoi(pedirDato("Ingresa la opcion deseada: "));
			if (opcion <= 0 || opcion > opciones.size())
				throw invalid_argument("");

			break;
		}
		catch (const std::invalid_argument &e)
		{
			mensaje = "Opcion no valida\n";
			continue;
		}
	}

	//* Navega a la vista seleccionada
	switch (opcion)
	{
	case 1:
		cargarVistaClientes();
		break;
	case 2:
		cargarVistaVentas();
		break;
	case 3:
		cargarVistaCompras();
		break;
	case 4:
		cargarVistaProveedores();
		break;
	case 5:
		cargarVistaEmpleados();
		break;
	case 6:
		cargarVistaInventario();
		break;
	case 7:
		system("cls");
		imprimirLinea("Saliendo del sistema... \n Adios!!");
		break;
	default:
		imprimirLinea("Opcion no encontrada");
		break;
	}
}

void cargarVistaClientes()
{
	system("cls");
	imprimirLinea("        Vista Clientes");
}

void cargarVistaVentas()
{
	system("cls");
	imprimirLinea("        Vista Ventas");
}

void cargarVistaCompras()
{
	system("cls");
	imprimirLinea("        Vista Compras");
}

void cargarVistaProveedores()
{
	system("cls");
	imprimirLinea("        Vista Proveedores");
}

void cargarVistaEmpleados()
{
	system("cls");
	imprimirLinea("        Vista Empleados");
}

void cargarVistaInventario()
{
	system("cls");
	imprimirLinea("        Vista Inventario");
}

//? ---- Utilidades ----
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