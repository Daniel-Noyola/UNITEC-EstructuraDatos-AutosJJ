#ifndef EDITORCSV_H
#define EDITORCSV_H

#include <string>
#include <vector>

using namespace std;

struct EditorCSV
{
	string nombreArchivo;
	string encabezados;

	EditorCSV(string _nombreArchivo, string _encabezados);

	/*Verifica si un archivo existe*/
	bool archivoExiste() const;

	/*Crea un nuevo archivo con los encabezados especificados*/
	void crearArchivo();

	/*Guarda los datos en una fila del archivo*/
	void guardarEnArchivo(const string& datos);

	/*Lee las filas de datos del archivo, ignorando la primera fila (encabezados)*/
	vector<string> leerArchivo() const;

	/*Reescribe el archivo con las filas proporcionadas, manteniendo los encabezados*/
	void reescribirArchivo(const vector<string>& filas);
};

#endif // EDITORCSV_H