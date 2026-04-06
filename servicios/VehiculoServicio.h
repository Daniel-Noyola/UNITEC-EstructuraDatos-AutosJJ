#ifndef VEHICULOSERVICIO_H
#define VEHICULOSERVICIO_H
#include "../utilidades/EditorCSV.h"
#include "../modelos/Vehiculo.h"
#include <list>

struct VehiculoServicio
{
	EditorCSV editorCSV;
	static int ultimoId;
	VehiculoServicio();

	/*Obtiene la lista de vehículos registrados*/
	list<Vehiculo> obtenerVehiculos();

	/*Valida la información de un vehículo antes de guardarlo*/
	void validarVehiculo(const Vehiculo& vehiculo);

	/*Agrega un nuevo vehículo*/
	Vehiculo agregarVehiculo(Vehiculo vehiculo);

	/*Obtiene un vehículo por su ID*/
	Vehiculo obtenerVehiculoPorId(int id);

	/*Obtiene vehículos filtrados por marca*/
	list<Vehiculo> obtenerVehiculosPorMarca(const string& marca);

	/*Devuelve solo los vehículos reparados y listos para la venta*/
	list<Vehiculo> obtenerVehiculosDisponibles();

	/*Marca un vehículo como reparado (listo para venta)*/
	Vehiculo marcarComoReparado(int id);

	/*Ordena la lista de vehículos por ID usando bubble sort*/
	static void ordenarVehiculos(list<Vehiculo>& vehiculos);

	/*Ordena la lista de vehículos por precio de adquisicion usando bubble sort*/
	static void ordenarVehiculosPorPrecio(list<Vehiculo>& vehiculos);
};

#endif // VEHICULOSERVICIO_H