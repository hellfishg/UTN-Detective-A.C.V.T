#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "Bibliotecas.h"

class ScreenManager {
private:
   // int pantalla;
   // Menu menu;
   Ventana *ventanaActual;

public:

   ScreenManager();

   void cargarEscena(DatosMouse *);

};


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//Metodos:

ScreenManager::ScreenManager(){

   ventanaActual=new MenuPrincipal();
   ventanaActual->dibujar();
}
///////////////////////////////////////////////////////////////////////////
//Preparar ventana:
///////////////////////////////////////////////////////////////////////////
//Dibujar ventana:

///////////////////////////////////////////////////////////////////////////
void ScreenManager::cargarEscena(DatosMouse *dm){


   int seleccion = ventanaActual->obtenerBotonClick(dm);//si es zero no clickeo en un boton valido.

   if(seleccion!=0)
   {
      ventanaActual->destroy();

      switch(seleccion)
      {
         case 1:
            ventanaActual = new MenuOpciones();
            break;
         case 2:
            ventanaActual = new MenuRanking();
            break;
         case 3:
            ventanaActual = new MenuCargar();
            break;
      }

      ventanaActual->dibujar();
   }



}
///////////////////////////////////////////////////////////////////////



#endif //SCREENMANAGER_H
