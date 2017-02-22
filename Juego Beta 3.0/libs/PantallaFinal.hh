#ifndef PANTALLAFINAL_HH
#define PANTALLAFINAL_HH

#include "Bibliotecas.hh"

class PantallaFinal:public Pantalla {

private:

   Locacion loc;
   int finalSelec=0;
   int btnNext=0;

   void guardarVictoria();//guarda en rankigs.dat si el final fue bueno.

public:

   PantallaFinal();

   void dibujar(DatosMouse *dm);
   void destruir();

};

///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaFinal::PantallaFinal(){

   this->setID(116);//Colocar la ID de la ventana.



}
///////////////////////////////////////////////////////////////////////
void PantallaFinal::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);
   this->colocarBotones();//Dibuja los botones del vector botones heredado.


/////////////////////////////////////////////////////////////////////////

   Save save;

/*   if(save.getSaltosRestantes()<0){
      //Final sin tiempo:

      finalSelec=1;
   }

   if(save.getVida()<0 && finalSelec==0){
      //Final sin vida:

      finalSelec=1;
   }

   if(strcmp(save.getOrdenDeArresto(),save.getVillano())!=0 && finalSelec==0){
      //Final sin orden de arresto:


      finalSelec=1;
   }*/

   if(finalSelec==0){
      //Final victoria:

      char text1[]={"Enhorabuena, has atrapado al villano, ahora será trasladado a los cuarteles de la A.C.V.T, donde será interrogado, y luego encerrado en un tubo criogénico por el resto de sus días, ya que si escapara podría provocar más cambios en la historia. En cuanto a ti, puedes tomarte un merecido descanso, al menos por ahora…."};

      switch (btnNext){

         case 0:


            this->cargarModuloA("./images/Loc_Egipto.jpg");
            this->cargarModuloB("./images/111Panel_b");


            this->cortarString(text1,"",37,417,106,20,78,200,3);

            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------SIGUIENTE");


         break;

         case 1:




         break;

      }

      char text2[]={""};

      this->cortarString(text1,"",37,417,106,20,78,200,3);

      al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------SIGUIENTE");




   }


/////////////////////////////////////////////////////////////////////////
   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
      case 1:
         this->setIDsalto(0);
         std::cout << "Viaje" << std::endl;

      break;

      case 2:
         this->setIDsalto(0);
         std::cout << "Buscar" << std::endl;
      break;

      case 3:
         this->setIDsalto(0);
         std::cout << "Data" << std::endl;
      break;

      case 4:
         this->setIDsalto(14);
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

void  PantallaFinal::guardarVictoria(){


}

////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////


void PantallaFinal::destruir(){

   std::cout << "destruccion de PantallaFinal" << std::endl;


}
///////////////////////////////////////////////////////////////////////


#endif //PantallaFinal_HH


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
