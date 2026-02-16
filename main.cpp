#include <iostream>
#include <vector>
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
struct IO
{
	static void mostrarMenu(string texto, vector<string> opciones);
	static void imprimirLinea(string texto, string estilos = "", bool saltoLinea = true);
	static string pedirDato(string texto, bool esSecreto = false);
};
void calcularDiferenciaDeTiempo(int fechaAlta, int *diferenciaTiempo);

//& ---- Vistas ----
struct Vista
{
	static void inicio();
	static void login();
	static void dashboard();
	static void clientes();
	static void ventas();
	static void compras();
	static void proveedores();
	static void empleados();
	static void inventario();
};

//& ---- Structs ----
struct Cliente
{
	int id,
		tiempoComoCliente;
	string nombre,
		direccion,
		telefono,
		correo;
	static std::vector<Cliente> clientes;

	static void listarClientes();
	static void agregarCliente();
};

struct Proveedor
{
	int id,
		tiempoComoProveedor;
	string nombre,
		direccion,
		telefono,
		correo;
	static std::vector<Proveedor> proveedores;

	static void listarProveedores();
	static void agregarProveedor();
};
struct Vehiculo
{
	int id;
	string marca;
	string modelo;
	string color;
	string anio;
	string version;
	string kilometraje;
	string estado;
	string aseguradora;
	string precioCliente;
};

struct CostosVehiculo
{
	int idVehiculo,
		precioCompra,
		grua,
		refacciones,
		hojalateria,
		manoDeObra,
		otrosGastos,
		costoTotal;
};

std::vector<Cliente> Cliente::clientes = {
	{1, 5, "Juan Perez", "Av. Reforma 123, CDMX", "5512345678", "juan.perez@email.com"},
	{2, 3, "Maria Gonzalez", "Calle 5 de Mayo 45, Puebla", "2229876543", "maria.gonzalez@email.com"},
	{3, 8, "Carlos Lopez", "Blvd. Kukulcan Km 12, Cancun", "9981122334", "carlos.lopez@email.com"},
	{4, 2, "Ana Martinez", "Av. Vallarta 2440, Guadalajara", "3334455667", "ana.martinez@email.com"},
	{5, 10, "Pedro Sanchez", "Calle Madero 101, Monterrey", "8189988776", "pedro.sanchez@email.com"}};

std::vector<Proveedor> Proveedor::proveedores = {
	{1, 10, "Refacciones del Norte", "Norte 45, Monterrey", "8181234567", "ventas@refnor.com"},
	{2, 5, "Llantas y Rines", "Sur 12, CDMX", "5512345678", "contacto@llantasyrames.com"},
	{3, 8, "Baterias y Acumuladores", "Oriente 23, Puebla", "2229876543", "info@baterias.com"},
	{4, 3, "Aceites y Lubricantes", "Poniente 56, Guadalajara", "3334455667", "ventas@aceites.com"},
	{5, 15, "Cristales y Parabrisas", "Centro, Cancun", "9981122334", "atencion@cristales.com"}};

int main()
{
	// Configura los colores de la terminal
	cout << COLORES_BASE << "\033[2J\033[H";

	Vista::inicio();
	Vista::login();
	Vista::dashboard();

	return 0;
}

//? ------- Vistas --------
void Vista::inicio()
{
	system("cls");

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
}

