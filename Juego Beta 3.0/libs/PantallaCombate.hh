#ifndef PANTALLACOMBATE_HH_INCLUDED
#define PANTALLACOMBATE_HH_INCLUDED

#include "Bibliotecas.hh"

class PantallaCombate:public Pantalla {
private:

   int inicio=0;
   int modo;
   Secuaz sec;

   ALLEGRO_BITMAP *lifeV;
   ALLEGRO_BITMAP *lifeH;

public:

   PantallaCombate();

   void dibujar(DatosMouse *dm);
   void destruir();

   void graficosIniciales();

   void dibujarVidaSecuaz();//calcula y dibuja la vida del secuaz.

};

///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaCombate::PantallaCombate(){

   this->setID(115);//Colocar la ID de la ventana.

}
///////////////////////////////////////////////////////////////////////

void PantallaCombate::dibujar(DatosMouse * dm){

   if(inicio==0){

      this->colocarBotones();//Dibuja los botones del vector botones heredado.

      graficosIniciales();

      modo=0;
      inicio++;
   }

   Save save;
   this->jumpsTimes(save.getSaltosRestantes());

   dibujarVidaSecuaz();

   if (sec.getVidaActual() == 0){//vida llega a 0:

      std::cout << "Secuaz Muerto" << '\n';

      ////////ejemplo de pista:

      this->cargarModuloB("./images/111Panel_b.png");

      char pistaLoc[60]={"Mi maestro se fue a un lugar donde no te da el sol."};

      char randPistaVillano[60]={" ...Pero antes fue a comprar balas para la escopeta. jeje!"};

      this->cortarString(pistaLoc,randPistaVillano,37,421,106,20,78,200,3);

      al_draw_text(this->getFont(),al_map_rgb(78,200,3),417,376,0,"<----- VOLVER AL MENU ANTERIOR");
   }

/////////////////////////////////////////////////////////////////////////

   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
      case 1:
         std::cout << "Viaje" << std::endl;
         if (sec.getVidaActual() > 0){

            this->setIDsalto(0);
            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,370,0,"NO VOY A DEJAR QUE TE ESCAPES!!");

         }else{
            this->setIDsalto(113);
         }
      break;

      case 2:
         std::cout << "Buscar" << std::endl;
         if (sec.getVidaActual() > 0){

            this->setIDsalto(0);
            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,370,0,"NO VOY A DEJAR QUE TE ESCAPES!!");

         }else{
            this->setIDsalto(112);
         }
      break;

      case 3:
         std::cout << "Data" << std::endl;
         if (sec.getVidaActual() > 0){

            this->setIDsalto(0);
            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,370,0,"NO VOY A DEJAR QUE TE ESCAPES!!");

         }else{
            this->setIDsalto(114);
         }
      break;

      case 4:
         std::cout << "Salir" << std::endl;
         if (sec.getVidaActual() > 0){

            this->setIDsalto(0);
            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,370,0,"NO VOY A DEJAR QUE TE ESCAPES!!");

         }else{
            this->setIDsalto(12);
         }
      break;

      case 5:
         this->setIDsalto(0);
         std::cout << "btn 5 Ataque!" << '\n';

         std::cout << "***********************" << '\n';
         std::cout << "GOLPE: " << save.getDano()<<" - " <<sec.getVidaActual() << " :VIDA"<<'\n';

         sec.golpear(save.getDano());//golpea al villano.

         std::cout << "HP:" << sec.getVidaActual()<< '\n';
         std::cout << "***********************" << '\n';

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
         std::cout << "btn 10" << std::endl;
         if (sec.getVidaActual() > 0){

            this->setIDsalto(0);
            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,370,0,"NO VOY A DEJAR QUE TE ESCAPES!!");

         }else{
            this->setIDsalto(112);
         }
      break;

   }
}
///////////////////////////////////////////////////////////////////////
void PantallaCombate::graficosIniciales(){

   sec.randomSecuaz();//crea un secuaz random.

   this->cargarModuloA(sec.getImagen());

   this->cargarModuloB("./images/111Panel_b.png");

   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,120,0,"<------ ATACAR");
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------ VOLVER AL MENU ANTERIOR");

   Save save;
   this->jumpsTimes(save.getSaltosRestantes());

}
///////////////////////////////////////////////////////////////////////

void PantallaCombate::dibujarVidaSecuaz(){

   char vida[4];
   int n=sec.getVidaActual();

   sprintf(vida,"%d",n);

   char path[25]={"./images/vida_"};
   char extencion[5]={".jpg"};

   strcat(path,vida);
   strcat(path,extencion);

   std::cout << "Path vida secuaz|" << path<<"|" <<'\n';

   lifeV = al_load_bitmap( path );
   al_draw_bitmap(lifeV,29,45,0);

};

//////////////////////////////////////////////////////////////////////

void PantallaCombate::destruir(){

   std::cout << "destruccion de PantallaCombate" << std::endl;

   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////

#endif // PANTALLACOMBATE_HH_INCLUDED

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
