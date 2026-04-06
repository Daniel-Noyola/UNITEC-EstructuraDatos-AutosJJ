#ifndef VISTAS_H
#define VISTAS_H

#include "./PantallaEnum.h"

struct Vista
{
	static Pantalla inicio();
	static Pantalla login();
	static Pantalla dashboard();

	// ─── Clientes ───────────────────────────────────────────────────────
	static void clientes();
	static void registrarCliente();
	static void listarClientes();
	static void buscarClienteId();
	static void buscarClienteNombre();
	static void eliminarClienteId();

	// ─── Proveedores ────────────────────────────────────────────────────
	static void proveedores();
	static void registrarProveedor();
	static void listarProveedores();
	static void buscarProveedorId();
	static void eliminarProveedor();

	// ─── Vehículos ──────────────────────────────────────────────────────
	static void vehiculos();
	static void registrarVehiculo();
	static void listarVehiculos();
	static void buscarVehiculoId();
	static void buscarVehiculoMarca();
	static void marcarReparado();

	// ─── Taller (Gastos de Reparación) ──────────────────────────────────
	static void taller();
	static void agregarGasto();
	static void verGastos();

	// ─── Inventario ─────────────────────────────────────────────────────
	static void inventario();

	// ─── Ventas ─────────────────────────────────────────────────────────
	static void ventas();
	static void registrarVenta();
	static void listarVentas();

	// ─── Reportes ───────────────────────────────────────────────────────
	static void reportes();

	// ─── Otros (stubs a mantener) ───────────────────────────────────────
	static void compras();
	static void empleados();
};

#endif // VISTAS_H