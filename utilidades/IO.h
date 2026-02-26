#pragma once
#include <string>
#include <vector>

struct IO
{
	/*Muestra un menu con las opciones almacenadas en un arreglo*/
	static void imprimirMenu(std::string texto, std::vector<std::string> opciones);

	/*Imprime una linea en la terminal el texto especificado con los estilos disponibles*/
	static void imprimirLinea(std::string texto, std::string estilos = "", bool saltoLinea = true);

	/*Imprime un texto y espera a que el usuario ingrese un dato*/
	static std::string pedirDato(std::string texto, bool esSecreto = false);

	static void limpiarPantalla();
};
