#pragma once
#include "./PantallaEnum.h"

struct Vista
{
	static Pantalla inicio();
	static Pantalla login();
	static Pantalla dashboard();

	static void clientes();
	static void registrarCliente();
	static void listarClientes();

	static void ventas();
	static void compras();
	static void proveedores();
	static void empleados();
	static void inventario();
};
