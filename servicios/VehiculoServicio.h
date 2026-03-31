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

	/*Agrega un nuevo vehículo*/
	Vehiculo agregarVehiculo(int anio, const string& descripcion, const string& marca, const string& modelo, const string& color, const string& version, const string& kilometraje, const string& estado, const string& aseguradora, const string& precioCliente);

	/*Obtiene un vehículo por su ID*/
	Vehiculo obtenerVehiculoPorId(int id);

	list<Vehiculo> obtenerVehiculosPorMarca(const string& marca);

	/*Ordena la lista de vehículos por ID usando bubble sort*/
	static void ordenarVehiculos(list<Vehiculo>& vehiculos);
};

#endif // VEHICULOSERVICIO_H