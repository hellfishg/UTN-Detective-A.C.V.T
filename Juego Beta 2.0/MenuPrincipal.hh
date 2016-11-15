#ifndef MENUPRINCIPAL_HH
#define MENUPRINCIPAL_HH

#include "Bibliotecas.hh"

class MenuPrincipal:public Ventana{

private:

   // int seleccionDelmouse (int ,int );
   //bool clickEnRectangulo(int ,int,int,int,int, int);

public:

   MenuPrincipal();

   void dibujar(DatosMouse *dm);
   void destruir();

   void cargarPantalla(int,int,int );

};

///////////////////////////////////////////////////////////////////////
//Metodos:
MenuPrincipal::MenuPrincipal(){

   this->setID(0);//Colocar la ID de la ventana.

   this->cargarDatosVentana(2,al_load_bitmap("fondoMenu.png"));//El primer dato int pide la cantidad de botones totales.

   //Cargar botones uno a uno:
   this->cargarBoton(1,546,706,255,296,al_load_bitmap("Boton_3.png"));

   this->cargarBoton(2,546,706,300,340,al_load_bitmap("Boton_2.png"));

}
///////////////////////////////////////////////////////////////////////
void MenuPrincipal::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);

   this->colocarBotones();//Dibuja los botones del vector botones heredado.


   int selc=comprobarClickBoton(dm);

   switch (selc) {
      case 1:
         this->setIDsalto(14);
         std::cout << "Ranking" << std::endl;
      break;

      case 2:
         this->setIDsalto(-1);
         std::cout << "Salir" << std::endl;
      break;
   }



}
///////////////////////////////////////////////////////////////////////
void MenuPrincipal::destruir(){

   std::cout << "destruccion de menuPrincipal" << std::endl;

   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////


#endif //MenuPrincipal_H
