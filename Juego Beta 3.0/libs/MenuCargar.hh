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

   this->cargarDatosVentana(1,al_load_bitmap("./images/12Fon_cargarPartida.jpg"));//El primer dato int pide la cantidad de botones totales.

   //Cargar botones uno a uno:
   this->cargarBoton(1,288,569,503,595,al_load_bitmap("./images/btn12_Volver.png"));

}
///////////////////////////////////////////////////////////////////////
void MenuCargar::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);

   this->colocarBotones();//Dibuja los botones del vector botones heredado.

   this->getBoton(1)->setImagen(al_load_bitmap("./images/btn12_Volver.png"));

   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
      case 1:
         this->setIDsalto(1);
         std::cout << "Menu Principal" << std::endl;
      break;

      case 2:
         this->setIDsalto(-1);
         std::cout << "Cargar save" << std::endl;
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
