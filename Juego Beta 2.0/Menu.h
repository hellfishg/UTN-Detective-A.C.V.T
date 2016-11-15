#ifndef MENU_H
#define MENU_H

#include "Bibliotecas.h"

class Menu {

private:
   ALLEGRO_BITMAP *fondo,*botones,*guybrush;

   int pantallaActual;//static mantiene su valor dentro de cargar.
   int seleccionDelmouse (int ,int );
   bool clickEnRectangulo(int ,int,int,int,int, int);

public:

   Menu();


   void cargarPantalla(int,int,int );

};

///////////////////////////////////////////////////////////////////////
//Metodos:
Menu::Menu(){

	pantallaActual=0;
   fondo= al_load_bitmap("fondoMenu.png");
   botones= al_load_bitmap("botones.png");
   guybrush=al_load_bitmap ("guybrush.png");

}

///////////////////////////////////////////////////////////////////////
bool Menu::clickEnRectangulo(int xM,int yM,int x1,int y1,int x2, int y2){

   bool retorno=false;

   if (xM>x1 && xM<x2 && yM>y1 && yM<y2){retorno=true;}

   return retorno;
}
///////////////////////////////////////////////////////////////////////
int Menu::seleccionDelmouse (int x,int y){

   int retorno=0;

   switch (pantallaActual) {


      case 1:
         if (retorno == 0 && clickEnRectangulo(x,y,10,10,250,250)){
            retorno=2;
         }
      break;

      default:
         if (retorno == 0 && clickEnRectangulo(x,y,546,255,706,296)) {retorno=1;}

         if (retorno == 0 && clickEnRectangulo(x,y,563,553,690,590)) {retorno=5;}
         break;
   }


   return retorno;
}
///////////////////////////////////////////////////////////////////////

void Menu::cargarPantalla(int x,int y,int bn){







   pantallaActual=seleccionDelmouse(x,y);

   switch (pantallaActual) {
      case 0:
      al_draw_bitmap(fondo,0,0,0);
      al_draw_bitmap(botones,400,200,0);
      break;

      case 1:
      al_clear_to_color(al_map_rgb(0, 0, 0));

      al_draw_bitmap(fondo,0,0,0);
      al_draw_bitmap(botones,400,200,0);

         al_draw_bitmap(guybrush,10,10,0);
         std::cout << "ups" << std::endl;
         break;
      case 2:
      al_clear_to_color(al_map_rgb(0, 0, 0));

      al_draw_bitmap(fondo,0,0,0);
      al_draw_bitmap(botones,400,200,0);
            al_draw_bitmap(botones,10,10,0);
            break;

      case 5:

         std::cout << "Se fue por aca!" << std::endl;

         break;
   }



}



#endif //MENU_H

/*Las pantallas esta numeradas segun el orden de seleccion. Cada opcion del menu
posee un numero que sera utilizado para conformar el numero final de pantalla.

EJ: El menu principal seria la pantalla 0 y posee 4 opciones. Cada opcion seria
de 1 al 4. generando las pantallas 1,2,3,4.

Si preciono la opcion 1, la pantalla siguiente sera 1-1 o 1-2 1-3.
Si dentro de la 1-2 seguimos pasando menues. seran agregados al menu correspondiente.
por ejemplo 1-2-1 ,1-2-2. 1-2-3 etc.

De esta forma se tiene un orden logico de los menues, y si se quiere agregar un menu, no hay que andar moviendo todas las selecciones.
*/
