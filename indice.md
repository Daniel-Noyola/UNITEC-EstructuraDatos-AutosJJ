# Índice de Aspectos Técnicos — Proyecto AutosJJ

## 1. Funciones

**Definición:**  
Una **función** es un bloque de código con nombre que realiza una tarea específica y puede ser invocado desde otros puntos del programa. Recibe datos de entrada mediante **parámetros**, ejecuta su lógica y puede retornar un resultado con `return`. Promueven la reutilización de código y separan responsabilidades (cada función hace una sola cosa).

**Cuándo se usa:** A lo largo de todo el proyecto para encapsular operaciones como validar datos, ordenar listas, calcular totales y leer/escribir archivos CSV.

---

## 2. Apuntadores (Pointers)

**Definición:**  
Un apuntador es una variable que almacena la **dirección de memoria** de otra variable. En lugar de contener un valor directamente, guarda "dónde" está ese valor. Se declaran con `*` y se accede al valor que señalan con el operador de desreferencia `*`. La dirección de una variable se obtiene con el operador `&`.

**Cuándo se usa:** Cuando se quiere que una función modifique directamente el valor de una variable del llamador (paso por referencia manual), evitando copias innecesarias.

---

### 📝 Definición

| Archivo | Líneas | Descripción |
|---------|--------|-------------|
| [`utilidades/Utils.cpp`](./utilidades/Utils.cpp) | 8–12 | Declaración e implementación de `calcularDiferenciaDeTiempo(int fechaInicio, int* diferenciaTiempo)`. El parámetro `int*` es el apuntador; la línea `*diferenciaTiempo = anioActual - fechaInicio` escribe el resultado directamente en la variable apuntada. |

### ▶️ Uso

| Archivo | Líneas | Descripción |
|---------|--------|-------------|
| [`vistas/clientes/registrarClientes.cpp`](./vistas/clientes/registrarClientes.cpp) | 22–23 | Se declara un apuntador explícito `int* tiempoClientePtr = &nuevoCliente.tiempoComoCliente` y se pasa a `calcularDiferenciaDeTiempo`. La función escribe el resultado directamente sobre el campo del struct a través del apuntador, sin necesidad de retornar un valor. |

---

## 3. Recursividad

**Definición:**  
Una función **recursiva** es aquella que se llama a sí misma para resolver una versión más pequeña del mismo problema. Toda función recursiva requiere al menos un **caso base** que detiene las llamadas (evita el ciclo infinito) y un **caso recursivo** que avanza hacia ese caso base.

**Cuándo se usa:** Cuando un problema se puede descomponer en subproblemas del mismo tipo, como recorrer una lista acumulando valores.

---

### 📝 Definición

| Archivo | Líneas | Descripción |
|---------|--------|-------------|
| [`servicios/GastoReparacionServicio.cpp`](./servicios/GastoReparacionServicio.cpp) | 80–88 | Función `calcularTotalGastos(it, fin)`: recorre la lista de gastos de forma recursiva. **Caso base (L85–86):** si `it == fin` retorna `0.0`. **Caso recursivo (L87):** retorna `it->monto + calcularTotalGastos(next(it), fin)`. |
| [`servicios/VentaServicio.cpp`](./servicios/VentaServicio.cpp) | 78–86 | Función `calcularGananciaTotal(it, fin)`: acumula la utilidad de todas las ventas recursivamente. **Caso base (L83–84):** retorna `0.0` cuando `it == fin`. **Caso recursivo (L85):** retorna `it->utilidad + calcularGananciaTotal(next(it), fin)`. |

### ▶️ Uso

