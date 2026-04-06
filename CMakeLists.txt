# CMakeList.txt: proyecto de CMake para AutosJJ
cmake_minimum_required (VERSION 3.10)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("AutosJJ")

add_executable (AutosJJ
	"AutosJJ.cpp"
	"AutosJJ.h"

	# ─── Includes ────────────────────────────────────────────────────────
	"includes/Constantes.h"
	"includes/PantallaEnum.h"
	"includes/vistas.h"

	# ─── Utilidades ──────────────────────────────────────────────────────
	"utilidades/IO.h"
	"utilidades/IO.cpp"
	"utilidades/EditorCSV.h"
	"utilidades/EditorCSV.cpp"
	"utilidades/Utils.h"
	"utilidades/Utils.cpp"

	# ─── Modelos ─────────────────────────────────────────────────────────
	"modelos/Cliente.h"
	"modelos/Vehiculo.h"
	"modelos/CostosVehiculo.h"
	"modelos/GastoReparacion.h"
	"modelos/Proveedor.h"
	"modelos/Venta.h"

	# ─── Servicios ───────────────────────────────────────────────────────
	"servicios/ClienteServicio.h"
	"servicios/ClienteServicio.cpp"
	"servicios/VehiculoServicio.h"
	"servicios/VehiculoServicio.cpp"
	"servicios/GastoReparacionServicio.h"
	"servicios/GastoReparacionServicio.cpp"
	"servicios/ProveedorServicio.h"
	"servicios/ProveedorServicio.cpp"
	"servicios/VentaServicio.h"
	"servicios/VentaServicio.cpp"

	# ─── Vistas base ─────────────────────────────────────────────────────
	"vistas/inicio.cpp"
	"vistas/login.cpp"
	"vistas/dashboard.cpp"
	"vistas/otros.cpp"

	# ─── Vistas Clientes ─────────────────────────────────────────────────
	"vistas/clientes/clientes.cpp"
	"vistas/clientes/listarClientes.cpp"
	"vistas/clientes/registrarClientes.cpp"
	"vistas/clientes/buscarClienteId.cpp"
	"vistas/clientes/buscarClienteNombre.cpp"
	"vistas/clientes/eliminarClienteId.cpp"

	# ─── Vistas Proveedores ──────────────────────────────────────────────
	"vistas/proveedores/proveedores.cpp"
	"vistas/proveedores/listarProveedores.cpp"
	"vistas/proveedores/registrarProveedor.cpp"
	"vistas/proveedores/buscarProveedorId.cpp"
	"vistas/proveedores/eliminarProveedor.cpp"

	# ─── Vistas Vehiculos ────────────────────────────────────────────────
	"vistas/vehiculos/vehiculos.cpp"
	"vistas/vehiculos/listarVehiculos.cpp"
	"vistas/vehiculos/registrarVehiculo.cpp"
	"vistas/vehiculos/buscarVehiculoId.cpp"
	"vistas/vehiculos/buscarVehiculoMarca.cpp"
	"vistas/vehiculos/marcarReparado.cpp"

	# ─── Vistas Taller ───────────────────────────────────────────────────
	"vistas/taller/taller.cpp"
	"vistas/taller/agregarGasto.cpp"
	"vistas/taller/verGastos.cpp"

	# ─── Vistas Inventario ───────────────────────────────────────────────
	"vistas/inventario/inventario.cpp"

	# ─── Vistas Ventas ───────────────────────────────────────────────────
	"vistas/ventas/ventas.cpp"
	"vistas/ventas/registrarVenta.cpp"
	"vistas/ventas/listarVentas.cpp"

	# ─── Vistas Reportes ─────────────────────────────────────────────────
	"vistas/reportes/reportes.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AutosJJ PROPERTY CXX_STANDARD 20)
endif()

# Expone la raíz del proyecto como macro para que el código pueda construir rutas absolutas
target_compile_definitions(AutosJJ PRIVATE PROJECT_ROOT="${CMAKE_SOURCE_DIR}/")
