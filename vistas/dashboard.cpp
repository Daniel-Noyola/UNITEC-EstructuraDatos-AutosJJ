#pragma once
#include "../AutosJJ.h"

Pantalla Vista::dashboard()
{
    /*Opciones del menu principal*/
    vector<string> opcionesMenu = {
        "Clientes",
        "Proveedores",
        "Vehiculos / Compras",
        "Taller (Gastos de Reparacion)",
        "Inventario",
        "Ventas",
        "Reportes",
        "Salir" };

    bool salir = false;
    string mensaje;

    /*Ciclo principal del dashboard que mantiene el programa en ejecucion*/
    while (!salir)
    {
		IO::limpiarPantalla();
        IO::imprimirLinea("=== Dashboard ===");
        IO::imprimirMenu("Opciones disponibles:", opcionesMenu);
		mensaje.empty() ? IO::imprimirLinea("") : IO::imprimirLinea(mensaje, TEXTO_ADVERTENCIA);
		mensaje.clear();

        int opcion = 0;

        /*Valida que el usuario ingrese una opcion valida del menu*/
        try {
            opcion = stoi(IO::pedirDato("Seleccione una opcion: "));
        }
        catch (const std::exception&)
        {
            mensaje = "Opcion no valida. Intente nuevamente.";
            continue;
        }

        /*Ejecuta la opcion seleccionada por el usuario*/
        switch (opcion)
        {
        case 1: Vista::clientes();    break;
		case 2: Vista::proveedores(); break;
        case 3: Vista::vehiculos();   break;
        case 4: Vista::taller();      break;
        case 5: Vista::inventario();  break;
        case 6: Vista::ventas();      break;
        case 7: Vista::reportes();    break;
        case 8: salir = true;         break;
        default:
            mensaje = "Opcion no valida. Intente nuevamente.";
            break;
        }
    }

    return Pantalla::Salir;
}