| Archivo | Líneas | Descripción |
|---------|--------|-------------|
| [`vistas/taller/verGastos.cpp`](./vistas/taller/verGastos.cpp) | 37–39 | Llama a `calcularTotalGastos` para mostrar el total de gastos de reparación de un vehículo específico. |
| [`vistas/ventas/registrarVenta.cpp`](./vistas/ventas/registrarVenta.cpp) | 45–47 | Llama a `calcularTotalGastos` para obtener el costo total de reparación antes de registrar la venta. |
| [`vistas/reportes/reportes.cpp`](./vistas/reportes/reportes.cpp) | 18–26 | Llama a `calcularGananciaTotal` y a `calcularTotalGastos` para generar el reporte financiero global del sistema. |

---



## 4. Estructuras (`struct`)

**Definición:**  
Una **estructura** (`struct`) es un tipo de dato compuesto que agrupa múltiples variables (llamadas **campos** o **miembros**) bajo un mismo nombre. Permite modelar entidades del mundo real con sus atributos. En C++, a diferencia de una clase, los miembros son públicos por defecto.

**Cuándo se usa:** Para representar las entidades del sistema (vehículos, clientes, ventas, etc.) agrupando todos sus datos relacionados en una sola unidad.

---

### 📝 Definición

| Archivo | Líneas | Estructura | Campos principales |
|---------|--------|-----------|-------------------|
| [`modelos/Vehiculo.h`](./modelos/Vehiculo.h) | 8–23 | `Vehiculo` | id, anio, descripcion, marca, modelo, color, version, kilometraje, estado, aseguradora, precioCliente, precioAdquisicion, reparado |
| [`modelos/Cliente.h`](./modelos/Cliente.h) | 8–16 | `Cliente` | id, tiempoComoCliente, nombre, direccion, telefono, correo |
| [`modelos/GastoReparacion.h`](./modelos/GastoReparacion.h) | 8–14 | `GastoReparacion` | id, vehiculoId, descripcion, monto |
| [`modelos/Venta.h`](./modelos/Venta.h) | 8–17 | `Venta` | id, vehiculoId, clienteId, precioVenta, precioAdquisicion, totalGastos, utilidad |
| [`modelos/Proveedor.h`](./modelos/Proveedor.h) | 8–15 | `Proveedor` | id, nombre, contacto, direccion, telefono |

### ▶️ Uso

| Archivo | Líneas | Estructura usada | Descripción |
|---------|--------|-----------------|-------------|
| [`servicios/VehiculoServicio.cpp`](./servicios/VehiculoServicio.cpp) | 29–56 | `Vehiculo` | Se crean instancias de `Vehiculo` al parsear cada fila del CSV. |
| [`servicios/ClienteServicio.cpp`](./servicios/ClienteServicio.cpp) | 28–46 | `Cliente` | Se crean instancias de `Cliente` al leer el archivo `clientes.csv`. |
| [`servicios/GastoReparacionServicio.cpp`](./servicios/GastoReparacionServicio.cpp) | 26–43 | `GastoReparacion` | Se crean instancias de `GastoReparacion` al leer `gastos.csv`. |
| [`servicios/VentaServicio.cpp`](./servicios/VentaServicio.cpp) | 28–48 | `Venta` | Se crean instancias de `Venta` al leer `ventas.csv`. |
| [`servicios/ProveedorServicio.cpp`](./servicios/ProveedorServicio.cpp) | 27–44 | `Proveedor` | Se crean instancias de `Proveedor` al leer `proveedores.csv`. |
| [`utilidades/Utils.cpp`](./utilidades/Utils.cpp) | 29–96 | Todas | Se instancian structs de todas las entidades para cargar los datos de prueba. |

---

## 5. Algoritmo de Ordenamiento — Bubble Sort

**Definición:**  
El **Bubble Sort** (ordenamiento de burbuja) recorre repetidamente la colección comparando pares de elementos adyacentes e intercambiándolos si están en el orden incorrecto. Repite el proceso hasta que no se hace ningún intercambio, lo que indica que la colección quedó ordenada.

**Complejidad:** O(n²) en el peor caso. Sencillo de implementar e ideal para colecciones pequeñas.

**Cuándo se usa:** Para ordenar las listas de entidades por un campo clave (ID o precio) antes de mostrarlas al usuario.

