#ifndef EDITORCSV_H
#define EDITORCSV_H

#include <string>
#include <vector>

using namespace std;

struct EditorCSV
{
	string nombreArchivo;
	EditorCSV(string _nombreArchivo);

	/*Verifica si un archivo existe*/
	bool archivoExiste() const;

	/*Crea un nuevo archivo con los encabezados especificados*/
	void crearArchivo(const string& encabezados);

	/*Guarda los datos en una fila del archivo*/
	void guardarEnArchivo(const string& datos);

	/*Lee las filas de datos del archivo, ignorando la primera fila (encabezados)*/
	vector<string> leerArchivo() const;
};

#endif // EDITORCSV_H