#pragma once
#include "../AutosJJ.h"

Pantalla Vista::dashboard()
{
    //* Opciones del menu principal
    vector<string> opcionesMenu = {
        "Clientes",
        "Vehiculos",
        "Ventas",
        "Compras",
        "Proveedores",
        "Empleados",
        "Inventario",
        "Salir" };

    bool salir = false;
    string mensaje;

    while (!salir)
    {
		IO::limpiarPantalla();
        IO::imprimirLinea("=== Dashboard ===");
        IO::imprimirMenu("Opciones disponibles:", opcionesMenu);
		mensaje.empty() ? IO::imprimirLinea("") : IO::imprimirLinea(mensaje, TEXTO_ADVERTENCIA);
		mensaje.clear();

        int opcion = 0;
        try {
            opcion = stoi(IO::pedirDato("Seleccione una opcion: "));
        }
        catch (const std::exception&)
        {
            mensaje = "Opcion no valida. Intente nuevamente.";
            continue;
        }

        switch (opcion)
        {
        case 1: Vista::clientes();     break;
		case 2: Vista::vehiculos();    break;
        case 3: Vista::ventas();       break;
        case 4: Vista::compras();      break;
        case 5: Vista::proveedores();  break;
        case 6: Vista::empleados();    break;
        case 7: Vista::inventario();   break;
        case 8: salir = true;          break;
        default:
            mensaje = "Opcion no valida. Intente nuevamente.";
            break;
        }
    }

    return Pantalla::Salir;
}
