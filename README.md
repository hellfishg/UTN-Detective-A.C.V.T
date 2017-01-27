	# UTN-Detective-A.C.V.T
Proyecto-juego para la universidad, parecido al Carmen Sandiego con toques de RPG.

Historia:Somos parte de la policia temporal y nuestra mision es detener a un delicuente que intenta alterar los hechos historicos mas importantes con el objetivo de dominar el futuro.

-----------------------------------------------------------------------------------------

ARGUMENTO:

Nombre: UTN-Detective-A.C.V.T

Genero: Puzzle/educacional/RPG.
	Proyecto-juego para la universidad, parecido al Carmen Sandiego con toques de RPG.

Historia:Somos parte de la policia temporal y nuestra mision es detener a un delicuente que intenta alterar los hechos historicos mas importantes con el objetivo de dominar el futuro.

-----------------------------------------------------------------------------------------
MECANICA:

	GENERAL: El jugador tendra que atrapar a un delincuente que realiza crimenes en diferentes periodos de la historia. Para ello tendra que derrotar secuaces y interrogarlos para obtener las pistas del rastro dejado por el criminal. Existe un numero finito de saltos que se pueden dar antes de perder, por lo tanto es importante dar la menor cantidad de saltos posibles para atrapar al delincuente. Tambien es util que el jugador pueda interpretar las pistas con menos combates, dado que su vida es limitada tambien y tiene que ser administrada hasta el final de la partida elegiendo entre obtener mas datos o arriesgarse a saltar.

	Ademas el jugador tiene que obtener de estos interrogatorios caracteristicas del delincuente que se esta persiguiendo. Dado que en el momento final de atraparlo (en el ultimo salto) se necesita una identificacion del delincuente con una orden de arrestro. (El jugador tambien puede arriezgar la orden de arresto)

	Jugador:
		*Puede iniciar un nueva partida o cargar una existente.
		*Ingresa un nombre de jugador.
		*Elije alguno de los 3 personajes disponibles, cada uno posee una serie de habilidades distintas que dan cierta ventaja entre los diferentes pjs.
			(vida extra, daño extra, tiempo extra)
		*Puede seleccionar dentro de su interfaz de viaje (InterTravel):
		 	++Investigar un lugar (3 locaciones por sector):
		 		+Se podra elegir 3 locaciones donde se tendra que pelear para obtener una pista.Dicha pista puede ser sutilmente un dato del paradero del siguiente salto y/o descripcion del delincuente.

		 		EL COMBATE:
		 			El combate se basa en el daño del jugador y el daño del secuaz. Primero ataca el jugador y luego el secuaz. Si el jugador puede hacerle igual o mas daño que la vida del secuaz en el primer golpe, entonces saldra sin penalizacion del combate. si el jugador no logra esto, el secuaz golpeara, y reducira la vida del jugador permanentemente.si la vida llega a 0, la partida se pierde automaticamente.

		 	++Viajar a otro zector temporal (4 locaciones por salto):
		 		Apareceran 4 saltos temporales para ir. solo uno de ellos es el camino correcto, otro es el lugar de donde se venia (por si se necesita volver al equibocarse de camino) y los otros dos sera al azar para confundir.
		 		Cada salto consumira el combustible de la nave en 1.
		 		Si el combustible queda en 0,la partida se pierde automaticamente.

		 	++Acceder a la base de datos de criminales:
		 		Se podra revisar la base de datos de todos los criminales conocidos (5 en un principio) Y se podra pedir una orden de arresto para uno de ellos. de esta forma poder atraparlo al final del juego.

		 	++Salir y guardar la partida:
		 		Pide un numbre del archivo a guardar y regresa al menu principal.

		 Victoria:
		 	Una vez atrapado al delincuente, se genera una pantalla de felicitaciones y se guarda el puntaje en el arcvhivo de rankings.
		 	El puntaje se evalua de esta forma:
		 		100 puntos por terminar la partida.
		 		10 puntos por cada punto de vida restante.
		 		30 por cada punto de combustible restante.
		 		20 puntos por cada secuaz vencido en la partida.

		 	Este puntaje sera mostrado al final de la partida y luego agregado al total del perfil del jugador. para poder verse el total en el ranking.
-----------------------------------------------------------------------------------------

Brain Storming:

	*Partidas cortas de 10-15 min aprox.
	*Archivos con pistas de eventos conocidos en la historia de la humanidad.
	*De viajes en el tiempo. Para poder usar texto plano sobre historia.(archivos ver binarios o text)
	*Posibilidad de modificar la historia, al final de la partida se ordena cronologicamente los sucesos ludicos (asignacion de memoria dinamica).
	*Posibilidad de crear un personaje basico con 1 habilidad que le permitan hacer algo especifico.(ventajas y desventajas)
	*Como en el Carmen San Diego, pero cada vez que elejis mal un lugar peleas con un enemigo.(sistema simple pareciodo al juego de cartas chainswan)
	*Combates en los eventos de pistas, similar a un sistema RPG simple (bases de datos de enemigos, estadisticas)
	*Combates randoms en base al reloj del sistema.
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

-----------------------------------------------------------------------------------------

MANEJO DEL GRUPO:

	+Armar las clases y fases del proyecto.
	+github.
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

Estructura de datos:
	-------------------
	|       PJ        |
	-------------------
	CARACTERISTICAS:
	+nombre
	+descripcion
	+descripcion skill
	+path imagen
	+daño
	+vida
	+saltos
	-------------------
	METODOS:
	+getters de todo
	-------------------

	-------------------
	|     SECUAZ      |
	-------------------
	CARACTERISTICAS:
	+path imagen
	+path imagen derrota
	+daño
	+vida total
	+vida actual
	-------------------
	METODOS:
	+getters de todo
	-------------------

	-------------------
	|    VILLANO      |
	-------------------
	CARACTERISTICAS:
	+nombre
	+descripcion
	+imagen path
	||+caracteristica 1
	||+caracteristica 2
	||+caracteristica 3
	*vector pistas consulatado
	-------------------
	METODOS:
	+getters de todo
	-------------------

	-------------------
	| PISTASVILLANOS  |
	-------------------
	CARACTERISTICAS:
	matriz:
		ingles|cazador|mistico|etc..
		pista1|pista1 |pista1 |
		pista2|pista2 |pista2 |
		pista3|etc..
	-------------------

	-------------------
	|    LOCACION     |
	-------------------
	CARACTERISTICAS:
	+nombre
	+descripcion
	+path imagen
	+desc. locacion (1,2,3)
	-------------------
	METODOS:
	+getters de todo
	-------------------


	-------------------
	|    RANKING      |
	-------------------
	CARACTERISTICAS:
	+nombre
	+puntos
	+saltos realizados
	+secuaces derrotados
	+villanos derrotados
	-------------------
	METODOS:
	+getters de todo
	-------------------

	-------------------
	|  CONFIGURACION  |
	-------------------
	CARACTERISTICAS:
	+sonido
	+musica
	+color tipografia
	+sacar presentacion
	-------------------
	METODOS:
	+getters de todo
	-------------------

	-------------------
	|      SAVE       |
	-------------------
	CARACTERISTICAS:

	+nom. jugador
	+vida actual
	+saltos rest
	+pj en uso
	+villano
	+loc.actual
	+loc.hechas (1,2,3)

	+orden de arresto (bool)
	||+caracteristica 1
	||+caracteristica 2
	||+caracteristica 3


	|+saltos hechos
	|+saltos realizados por lugar (ver final historial)
	|+secuaces derrotados.

	-------------------
	METODOS:
	+getters de todo
	-------------------
