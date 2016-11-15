#ifndef MENUCARGAR_HH
#define MENUCARGAR_HH

#include "Bibliotecas.hh"

class MenuCargar:public Ventana {
private:

public:

   MenuCargar();

   void dibujar(DatosMouse *dm);
   void destruir();

   void cargarPantalla(int,int,int );

};


///////////////////////////////////////////////////////////////////////
//Metodos:
MenuCargar::MenuCargar(){

   this->setID(12);//Colocar la ID de la ventana.

   this->cargarDatosVentana(2,al_load_bitmap("FondoCargar.jpeg"));//El primer dato int pide la cantidad de botones totales.

   //Cargar botones uno a uno:
   this->cargarBoton(1,546,706,255,296,al_load_bitmap("Boton_3.png"));

   this->cargarBoton(2,546,706,300,340,al_load_bitmap("Boton_2.png"));

}
///////////////////////////////////////////////////////////////////////
void MenuCargar::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);

   this->colocarBotones();//Dibuja los botones del vector botones heredado.


   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
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
void MenuCargar::destruir(){

   std::cout << "destruccion de MenuCargar" << std::endl;

   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////


#endif //MenuCargar_HH
