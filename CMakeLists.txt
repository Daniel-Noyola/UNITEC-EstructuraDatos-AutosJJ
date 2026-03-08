# CMakeList.txt: proyecto de CMake para AutosJJ, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.10)

# Habilite Recarga activa para los compiladores de MSVC si se admiten.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("AutosJJ")

# Agregue un origen al ejecutable de este proyecto.
add_executable (AutosJJ 
	"AutosJJ.cpp"
	"AutosJJ.h"
	"includes/Constantes.h"
	"includes/PantallaEnum.h"
	"includes/vistas.h"
	"utilidades/IO.h"
	"utilidades/IO.cpp"
	"utilidades/EditorCSV.h"
	"utilidades/EditorCSV.cpp"
	"vistas/inicio.cpp"
	"vistas/login.cpp"
	"vistas/dashboard.cpp"
	"vistas/otros.cpp"
	"vistas/clientes/clientes.cpp"
	"vistas/clientes/listarClientes.cpp"
	"vistas/clientes/registrarClientes.cpp"
	"modelos/Cliente.h") 

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AutosJJ PROPERTY CXX_STANDARD 20)
endif()

# Expone la raíz del proyecto como macro para que el código pueda construir rutas absolutas
target_compile_definitions(AutosJJ PRIVATE PROJECT_ROOT="${CMAKE_SOURCE_DIR}/")

# TODO: Agregue pruebas y destinos de instalación si es necesario.
