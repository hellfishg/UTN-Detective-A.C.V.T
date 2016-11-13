#ifndef MENURANKING_H
#define MENURANKING_H

#include "Bibliotecas.h"

class MenuRanking:public Ventana{

private:

   // int seleccionDelmouse (int ,int );
   bool clickEnRectangulo(int ,int,int,int,int, int);

public:

   MenuRanking();

   void dibujar();
   void destruir();

   void cargarPantalla(int,int,int );

};

///////////////////////////////////////////////////////////////////////
//Metodos:
MenuRanking::MenuRanking(){


   this->cargarDatosVentana(1,al_load_bitmap("fondoMenu.png"));

   this->cargarBoton(1,300,500,355,395,al_load_bitmap("Boton_1.png"));

/*   al_init_font_addon();
   al_init_ttf_addon();
   ALLEGRO_FONT *font = al_load_font("orbitron-black.ttf",12,0);//la fuente en la carpeta*/


/////////////////////////////////////////////////////////////////////////////




}
///////////////////////////////////////////////////////////////////////
void MenuRanking::dibujar(){



   al_draw_bitmap(this->getFondo(),0,0,0);

   Boton *botTemp;

   for(int i=0;i<this->getCantBotones();i++){

      botTemp=this->getBoton(i);
      al_draw_bitmap(botTemp->getImagen(),botTemp->getXIzq(),botTemp->getYSup(),0);


   }
   // al_draw_bitmap(botones,400,200,0);
}
///////////////////////////////////////////////////////////////////////
void MenuRanking::destruir(){

   std::cout << "destruccion de todo el mundo todos" << std::endl;

}
///////////////////////////////////////////////////////////////////////



#endif //MENURANKING_H

/*Las pantallas esta numeradas segun el orden de seleccion. Cada opcion del menu
posee un numero que sera utilizado para conformar el numero final de pantalla.

EJ: El menu principal seria la pantalla 0 y posee 4 opciones. Cada opcion seria
de 1 al 4. generando las pantallas 1,2,3,4.

Si preciono la opcion 1, la pantalla siguiente sera 1-1 o 1-2 1-3.
Si dentro de la 1-2 seguimos pasando menues. seran agregados al menu correspondiente.
por ejemplo 1-2-1 ,1-2-2. 1-2-3 etc.

De esta forma se tiene un orden logico de los menues, y si se quiere agregar un menu, no hay que andar moviendo todas las selecciones.
*/