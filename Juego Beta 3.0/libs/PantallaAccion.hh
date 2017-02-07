#ifndef PANTALLAACCION_HH
#define PANTALLAACCION_HH

#include "Bibliotecas.hh"

class PantallaAccion:public Pantalla {

private:

public:

   PantallaAccion();

   void dibujar(DatosMouse *dm);
   void destruir();

   void cargarLocacion();


};


///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaAccion::PantallaAccion(){

   this->setID(111);//Colocar la ID de la ventana.

   //this-setLocacion(1);


}
///////////////////////////////////////////////////////////////////////
void PantallaAccion::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);
   this->colocarBotones();//Dibuja los botones del vector botones heredado.
/////////////////////////////////////////////////////////////////////////

   this->cargarLocacion();





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
         this->setIDsalto(0);
         std::cout << "btn 5" << std::endl;
      break;

      case 6:
         this->setIDsalto(0);
         std::cout << "btn 6" << std::endl;
      break;

      case 7:
         this->setIDsalto(0);
         std::cout << "btn 7" << std::endl;
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
         this->setIDsalto(0);
         std::cout << "regresar" << std::endl;
      break;

   }



}
///////////////////////////////////////////////////////////////////////
void PantallaAccion::cargarLocacion(){

   switch (this->getZonaIni()) {

      case 1:
         this->cargarModuloA("./images/ModuloA_Bastilla.png");
        //  . Durante varios siglos cumpli� un papel fundamental en la defensa de la ciudad, pero con el pas�
         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,106,0,"La Bastilla o Bastilla de San Antonio");
         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,126,0,"fue una fortaleza que protegia");
         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,146,0,"el costado oriental de la ciudad de");
         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,166,0,"Paris.");

         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),100,59,0,"Francia - 1489");

         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),613,453,0,"4 Time Jumps");
      break;

      case 2:
         this->cargarModuloA("./images/ModuloA_Piramides.png");

         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,106,0,"La Gran piramide de Guiza es la mas");
         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,126,0,"antigua de las Siete maravillas del ");
         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,146,0,"mundo y la unica que aun perdura.");

         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),100,59,0,"Egipto - 1500 AC");

         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),613,453,0,"4 Time Jumps");

      break;

      case 3:
         this->cargarModuloA("./images/ModuloA_Lejano.png");

         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,106,0,"Viejo Oeste, Antiguo Oeste, Salvaje ");
         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,126,0,"Oeste son los terminos con que se ");
         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,146,0,"denomina a los hechos historicos que");
         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,166,0,"tuvieron lugar en el siglo XIX EEUU");

         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),100,59,0,"EEUU - 1810");

         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),613,453,0,"4 Time Jumps");

      break;
   }


}

////////////////////////////////////////////////////////////////////////
void PantallaAccion::destruir(){

   std::cout << "destruccion de PantallaAccion" << std::endl;

   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////



#endif //PantallaAccion_HH


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

//this->getBoton(1)->setImagen(al_load_bitmap("btn12_Volver.png"));

///////////////////////////////////////////////////////////////////////

//Creo un boton transparente para usar de marco.
//Para decirle el color transparente de una bitmap.

// ALLEGRO_BITMAP *boteee=al_load_bitmap("Test_transparencia.png");
//
// al_convert_mask_to_alpha(boteee,al_map_rgb(255,0,255));
//
// this->cargarBoton(2,288,300,289,570,botee);
