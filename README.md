# UTN-Detective-A.C.V.T
Proyecto-juego para la universidad, parecido al Carmen Sandiego con toques de RPG.

Historia:Somos parte de la policia temporal y nuestra mision es detener a un delicuente que intenta alterar los hechos historicos mas importantes con el objetivo de dominar el futuro.

-----------------------------------------------------------------------------------------

Brain Storming:

	*Partidas cortas de 15-20 min aprox.
	*Archivos con pistas de eventos conocidos en la historia de la humanidad.
	*De viajes en el tiempo. Para poder usar texto plano sobre historia.(archivos ver binarios o text)
	*Posibilidad de modificar la historia, al final de la partida se ordena cronologicamente los sucesos ludicos (asignacion de memoria dinamica).
	*Posibilidad de crear un personaje basico con 4 habilidades que le permitan hacer algo especifico.(ventajas y desventajas)
	*Como en el Carmen San Diego, pero cada vez que elejis mal un lugar peleas con un enemigo.(sistema simple pareciodo al juego de cartas chainswan)
	*Combates en los eventos de pistas, similar a un sistema RPG simple (bases de datos de enemigos, estadisticas)
	*Combates randoms en base al reloj del sistema.
	*Sistema de daños basado en dados.
	*Sistema de HP simple.
	*Creacion de imagenes de locaciones, menus, fotos enemigos, personajes etc.
	*Sistema de records y perfil, basado en el tiempo y hp final del personaje.

	*OPC: Ver posibilidad de comprar items especiales que ayuden en estos combates.
	*Tiempo limite de saltos temporales hasta un cambio en la historia catastrofico.(tal vez tu jefe se convierte en el enemigo y te despide al final del tiempo :P)
-----------------------------------------------------------------------------------------

Herramientas utilizadas:

	+Asignacion de memoria dinamica- para poder construir el vector de sucesos modificados historicos del juego.
	+creacion de objetos enemigos concierto grado de randomicidad. (+20 hp -20 hp)
	+Manejo de imagenes- para mostrar las locaciones y efectos de daño.
	+Sonidos.
	+Manejo de archivos- Para tener la base de datos de la historia y los registros utilizados.
	+Manejo de archivos- Para rankings.
	+Manejo de archivos- Para enemigos.
	+Manejo de archivos- Para PJ (personjes jugadores)
	+Clases, Objetos, Herencias- Para crear las instancias repetidas y la estructura de programa.
-----------------------------------------------------------------------------------------

LIBRERIAS DE USO (INVESTIGACION):

	+++ALLEGRO: Multiplataforma, Recomendada por simplicidad para tareas simples (crear ventanas, etc), especalizada en 2D.
	+SFML:Lireria programada en c++, recomndada por su simpleza. Multiplataforma.(impresindible ahora me parece),Sofware Libre.
	+Cocos2d-X: Libreria multiplataforma (incluso IOs y android), dicen que es la mejor actualmente para 2D.
	+SDL: Es una libreria antigua orientada en C.
-----------------------------------------------------------------------------------------

MANEJO DEL GRUPO:

	+Armar las clases y fases del proyecto.
	+Delegar los clases y trabajos.
	+Ver trabajar online pantallas divididas (hangOut)
	+Creacion de espacio de trabajo en Dropbox.
	+Independizar el diagrama, de presentacion vs los que estan codeando o metidos en el proyecto. (Ver la operancia del protoInforme)
	+Balance del juego.
-----------------------------------------------------------------------------------------

DIAGRAMA DE CLASES:

	Caracteristicas:
	+resolucion 1024x768
	+Imagenes JPG.
	
	+Clase Presentacion:
		*Imagen/es Texto ascendente.(tiene que cortar con cualquier tecla)
	
	+Clase menu principal:
		*Imagen de fondo.
		*Menu opciones.
			+Nueva partida.
				Borrar save.
			+Cargar Partida.
			+Ranking.
			+Opciones.
				+musica off/on.
				+color del texto.
				+Borrar ranking.
				+modo cheaters. (con clave)
					+Modo dios.
					+tiempo infinito.
					+daño 9999.

	+Clases ventanaPrincipal de tipo abstrac:
		*Fecha actual marge arriba.
		*Tiempo restante.
		*Manejo de graficos.
		*Grafico Tablero de circuitos electronico.
		*Botones cerrar,minimizar.
		*Propiedades y posiciones de los paneles.
			*Panel 1: Imagen estatica de lugar, animaciones, Enemigo foto.
			*Panel 2: Va ir el texto, La descripcion del combate. barras de vida daño.
			*Panel 3: Botonera de opciones,de combate, viaje, computadora.

	+Clase panel 1/Animaciones:
		+Manejo de imagenes:
			+Imagen estatica del lugar.
			+animacion del salto del tiempo.
			+Imagen del enemigo.
			+Imagen de la ficha del sospechoso.
			+Animacion sobre la imagen del enemigo, del daño.
			+Imagen del personaje en la seleccion.
			
	+Clase panel 2/caracteristicas:
		+Texto de ubicacion.
		+Combate datos (barra de vida, daños)
		+Opciones de viaje.
		+Descripcion de ficha del sospechoso.
		+Descripcion de las pistas/locaciones.
		
	+Clase Panel 3/botonera:
		+Botones y opciones.
		+Boton de BACK.
		*MODOS:
			+Modo comun:
				+btn: Viajes:
					+btn:1,2,3 ubicaciones.
					+btn:BACK.

				+btn: Busqueda:
					*btn: Locaciones 3:
						+Combate:
							+btn: atacar.
							+btn: usar item.
					
				+btn: Data:
					+btn: Orden arresto:
						+Menu desplegable para elegir caracteristicas.
						+btn: Pedir Orden de arresto.
						+btn: BACK.
					+btn: Base de datos criminales conocidos.
						+btn: next/prev.
						+btn: BACK.
					+btn: Personaje/items.
						+btn: BACK.
						
				+btn: guardar/salir.
					

	+Clase Game over:
		*Perder:
			*cinematica tu jefe es el malo.
			*Borrar save.

		*Ganar:
			*Cinematica atrapaste al delincuente.
			*Ranking (vida+tiempo restante)
			*Borrar save.
-----------------------------------------------------------------------------------------

ARCHIVOS REGISTROS:
	
	+Carpeta recursos.(las imagenes)
	+Carpeta que tenga (las clases)
	+Carpeta archivos reg.
	+Carpeta musica.
	
	recursos:
		+imagenes enemigos.
		+imagenes interfaz ventana.
		+imagenes lugares.
		+imagenes PJ.
		+imagenes sprites.
		+imagenes botones.
		+imagenes textos.
		+imagen puntero.
		+imagenes tipografia.
		+imagenes fondos. (Menu,intro,final/bueno/malo).
		+imagenes items.

	musica:
		+sonidos botones.
		+sonidos golpes.
		+sonido viaje temporal.
		+musicas.

	registros:
		puntuaciones.
			
		vidas enemigos.
		vida personaje.

		tiempo restante.
		daño enmigos.
		daño personaje.

		textos locaciones.
		locaciones temporales.

		registro save.

		items.
		textos de descripcion de personeje.

		base de datos de delincuentes.

		registro fecha estelar.
		
		configuracion.

		archivo historia modificada.


