#include "Utils.h"
#include "../servicios/ClienteServicio.h"
#include "../servicios/VehiculoServicio.h"
#include "../servicios/ProveedorServicio.h"
#include "../servicios/GastoReparacionServicio.h"
#include "../servicios/VentaServicio.h"

void calcularDiferenciaDeTiempo(int fechaInicio, int* diferenciaTiempo)
{
	int anioActual = 2026;
	*diferenciaTiempo = anioActual - fechaInicio;
}

void cargarDatosDePrueba()
{
	// ─── Clientes ─────────────────────────────────────────────────────────────
	ClienteServicio clienteServicio;
	if(clienteServicio.obtenerClientes().empty())
	{
		struct { const char* nombre; const char* dir; const char* tel; const char* correo; int anio; } cls[] = {
			{"Carlos Mendoza",   "Av. Reforma 101 CDMX",     "5551234567", "carlos.m@email.com",  2020},
			{"Sofia Ramirez",    "Calle Juarez 45 Monterrey", "8181234567", "sofia.r@email.com",   2019},
			{"Luis Torres",      "Blvd. Diaz Ordaz 88 GDL",  "3331234567", "luis.t@email.com",    2021},
			{"Ana Flores",       "Insurgentes Sur 500 CDMX",  "5557654321", "ana.f@email.com",     2018},
			{"Roberto Vega",     "Av. Hidalgo 200 Puebla",    "2221234567", "roberto.v@email.com", 2022},
		};
		for(auto& c : cls)
		{
			Cliente cl;
			cl.nombre    = c.nombre;
			cl.direccion = c.dir;
			cl.telefono  = c.tel;
			cl.correo    = c.correo;
			calcularDiferenciaDeTiempo(c.anio, &cl.tiempoComoCliente);
			clienteServicio.agregarCliente(cl);
		}
	}

	// ─── Proveedores ──────────────────────────────────────────────────────────
	ProveedorServicio proveedorServicio;
	if(proveedorServicio.obtenerProveedores().empty())
	{
		struct { const char* nombre; const char* contacto; const char* dir; const char* tel; } pvs[] = {
			{"Autos Siniestrados SA",  "Pedro Guzman",   "Zona Industrial Norte 1",    "5559001234"},
			{"Reconstrucciones MX",    "Maria Lopez",    "Blvd. del Valle 320 MTY",    "8189001234"},
			{"Importadora AutoPiezas", "Jorge Herrera",  "Parque Industrial Bajio GTO","4629001234"},
			{"SurAutos Recuperacion",  "Diana Castillo", "Av. del Ejercito 77 OAX",    "9519001234"},
			{"NorteStock Vehicular",   "Alan Soto",      "Calle Texcoco 15 CDMX",      "5559005678"},
		};
		for(auto& p : pvs)
		{
			Proveedor pv;
			pv.nombre    = p.nombre;
			pv.contacto  = p.contacto;
			pv.direccion = p.dir;
			pv.telefono  = p.tel;
			proveedorServicio.agregarProveedor(pv);
		}
	}

	// ─── Vehiculos ────────────────────────────────────────────────────────────
	VehiculoServicio vehiculoServicio;
	if(vehiculoServicio.obtenerVehiculos().empty())
	{
		struct {
			int anio; const char* desc; const char* marca; const char* modelo;
			const char* color; const char* ver; const char* km;
			const char* estado; const char* aseg; float precioC; double precioA; bool rep;
		} vehs[] = {
			{2019,"Choque frontal severo","Toyota", "Corolla","Blanco","LE",    "42000","Moderado","HDI Seguros",  195000, 85000,  true },
			{2021,"Perdida total trasera","Honda",  "Civic",  "Gris",  "Sport", "28000","Severo",  "GNP Seguros",  220000, 95000,  true },
			{2020,"Robo con recuperacion","Nissan", "Versa",  "Rojo",  "Sense", "61000","Leve",    "Qualitas",     145000, 58000,  true },
			{2022,"Granizo severo techo", "Mazda",  "CX-5",   "Negro", "iSport","15000","Moderado","AXA Seguros",  390000, 165000, false},
			{2018,"Inundacion motor",     "Hyundai","Tucson", "Azul",  "GLS",   "74000","Severo",  "ANA Seguros",  175000, 72000,  false},
			{2023,"Choque lateral",       "Kia",    "Sportage","Plata","LX",    "9000", "Leve",    "Seguros Atlas",480000, 210000, false},
		};
		for(auto& v : vehs)
		{
			Vehiculo veh;
			veh.anio             = v.anio;
			veh.descripcion      = v.desc;
			veh.marca            = v.marca;
			veh.modelo           = v.modelo;
			veh.color            = v.color;
			veh.version          = v.ver;
			veh.kilometraje      = v.km;
			veh.estado           = v.estado;
			veh.aseguradora      = v.aseg;
			veh.precioCliente    = v.precioC;
			veh.precioAdquisicion = v.precioA;
			veh.reparado         = false; // agregarVehiculo siempre lo fuerza a false
			Vehiculo vehGuardado = vehiculoServicio.agregarVehiculo(veh);

			// Si el vehiculo debe estar marcado como reparado, lo actualizamos
			if(v.rep)
				vehiculoServicio.marcarComoReparado(vehGuardado.id);
		}
	}

	// ─── Gastos de Reparacion ─────────────────────────────────────────────────
	GastoReparacionServicio gastoServicio;
	if(gastoServicio.obtenerGastos().empty())
	{
		// Usamos los IDs que se generaron (ultimoId arranca en 101)
		// Los vehiculos 1,2,3 estan reparados (IDs 101,102,103)
		// Los vehiculos 4,5,6 estan en taller (IDs 104,105,106)
		struct { int vehId; const char* desc; double monto; } gastos[] = {
			{101, "Hojalateria delantera",    12500.0},
			{101, "Pintura completa",          8900.0},
			{101, "Vidrio parabrisas",         3200.0},
			{102, "Cajuela y defensa trasera", 9800.0},
			{102, "Pintura zona trasera",      6500.0},
			{103, "Desbloqueo motor ECU",       4200.0},
			{103, "Llantas nuevas x4",         11000.0},
			{103, "Limpieza y detallado",       1800.0},
			{104, "Planchas de techo x3",      14000.0},
			{105, "Limpieza motor completa",    5500.0},
			{105, "Mangueras y empaques",       3100.0},
			{106, "Puerta lateral derecha",     7200.0},
			{106, "Pintura zona lateral",       5800.0},
		};
		for(auto& g : gastos)
		{
			GastoReparacion gr;
			gr.vehiculoId  = g.vehId;
			gr.descripcion = g.desc;
			gr.monto       = g.monto;
			gastoServicio.agregarGasto(gr);
		}
	}

	// ─── Ventas ───────────────────────────────────────────────────────────────
	VentaServicio ventaServicio;
	if(ventaServicio.obtenerVentas().empty())
	{
		// Vendemos los vehiculos que ya estan reparados (IDs 101, 102, 103)
		// a los primeros clientes (IDs 1001, 1002, 1003)
		struct { int vehId; int cliId; double precioAdq; double gastos; double precioVenta; } ventas[] = {
			{101, 1001, 85000.0,  24600.0, 195000.0}, // Toyota Corolla
			{102, 1002, 95000.0,  16300.0, 220000.0}, // Honda Civic
			{103, 1003, 58000.0,  17000.0, 145000.0}, // Nissan Versa
		};
		for(auto& v : ventas)
		{
			Venta vt;
			vt.vehiculoId       = v.vehId;
			vt.clienteId        = v.cliId;
			vt.precioAdquisicion = v.precioAdq;
			vt.totalGastos      = v.gastos;
			vt.precioVenta      = v.precioVenta;
			ventaServicio.registrarVenta(vt);
		}
	}
}