---

### 📝 Definición

| Archivo | Líneas | Función | Criterio de orden |
|---------|--------|---------|------------------|
| [`servicios/VehiculoServicio.cpp`](./servicios/VehiculoServicio.cpp) | 194–213 | `ordenarVehiculos` | Ordena `list<Vehiculo>` por `id` ascendente. |
| [`servicios/VehiculoServicio.cpp`](./servicios/VehiculoServicio.cpp) | 215–235 | `ordenarVehiculosPorPrecio` | Ordena `list<Vehiculo>` por `precioAdquisicion` ascendente. |
| [`servicios/ClienteServicio.cpp`](./servicios/ClienteServicio.cpp) | 144–163 | `ordenarClientes` | Ordena `list<Cliente>` por `id` ascendente. |
| [`servicios/ProveedorServicio.cpp`](./servicios/ProveedorServicio.cpp) | 126–145 | `ordenarProveedores` | Ordena `list<Proveedor>` por `id` ascendente. |

### ▶️ Uso

| Archivo | Líneas | Función invocada | Descripción |
|---------|--------|-----------------|-------------|
| [`servicios/VehiculoServicio.cpp`](./servicios/VehiculoServicio.cpp) | 58 | `ordenarVehiculos` | Se llama automáticamente al final de `obtenerVehiculos()` antes de retornar la lista. |
| [`servicios/VehiculoServicio.cpp`](./servicios/VehiculoServicio.cpp) | 134 | `ordenarVehiculos` | Se llama en `obtenerVehiculosPorMarca()` para retornar el resultado ordenado. |
| [`servicios/ClienteServicio.cpp`](./servicios/ClienteServicio.cpp) | 48 | `ordenarClientes` | Se llama en `obtenerClientes()` antes de retornar la lista. |
| [`servicios/ProveedorServicio.cpp`](./servicios/ProveedorServicio.cpp) | 46 | `ordenarProveedores` | Se llama en `obtenerProveedores()` antes de retornar la lista. |
| [`vistas/inventario/inventario.cpp`](./vistas/inventario/inventario.cpp) | 23–24 | `ordenarVehiculosPorPrecio` | Ordena el inventario disponible por precio antes de mostrarlo en pantalla. |

---

## 6. Listas (`list<T>`)

**Definición:**  
`std::list<T>` es una **lista doblemente enlazada** de la biblioteca estándar de C++. A diferencia de `array` o `vector`, sus elementos no son contiguos en memoria; cada nodo apunta al anterior y al siguiente. Es eficiente para insertar y eliminar en cualquier posición, y se recorre con iteradores.

**Métodos usados en el proyecto:**
- `push_back(e)` — agrega un elemento al final.
- `.begin()` / `.end()` — iteradores al inicio y al fin.
- `.empty()` — verifica si la lista está vacía.
- `.size()` — número de elementos.
- `.cbegin()` / `.cend()` — iteradores constantes (usados en las funciones recursivas).

**Cuándo se usa:** Para almacenar las colecciones de entidades cargadas desde los CSV, reemplazando arreglos de tamaño fijo.

---

### 📝 Definición

