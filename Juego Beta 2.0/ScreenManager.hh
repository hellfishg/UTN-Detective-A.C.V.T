#ifndef SCREENMANAGER_HH
#define SCREENMANAGER_HH

#include "Bibliotecas.hh"

class ScreenManager {
private:

   Ventana *ventanaActual;
   bool esMenuPrincipal;
public:

   ScreenManager(DatosMouse *dm);

   bool cargarEscena(DatosMouse *);

};



///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//Metodos:

ScreenManager::ScreenManager(DatosMouse * dm){

   ventanaActual=new MenuPrincipal();
   ventanaActual->dibujar(dm);
   esMenuPrincipal=true;

}
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
bool ScreenManager::cargarEscena(DatosMouse *dm){

   bool retorno=false;

   int seleccion = ventanaActual->obtenerBotonClick(dm);//si es zero no clickeo en un boton valido.


   if(seleccion!=0){

      ventanaActual->destruir();

      switch(seleccion){
         case 1://Siempre el boton 1 va ser el definido para Salir de cada ventana.
            if(esMenuPrincipal){
               //Salir del MenuPrincipal y del juego.
               retorno=true;

            }else{
               ventanaActual=new MenuPrincipal();
               esMenuPrincipal=true;
            }
            break;

         case 2:

            ventanaActual = new MenuRanking();
            esMenuPrincipal=false;
            break;

         case 3:
            // ventanaActual = new MenuCargar();
            //esMenuPrincipal=false;
            break;
      }


      ventanaActual->dibujar(dm);
      return retorno;
   }

}
///////////////////////////////////////////////////////////////////////



#endif //SCREENMANAGER_HH
