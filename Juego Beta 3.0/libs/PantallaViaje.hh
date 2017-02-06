#ifndef PANTALLAVIAJE_HH_INCLUDED
#define PANTALLAVIAJE_HH_INCLUDED

#include "Bibliotecas.hh"

class PantallaViaje:public Pantalla {
private:

public:

   PantallaViaje();

   void dibujar(DatosMouse *dm);
   void destruir();

};


///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaViaje::PantallaViaje(){

   this->setID(113);//Colocar la ID de la ventana.




}
///////////////////////////////////////////////////////////////////////
void PantallaViaje::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);
   this->colocarBotones();//Dibuja los botones del vector botones heredado.
/////////////////////////////////////////////////////////////////////////

   this->cargarModuloA("./images/ModuloA_TimeMachine.png");

   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,120,0,"<------FRANCIA, 1489 DC");
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,160,0,"<------EGITPO, 2800 AC");
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,200,0,"<------NUEVO MEJICO, 1800 DC");
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------VOLVER AL MENU ANTERIOR");
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),613,453,0,"4 Time Jumps");

   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
      case 1:
         this->setIDsalto(113);
         std::cout << "Viaje" << std::endl;

      break;

      case 2:
         this->setIDsalto(112);
         std::cout << "Buscar" << std::endl;
      break;

      case 3:
         this->setIDsalto(114);
         std::cout << "Data" << std::endl;
      break;

      case 4:
         this->setIDsalto(12);
         std::cout << "Salir" << std::endl;
      break;

      case 5:
         this->setIDsalto(111);
         this->setZonaIni(1);
         std::cout << "btn 5 "  << this->getZonaIni() << std::endl;
      break;

      case 6:
         this->setIDsalto(111);
         this->setZonaIni(2);
         std::cout << "btn 6 " << this->getZonaIni() << std::endl;
      break;

      case 7:
         this->setIDsalto(111);
         this->setZonaIni(3);
         std::cout << "btn 7 " << this->getZonaIni() << std::endl;
      break;

      case 8:
         this->setIDsalto(0);
         std::cout << "btn 8" << std::endl;
      break;

      case 9:
         this->setIDsalto(0);
         std::cout << "btn 9" << std::endl;
      break;

      case 10:
         this->setIDsalto(111);
         std::cout << "regresar" << std::endl;
      break;

   }



}
///////////////////////////////////////////////////////////////////////
void PantallaViaje::destruir(){

   std::cout << "destruccion de PantallaViaje" << std::endl;

   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////


#endif // PANTALLAVIAJE_HH_INCLUDED

/*
///////////////////////////////////////////////////////////////////////////////////////////
//REFERENCIA MEDIA PARA CARTELES EN BOTONES DEL PANEL B:
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,106,0,"   CARTEL DE PRESENTACION");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,119,0,"<---boton 5");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,160,0,"<---boton 6");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,206,0,"<---boton 7");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,251,0,"<---boton 8");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,290,0,"<---boton 9");

al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,376,0,"<---boton 10");
///////////////////////////////////////////////////////////////////////////////////////////
*/
