#ifndef VISTAS_H
#define VISTAS_H

#include "./PantallaEnum.h"

struct Vista
{
	static Pantalla inicio();
	static Pantalla login();
	static Pantalla dashboard();

	static void clientes();
	static void registrarCliente();
	static void listarClientes();
	static void buscarClienteId();
	static void buscarClienteNombre();
	static void eliminarClienteId();

	static void vehiculos();
	static void registrarVehiculo();
	static void buscarVehiculoId();
	static void buscarVehiculoMarca();

	static void ventas();
	static void compras();
	static void proveedores();
	static void empleados();
	static void inventario();
};

#endif // VISTAS_H