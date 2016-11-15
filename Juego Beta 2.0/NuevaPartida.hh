#ifndef NUEVAPARTIDA_HH
#define NUEVAPARTIDA_HH

#include "Bibliotecas.hh"

class NuevaPartida:public Ventana{

private:


public:

   NuevaPartida();

   void dibujar(DatosMouse *dm);
   void destruir();

   void cargarPantalla(int,int,int );

};

///////////////////////////////////////////////////////////////////////
//Metodos:
NuevaPartida::NuevaPartida(){

   this->setID(11);//Colocar la ID de la ventana.

   this->cargarDatosVentana(3,al_load_bitmap("11Fondo.png"));//El primer dato int pide la cantidad de botones totales.

   //Cargar botones uno a uno:
   this->cargarBoton(1,500,560,713,600,al_load_bitmap("btn11_transparente.png"));

   this->cargarBoton(2,413,560,476,600,al_load_bitmap("btn11_flecha_izq.png"));

   this->cargarBoton(3,735,561,800,600,al_load_bitmap("btn11_flecha_der.png"));


}
///////////////////////////////////////////////////////////////////////
void NuevaPartida::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);

   this->colocarBotones();//Dibuja los botones del vector botones heredado.

   ALLEGRO_FONT *font = al_load_font("orbitron-black.ttf",12,0);
   al_draw_text(font, al_map_rgb(78, 200, 3), 400, 10, ALLEGRO_ALIGN_CENTER, "asdsa");

   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
      case 1:
         this->setIDsalto(0);
         std::cout << "Iniciar Partida" << std::endl;
      break;

      case 2:
         this->setIDsalto(0);
         std::cout << "boton izq" << std::endl;
      break;

      case 3:
         this->setIDsalto(0);
         std::cout << "boton der" << std::endl;
      break;

      case 4:
         this->setIDsalto(14);
         std::cout << "Ranking" << std::endl;
      break;

      case 5:
         this->setIDsalto(-1);
         std::cout << "Salir del Sistema" << std::endl;
      break;
   }




}
///////////////////////////////////////////////////////////////////////
void NuevaPartida::destruir(){

   std::cout << "destruccion de NuevaPartida" << std::endl;

   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////


#endif //NuevaPartida_HH
