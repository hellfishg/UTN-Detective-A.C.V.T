#ifndef BIBLIOTECAS_HH
#define BIBLIOTECAS_HH

//De sistema:
#include <iostream>
#include <cstdio>
#include "string.h"
#include "stdlib.h"//libreria para usar rand

//Externas:
#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>//Agrega fonts
#include <allegro5/allegro_ttf.h>//Agrega ttf.

//Clases de Base de datos:
#include "../libs/Save.hh"
#include "../libs/Pj.hh"
#include "../libs/PistasVillanos.hh"
#include "../libs/Villano.hh"
#include "../libs/Secuaz.hh"
#include "../libs/Locacion.hh"
#include "../libs/Ranking.hh"

//Menues:
#include "../libs/DatosMouse.hh"
#include "../libs/Boton.hh"
#include "../libs/Ventana.hh"
#include "../libs/MenuPrincipal.hh"
#include "../libs/MenuCargar.hh"
#include "../libs/MenuRanking.hh"
#include "../libs/NuevaPartida.hh"
#include "../libs/MenuOpciones.hh"

//Pantallas de gamplay:
#include "../libs/Pantalla.hh"
#include "../libs/PantallaInicial.hh"
#include "../libs/PantallaAccion.hh"
#include "../libs/PantallaBusqueda.hh"
#include "../libs/PantallaViaje.hh"
#include "../libs/PantallaData.hh"
#include "../libs/PantallaCombate.hh"
#include "../libs/PantallaFinal.hh"


#endif //BIBLIOTECAS_HH