| Archivo | Líneas | Función | Tipo de lista retornada |
|---------|--------|---------|------------------------|
| [`servicios/VehiculoServicio.cpp`](./servicios/VehiculoServicio.cpp) | 22–60 | `obtenerVehiculos` | `list<Vehiculo>` — construida con `push_back` por cada fila del CSV. |
| [`servicios/VehiculoServicio.cpp`](./servicios/VehiculoServicio.cpp) | 125–136 | `obtenerVehiculosPorMarca` | `list<Vehiculo>` — filtrada y construida con `push_back`. |
| [`servicios/VehiculoServicio.cpp`](./servicios/VehiculoServicio.cpp) | 138–148 | `obtenerVehiculosDisponibles` | `list<Vehiculo>` — solo vehículos con `reparado == true`. |
| [`servicios/ClienteServicio.cpp`](./servicios/ClienteServicio.cpp) | 21–50 | `obtenerClientes` | `list<Cliente>` — cargada desde `clientes.csv`. |
| [`servicios/GastoReparacionServicio.cpp`](./servicios/GastoReparacionServicio.cpp) | 19–45 | `obtenerGastos` | `list<GastoReparacion>` — cargada desde `gastos.csv`. |
| [`servicios/GastoReparacionServicio.cpp`](./servicios/GastoReparacionServicio.cpp) | 47–57 | `obtenerGastosPorVehiculo` | `list<GastoReparacion>` — filtrada por `vehiculoId`. |
| [`servicios/VentaServicio.cpp`](./servicios/VentaServicio.cpp) | 21–50 | `obtenerVentas` | `list<Venta>` — cargada desde `ventas.csv`. |
| [`servicios/ProveedorServicio.cpp`](./servicios/ProveedorServicio.cpp) | 20–48 | `obtenerProveedores` | `list<Proveedor>` — cargada desde `proveedores.csv`. |

### ▶️ Uso

| Archivo | Líneas | Lista utilizada | Descripción |
|---------|--------|----------------|-------------|
| [`vistas/vehiculos/listarVehiculos.cpp`](./vistas/vehiculos/listarVehiculos.cpp) | — | `list<Vehiculo>` | Itera la lista para mostrar todos los vehículos en pantalla. |
| [`vistas/inventario/inventario.cpp`](./vistas/inventario/inventario.cpp) | 12–38 | `list<Vehiculo>` | Usa la lista de disponibles para ordenar y mostrar el inventario. |
| [`vistas/taller/verGastos.cpp`](./vistas/taller/verGastos.cpp) | 20–39 | `list<GastoReparacion>` | Itera la lista de gastos con un bucle `for` y la pasa a la función recursiva. |
| [`vistas/ventas/registrarVenta.cpp`](./vistas/ventas/registrarVenta.cpp) | 21–47 | `list<Vehiculo>`, `list<GastoReparacion>` | Obtiene disponibles, filtra gastos y pasa los iteradores de la lista a `calcularTotalGastos`. |
| [`vistas/reportes/reportes.cpp`](./vistas/reportes/reportes.cpp) | 19–52 | `list<Venta>`, `list<Vehiculo>`, `list<GastoReparacion>` | Usa las tres listas para calcular y mostrar el reporte financiero completo. |

---

## 7. Persistencia de Datos mediante Archivos CSV

**Definición:**  
Un archivo **CSV** (Comma-Separated Values) es un formato de texto plano donde cada línea representa un registro y los campos están separados por comas. Permite **persistir datos** entre ejecuciones del programa: se guardan en disco al crear o modificar registros, y se leen al iniciar el sistema.

**Cuándo se usa:** Para que los datos del sistema no se pierdan al cerrar el programa. Cada entidad tiene su propio archivo CSV en la carpeta `data/`.

**Archivos CSV del sistema:**

| Archivo CSV | Entidad | Encabezados |
|-------------|---------|-------------|
| `data/vehiculos.csv` | Vehículos | `id, anio, descripcion, marca, modelo, color, version, kilometraje, estado, aseguradora, precioCliente, precioAdquisicion, reparado` |
| `data/clientes.csv` | Clientes | `ID, TiempoComoCliente, Nombre, Direccion, Telefono, Correo` |
| `data/gastos.csv` | Gastos de Reparación | `id, vehiculoId, descripcion, monto` |
| `data/ventas.csv` | Ventas | `id, vehiculoId, clienteId, precioVenta, precioAdquisicion, totalGastos, utilidad` |
| `data/proveedores.csv` | Proveedores | `id, nombre, contacto, direccion, telefono` |

---

### 📝 Definición

