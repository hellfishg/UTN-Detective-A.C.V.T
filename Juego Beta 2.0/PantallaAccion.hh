#ifndef PantallaAccion_HH
#define PantallaAccion_HH

#include "Bibliotecas.hh"

class PantallaAccion:public Ventana {
private:

public:

   PantallaAccion();

   void dibujar(DatosMouse *dm);
   void destruir();

   void cargarPantalla(int,int,int );

};


///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaAccion::PantallaAccion(){

   this->setID(111);//Colocar la ID de la ventana.

   this->cargarDatosVentana(1,al_load_bitmap("12Fon_cargarPartida.jpg"));//El primer dato int pide la cantidad de botones totales.

   //Cargar botones uno a uno:
   this->cargarBoton(1,288,569,503,595,al_load_bitmap("btn12_Volver.png"));


   //Creo un boton transparente para usar de marco.
   //Para decirle el color transparente de una bitmap.

   // ALLEGRO_BITMAP *boteee=al_load_bitmap("Test_transparencia.png");
   //
   // al_convert_mask_to_alpha(boteee,al_map_rgb(255,0,255));
   //
   // this->cargarBoton(2,288,300,289,570,botee);






}
///////////////////////////////////////////////////////////////////////
void PantallaAccion::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);

   this->colocarBotones();//Dibuja los botones del vector botones heredado.


   this->getBoton(1)->setImagen(al_load_bitmap("btn12_Volver.png"));

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
void PantallaAccion::destruir(){

   std::cout << "destruccion de PantallaAccion" << std::endl;

   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////


#endif //PantallaAccion_HH
