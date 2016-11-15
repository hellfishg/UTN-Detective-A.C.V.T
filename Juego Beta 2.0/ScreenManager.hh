#ifndef SCREENMANAGER_HH
#define SCREENMANAGER_HH

#include "Bibliotecas.hh"

class ScreenManager {
private:

   Ventana *ventanaActual;
   bool esMenuPrincipal;
public:

   ScreenManager(DatosMouse *dm);

   int cargarEscena(DatosMouse *);

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
int ScreenManager::cargarEscena(DatosMouse *dm){


   int selec= ventanaActual->getIDsalto();//0 no cambio.-1 salir del sistema.


   if (selec!=0 && selec!=-1){

      ventanaActual->destruir();

      switch (selec) {

         case 1:

            ventanaActual=new MenuPrincipal();

            break;

         case 11:

            ventanaActual=new NuevaPartida();

            break;

         case 12:

            ventanaActual=new MenuCargar();

            break;

         case 13:

            ventanaActual=new MenuOpciones();

            break;

         case 14:

            ventanaActual=new MenuRanking();

            break;

      }
   }

   ventanaActual->dibujar(dm);
   return selec;
}
///////////////////////////////////////////////////////////////////////



#endif //SCREENMANAGER_HH
