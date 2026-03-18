# Documentación del Proyecto AutosJJ

## Visión General

`AutosJJ` es una aplicación de consola escrita en C++ que simula un sencillo sistema de gestión de vehículos. Demuestra conceptos básicos de programación como **estructuras**, **funciones**, **entrada/salida de archivos** y un diseño orientado a objetos simple. El proyecto está organizado para que sea fácil de explorar por estudiantes que están aprendiendo tanto programación general como el lenguaje C++.

---

## Estructura del Proyecto

```
AutosJJ/
├─ CMakeLists.txt            # Configuración de compilación (CMake)
├─ AutosJJ.cpp               # Punto de entrada (función main)
├─ AutosJJ.h                 # Includes globales y macros de utilidad
├─ data/                     # Archivos CSV de ejemplo usados por la aplicación
├─ includes/                 # Cabeceras de cada módulo
│   ├─ EditorCSV.h           # Utilidades para leer/escribir CSV
│   ├─ Constantes.h          # Constantes de colores y valores globales
│   └─ ...
├─ modelos/                  # Modelos de datos (structs) que representan entidades
│   ├─ Vehiculo.h            # Definición de la estructura Vehículo
│   └─ ...
├─ servicios/                # Capa de servicios – lógica de negocio
│   ├─ VehiculoServicio.h    # Funciones para crear, editar, listar vehículos
│   └─ ...
├─ utilidades/               # Utilidades auxiliares (validación, menús)
│   └─ ...
├─ vistas/                   # Capa de vistas – interacción con el usuario
│   ├─ VistaInicio.h         # Pantalla de bienvenida
│   ├─ VistaLogin.h          # Pantalla de login
│   ├─ VistaDashboard.h      # Menú principal después del login
│   └─ ...
└─ out/                      # Salida de compilación (ejecutables, objetos)
```

### Detalle de Directorios

- **CMakeLists.txt** – Define el nombre del proyecto, el estándar de C++ requerido (C++17), los archivos fuente y los directorios de includes. Ejecutando `cmake .` y luego `cmake --build .` se genera el ejecutable.
- **AutosJJ.cpp / AutosJJ.h** – Código mínimo que inicia la aplicación e incluye los encabezados más comunes.
- **data/** – Contiene los archivos CSV (`autos.csv`, `clientes.csv`, etc.) que utiliza `EditorCSV`. Puedes modificarlos para observar cómo cambia el comportamiento del programa.
- **includes/** – Archivos de cabecera que exponen la interfaz pública de cada módulo. Mantener los headers separados de las implementaciones facilita la navegación del código.
- **modelos/** – Definiciones simples de `struct` que modelan entidades del mundo real (Vehículo, Cliente, etc.). Son contenedores de datos sin lógica de negocio.
- **servicios/** – Funciones que operan sobre los modelos. Por ejemplo, `VehiculoServicio` contiene funciones para agregar, eliminar o buscar vehículos. Esta capa aísla el *qué* del *cómo*.
- **utilidades/** – Herramientas varias como validación de entrada, renderizado de menús y manejo de colores de consola. Se reutilizan en distintas vistas.
- **vistas/** – La capa de *vista*. Cada vista corresponde a una pantalla que el usuario ve en la consola. Las funciones en este directorio se encargan de imprimir menús, leer opciones del usuario y llamar a las funciones de servicio correspondientes.
- **out/** – Artefactos generados por la compilación (archivos objeto, ejecutable). Esta carpeta está ignorada por el control de versiones.

---

## Cómo Compilar y Ejecutar

## Cómo Compilar y Ejecutar con Visual Studio

1. **Abrir el proyecto en Visual Studio**
   - En Visual Studio, seleccione **Archivo → Abrir → Carpeta...** y elija la carpeta raíz `AutosJJ`. Visual Studio detectará automáticamente el archivo `CMakeLists.txt` y configurará un proyecto CMake.

2. **Configurar la generación**
   - En la barra superior, elija la configuración **Debug** o **Release** y la plataforma **x64** (o la que prefiera).  
   - Visual Studio generará los archivos de proyecto y mostrará la lista de fuentes en el Explorador de Soluciones.

3. **Compilar**
   - Presione **Ctrl + Shift + B** o haga clic en **Compilar → Compilar solución**. Visual Studio ejecutará CMake y compilará el ejecutable en la carpeta `out\`.

4. **Ejecutar**
   - En la barra de depuración, haga clic en **Iniciar sin depuración** (Ctrl + F5) o **Iniciar depuración** (F5) para lanzar `AutosJJ.exe`.  
   - La consola aparecerá y podrá interactuar con el programa.

5. **Actualización automática de CMake**
   - Cada vez que añada o elimine archivos fuente en el proyecto, Visual Studio actualizará automáticamente el `CMakeLists.txt` interno, por lo que no es necesario editar manualmente el archivo CMake.

---

## Puntos de Aprendizaje para Nuevos Estudiantes

- **Diseño Modular** – El proyecto separa *datos* (modelos), *lógica* (servicios) y *presentación* (vistas). Esto refleja el patrón Modelo‑Vista‑Controlador (MVC) y ayuda a comprender una arquitectura limpia.
- **Separación Header/Implementation** – Al colocar declaraciones en archivos `.h` y definiciones en `.cpp`, aprendes cómo el compilador resuelve símbolos y cómo evitar dependencias circulares.
- **Entrada/Salida de Archivos CSV** – `EditorCSV` muestra cómo abrir un archivo, leer línea por línea, dividir por comas e ignorar la fila de encabezado. Es un ejemplo práctico de manipulación de datos externos.
- **Uso de `struct` vs `class`** – El proyecto usa principalmente `struct` para contenedores de datos simples, lo que por defecto tiene miembros públicos, facilitando su uso a principiantes.
- **Constantes de Color** – `Constantes.h` define códigos de color para la consola (`TEXTO_EXITO`, `TEXTO_ERROR`). Puedes experimentar cambiando estos valores para ver cómo se estiliza la salida.
- **Sistema de Build (CMake)** – Entender el archivo `CMakeLists.txt` enseña cómo automatizar la compilación en distintas plataformas.

---

## Contribuir al Proyecto

Si deseas ampliar el proyecto:
1. Añade un nuevo **modelo** en `modelos/` si necesitas una nueva entidad.
2. Crea el **servicio** correspondiente en `servicios/` para la lógica de negocio.
3. Añade una **vista** en `vistas/` para exponer la nueva funcionalidad al usuario.
4. Actualiza `CMakeLists.txt` para incluir los nuevos archivos fuente.

Todas las contribuciones deben seguir el estilo de codificación existente: usar `camelCase` para funciones, mantener líneas por debajo de 100 caracteres y agregar comentarios que expliquen el propósito de cada función.