| Archivo | Líneas | Función / Clase | Descripción |
|---------|--------|----------------|-------------|
| [`utilidades/EditorCSV.h`](./utilidades/EditorCSV.h) | — | `struct EditorCSV` | Declara la clase que encapsula toda la lógica de lectura y escritura CSV. |
| [`utilidades/EditorCSV.cpp`](./utilidades/EditorCSV.cpp) | 17–28 | `crearArchivo` | Crea el archivo con sus encabezados si no existe en disco. |
| [`utilidades/EditorCSV.cpp`](./utilidades/EditorCSV.cpp) | 30–40 | `guardarEnArchivo` | Abre el archivo en modo `append` y escribe una nueva fila de datos. |
| [`utilidades/EditorCSV.cpp`](./utilidades/EditorCSV.cpp) | 42–57 | `leerArchivo` | Lee todas las filas del CSV (omitiendo el encabezado) y las retorna como `vector<string>`. |
| [`utilidades/EditorCSV.cpp`](./utilidades/EditorCSV.cpp) | 59–73 | `reescribirArchivo` | Reemplaza el contenido completo del archivo (usado en actualizaciones y eliminaciones). |

### ▶️ Uso

| Archivo | Líneas | Operación | Descripción |
|---------|--------|-----------|-------------|
| [`servicios/VehiculoServicio.cpp`](./servicios/VehiculoServicio.cpp) | 10–12 | Inicialización | El constructor crea un `EditorCSV` apuntando a `vehiculos.csv`. |
| [`servicios/VehiculoServicio.cpp`](./servicios/VehiculoServicio.cpp) | 24 | `leerArchivo` | Llama a `leerArchivo()` para obtener las filas del CSV y poblar la lista. |
| [`servicios/VehiculoServicio.cpp`](./servicios/VehiculoServicio.cpp) | 109 | `guardarEnArchivo` | Guarda la cadena CSV del nuevo vehículo al final del archivo. |
| [`servicios/VehiculoServicio.cpp`](./servicios/VehiculoServicio.cpp) | 189 | `reescribirArchivo` | Reescribe el archivo completo al marcar un vehículo como reparado. |
| [`servicios/ClienteServicio.cpp`](./servicios/ClienteServicio.cpp) | 10–12 | Inicialización | El constructor crea un `EditorCSV` apuntando a `clientes.csv`. |
| [`servicios/ClienteServicio.cpp`](./servicios/ClienteServicio.cpp) | 80 | `guardarEnArchivo` | Guarda la cadena CSV del nuevo cliente al final del archivo. |
| [`servicios/ClienteServicio.cpp`](./servicios/ClienteServicio.cpp) | 140 | `reescribirArchivo` | Reescribe el archivo al eliminar un cliente. |
| [`servicios/GastoReparacionServicio.cpp`](./servicios/GastoReparacionServicio.cpp) | 9–11 | Inicialización | Constructor apunta a `gastos.csv`. |
| [`servicios/GastoReparacionServicio.cpp`](./servicios/GastoReparacionServicio.cpp) | 75 | `guardarEnArchivo` | Guarda el nuevo gasto de reparación en el CSV. |
| [`servicios/VentaServicio.cpp`](./servicios/VentaServicio.cpp) | 11–13 | Inicialización | Constructor apunta a `ventas.csv`. |
| [`servicios/VentaServicio.cpp`](./servicios/VentaServicio.cpp) | 73 | `guardarEnArchivo` | Guarda la nueva venta en el CSV. |
| [`servicios/ProveedorServicio.cpp`](./servicios/ProveedorServicio.cpp) | 10–12 | Inicialización | Constructor apunta a `proveedores.csv`. |
| [`servicios/ProveedorServicio.cpp`](./servicios/ProveedorServicio.cpp) | 73 | `guardarEnArchivo` | Guarda el nuevo proveedor en el CSV. |
| [`servicios/ProveedorServicio.cpp`](./servicios/ProveedorServicio.cpp) | 122 | `reescribirArchivo` | Reescribe el archivo al eliminar un proveedor. |
