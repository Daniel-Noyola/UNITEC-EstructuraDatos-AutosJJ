#include "EditorCSV.h"

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

EditorCSV::EditorCSV(string _nombreArchivo, string _encabezados) : nombreArchivo(string(PROJECT_ROOT) + _nombreArchivo), encabezados(_encabezados)
{}

bool EditorCSV::archivoExiste() const
{
	ifstream archivo(nombreArchivo);
	return archivo.good();
}

void EditorCSV::crearArchivo()
{
	if(!archivoExiste())
	{
		ofstream archivo(nombreArchivo);
		if(archivo.is_open())
		{
			archivo << encabezados << endl;
			archivo.close();
		}
	}
}

void EditorCSV::guardarEnArchivo(const string& datos)
{
	ofstream archivo(nombreArchivo, ios::app);
	if (archivo.is_open())
	{
		archivo << fixed << setprecision(2);
		archivo << datos << endl;
		archivo.close();
	}
	
}

vector<string> EditorCSV::leerArchivo() const
{
	vector<string> filas;
	ifstream archivo(nombreArchivo);
	if (archivo.is_open())
	{
		string linea;
		getline(archivo, linea); // Ignorar la primera fila (encabezados)
		while (getline(archivo, linea))
		{
			filas.push_back(linea);
		}
		archivo.close();
	}
	return filas;
}

void EditorCSV::reescribirArchivo(const vector<string>& filas)
{
	ofstream archivo(nombreArchivo);
	if (archivo.is_open())
	{
		archivo << encabezados << endl; // Escribir los encabezados
		archivo << fixed << setprecision(2);

		for (const string& fila : filas)
		{
			archivo << fila << endl; // Escribir cada fila de datos
		}
		archivo.close();
	}
}