void Vista::login()
{
	bool credencialesCorrectas = false;
	string mensaje = "";

	do
	{
		system("cls");

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
}

void Vista::dashboard()
{
	//* Opciones del menu principal
	vector<string> opcionesMenu = {
		"Clientes",
		"Ventas",
		"Compras",
		"Proveedores",
		"Empleados",
		"Inventario",
		"Salir"};

	int opcion;
	string mensaje;
	bool salir = false;

	do
	{
		// Ciclo para mostrar el menu y obtener una opcion valida
		bool opcionValida = false;
		do
		{
			system("cls");
			IO::imprimirLinea("        Dashboard");
			mensaje.empty()
				? IO::imprimirLinea("")
				: IO::imprimirLinea(mensaje, TEXTO_ADVERTENCIA);

			IO::mostrarMenu("Opciones disponibles", opcionesMenu);
			try
			{
				opcion = stoi(IO::pedirDato("Ingresa la opcion deseada: "));
				if (opcion <= 0 || opcion > opcionesMenu.size())
					throw invalid_argument("");

				opcionValida = true;
			}
			catch (const std::invalid_argument &e)
			{
				mensaje = "Opcion no valida\n";
			}
		} while (!opcionValida);

		mensaje = ""; // Limpia el mensaje despues de una eleccion exitosa

		//* Navega a la vista seleccionada
		switch (opcion)
		{
		case 1:
			Vista::clientes();
			break;
		case 2:
			Vista::ventas();
			break;
		case 3:
			Vista::compras();
			break;
		case 4:
			Vista::proveedores();
			break;
		case 5:
			Vista::empleados();
			break;
		case 6:
			Vista::inventario();
			break;
		case 7:
			system("cls");
			IO::imprimirLinea("Saliendo del sistema... \n Adios!!");
			salir = true;
			break;
		default:
			IO::imprimirLinea("Opcion no encontrada");
			break;
		}

		if (!salir)
		{
			IO::imprimirLinea("Presiona ENTER para volver al dashboard...", "", false);
			cin.get();
		}
	} while (!salir);
}

void Vista::clientes()
{
	vector<string> opcionesMenu = {"Listar clientes", "Agregar cliente", "Volver"};
	int opcion;
	string mensaje;
	bool volver = false;

	system("cls");

	do
	{
		bool opcionValida = false;
		do
		{
			system("cls");
			IO::imprimirLinea("        Vista Clientes");
			mensaje.empty() ? IO::imprimirLinea("") : IO::imprimirLinea(mensaje, TEXTO_ADVERTENCIA);

			IO::mostrarMenu("Opciones disponibles", opcionesMenu);
			try
			{
				opcion = stoi(IO::pedirDato("Ingresa la opcion deseada: "));
				if (opcion <= 0 || opcion > opcionesMenu.size())
					throw invalid_argument("");

				opcionValida = true;
			}
			catch (const std::invalid_argument &e)
			{
				mensaje = "Opcion no valida";
			}
		} while (!opcionValida);

		mensaje = "";

		switch (opcion)
		{
		case 1: //? Listar clientes
			system("cls");
			IO::imprimirLinea("Lista de clientes:");
			if (Cliente::clientes.empty())
				IO::imprimirLinea("No hay clientes registrados.", TEXTO_ADVERTENCIA);
			else
				Cliente::listarClientes();
			break;
		case 2: //? Agregar cliente
			system("cls");
			IO::imprimirLinea("Agregar cliente:");
			Cliente::agregarCliente();
			break;
		case 3: //? Volver
			volver = true;
			break;
		default:
			IO::imprimirLinea("Opcion no encontrada");
			break;
		}

		if (!volver)
		{
			IO::imprimirLinea("Presiona ENTER para continuar...", "", false);
			cin.get();
		}
	} while (!volver);
}

void Vista::ventas()
{
	system("cls");
	IO::imprimirLinea("        Vista Ventas");
}

void Vista::compras()
{
	system("cls");
	IO::imprimirLinea("        Vista Compras");
}

void Vista::proveedores()
{
	vector<string> opcionesMenu = {"Listar proveedores", "Agregar proveedor", "Volver"};
	int opcion;
	string mensaje;
	bool volver = false;

	system("cls");

	do
	{
		bool opcionValida = false;
		do
		{
			system("cls");
			IO::imprimirLinea("        Vista Proveedores");
			mensaje.empty() ? IO::imprimirLinea("") : IO::imprimirLinea(mensaje, TEXTO_ADVERTENCIA);

			IO::mostrarMenu("Opciones disponibles", opcionesMenu);
			try
			{
				opcion = stoi(IO::pedirDato("Ingresa la opcion deseada: "));
				if (opcion <= 0 || opcion > opcionesMenu.size())
					throw invalid_argument("");

				opcionValida = true;
			}
			catch (const std::invalid_argument &e)
			{
				mensaje = "Opcion no valida";
			}
		} while (!opcionValida);

		mensaje = "";

		switch (opcion)
		{
		case 1: //? Listar proveedores
			system("cls");
			IO::imprimirLinea("Lista de proveedores:");
			if (Proveedor::proveedores.empty())
				IO::imprimirLinea("No hay proveedores registrados.", TEXTO_ADVERTENCIA);
			else
				Proveedor::listarProveedores();
			break;
		case 2: //? Agregar proveedor
			system("cls");
			IO::imprimirLinea("Agregar proveedor:");
			Proveedor::agregarProveedor();
			break;
		case 3: //? Volver
			volver = true;
			break;
		default:
			IO::imprimirLinea("Opcion no encontrada");
			break;
		}

		if (!volver)
		{
			IO::imprimirLinea("Presiona ENTER para continuar...", "", false);
			cin.get();
		}
	} while (!volver);
}

void Vista::empleados()
{
	system("cls");
	IO::imprimirLinea("        Vista Empleados");
}

void Vista::inventario()
{
	system("cls");
	IO::imprimirLinea("        Vista Inventario");
}

//? ---- Utilidades ----
void IO::imprimirLinea(string texto, string estilos, bool saltoLinea)
{
	cout << estilos << " " << texto << RESET_STYLE << COLORES_BASE;
	if (saltoLinea)
		cout << endl;
}

/*Imprime un menu con las opciones pasadas como parametro*/
void IO::mostrarMenu(string texto, vector<string> opciones)
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

void calcularDiferenciaDeTiempo(int fechaInicio, int *diferenciaTiempo)
{
	int anioActual = 2026;
	*diferenciaTiempo = anioActual - fechaInicio;
}

//? ---- Clientes ----
void Cliente::listarClientes()
{
	for (const Cliente &cliente : Cliente::clientes)
	{
		string info = "ID: " + to_string(cliente.id) + " | Nombre: " + cliente.nombre + " | Tiempo como cliente: " + to_string(cliente.tiempoComoCliente) + " anios";
		IO::imprimirLinea(info);
	}
}

void Cliente::agregarCliente()
{
	Cliente nuevoCliente;

	nuevoCliente.id = stoi(IO::pedirDato("Ingresa el ID del cliente: "));
	nuevoCliente.nombre = IO::pedirDato("Ingresa el nombre del cliente: ");
	nuevoCliente.direccion = IO::pedirDato("Ingresa la direccion del cliente: ");
	nuevoCliente.telefono = IO::pedirDato("Ingresa el telefono del cliente: ");
	nuevoCliente.correo = IO::pedirDato("Ingresa el correo del cliente: ");
	int fechaAlta;
	bool fechaValida = false;
	do
	{
		try
		{
			fechaAlta = stoi(IO::pedirDato("Ingresa el anio de alta del cliente: "));
			if (fechaAlta >= 1900 && fechaAlta <= 2026)
				fechaValida = true;
			else
				IO::imprimirLinea("Anio de alta invalido. Debe estar entre 1900 y 2026.", TEXTO_ADVERTENCIA);
		}
		catch (std::invalid_argument)
		{
			IO::imprimirLinea("Entrada invalida. Ingrese un numero.", TEXTO_ADVERTENCIA);
		}
	} while (!fechaValida);

	calcularDiferenciaDeTiempo(fechaAlta, &nuevoCliente.tiempoComoCliente);

	string mensaje = "\n El cliente " + nuevoCliente.nombre + " lleva " + to_string(nuevoCliente.tiempoComoCliente) + " anios como cliente.";
	IO::imprimirLinea(mensaje);

	Cliente::clientes.push_back(nuevoCliente);
	IO::imprimirLinea("Cliente agregado exitosamente!", TEXTO_ITALIC);

	string respuesta = IO::pedirDato("\nDeseas agregar otro cliente? (s/n): ");
	if (respuesta == "s" || respuesta == "S")
		agregarCliente();

	return;
}

//? ---- Proveedores ----
void Proveedor::listarProveedores()
{
	for (const Proveedor &proveedor : Proveedor::proveedores)
	{
		string info = "ID: " + to_string(proveedor.id) + " | Nombre: " + proveedor.nombre + " | Tiempo como proveedor: " + to_string(proveedor.tiempoComoProveedor) + " anios";
		IO::imprimirLinea(info);
	}
}

void Proveedor::agregarProveedor()
{
	Proveedor nuevoProveedor;

	nuevoProveedor.id = stoi(IO::pedirDato("Ingresa el ID del proveedor: "));
	nuevoProveedor.nombre = IO::pedirDato("Ingresa el nombre del proveedor: ");
	nuevoProveedor.direccion = IO::pedirDato("Ingresa la direccion del proveedor: ");
	nuevoProveedor.telefono = IO::pedirDato("Ingresa el telefono del proveedor: ");
	nuevoProveedor.correo = IO::pedirDato("Ingresa el correo del proveedor: ");

	int fechaAlta;
	bool fechaValida = false;
	do
	{
		try
		{
			fechaAlta = stoi(IO::pedirDato("Ingresa el anio de alta del proveedor: "));
			if (fechaAlta >= 1900 && fechaAlta <= 2026)
				fechaValida = true;
			else
				IO::imprimirLinea("Anio de alta invalido. Debe estar entre 1900 y 2026.", TEXTO_ADVERTENCIA);
		}
		catch (std::invalid_argument)
		{
			IO::imprimirLinea("Entrada invalida. Ingrese un numero.", TEXTO_ADVERTENCIA);
		}
	} while (!fechaValida);

	calcularDiferenciaDeTiempo(fechaAlta, &nuevoProveedor.tiempoComoProveedor);

	string mensaje = "\n El proveedor " + nuevoProveedor.nombre + " lleva " + to_string(nuevoProveedor.tiempoComoProveedor) + " anios como proveedor.";
	IO::imprimirLinea(mensaje);

	Proveedor::proveedores.push_back(nuevoProveedor);
	IO::imprimirLinea("Proveedor agregado exitosamente!", TEXTO_ITALIC);

	string respuesta = IO::pedirDato("\nDeseas agregar otro proveedor? (s/n): ");
	if (respuesta == "s" || respuesta == "S")
		agregarProveedor();

	return;
}
