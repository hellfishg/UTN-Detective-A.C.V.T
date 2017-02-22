#ifndef PANTALLACOMBATE_HH_INCLUDED
#define PANTALLACOMBATE_HH_INCLUDED

#include "Bibliotecas.hh"

class PantallaCombate:public Pantalla {
private:

   int inicio=0;
   int modo;
   Secuaz sec;
   char randPistaVillano[200];


   ALLEGRO_BITMAP *lifeV;
   ALLEGRO_BITMAP *lifeH;


   void refrescarPantalla();

   void dibujarVidaSecuaz();//calcula y dibuja la vida del secuaz.
   void dibujarPista();//dibuja la pista cuando el secuaz muere.

   void ataque();

public:

   PantallaCombate();

   void dibujar(DatosMouse *dm);
   void destruir();



};

///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaCombate::PantallaCombate(){

   this->setID(115);//Colocar la ID de la ventana.

}
///////////////////////////////////////////////////////////////////////

void PantallaCombate::dibujar(DatosMouse * dm){

   al_draw_bitmap(al_load_bitmap("./images/111Fondo.png"),0,0,0);

   if(inicio==0){

      this->colocarBotones();//Dibuja los botones del vector botones heredado.

      sec.randomSecuaz();

      int ran=rand()%10+1;
      if(ran<=5){//Genera una pista random de villano para este secuaz.

         strcpy(randPistaVillano,sec.obtenerPista());

      }else{

         strcpy(randPistaVillano,"");
      }

      modo=0;
      inicio++;
   }

   refrescarPantalla();

   Save save;

   if (sec.getVidaActual() == 0){//vida llega a 0:

      std::cout << "Secuaz Muerto" << '\n';

      dibujarPista();

      save.setSecuacesDerrotados(save.getSecuDerrotados()+1);

      save.grabar();

   }else{

      al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,120,0,"<------ ATACAR");
      al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------ VOLVER AL MENU ANTERIOR");
   }

/////////////////////////////////////////////////////////////////////////

   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
      case 1:
         std::cout << "Viaje" << std::endl;
         if (sec.getVidaActual() > 0){

            this->setIDsalto(0);
            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,445,0,"NO ESCAPARAS!!");
            al_flip_display();//refresca la pantalla.
            al_rest(1.0);//pone en pausa el juego

         }else{
            this->setIDsalto(113);
         }
      break;

      case 2:
         std::cout << "Buscar" << std::endl;
         if (sec.getVidaActual() > 0){

            this->setIDsalto(0);
            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,445,0,"NO ESCAPARAS!!");
            al_flip_display();//refresca la pantalla.
            al_rest(1.0);//pone en pausa el juego

         }else{
            this->setIDsalto(112);
         }
      break;

      case 3:
         std::cout << "Data" << std::endl;
         if (sec.getVidaActual() > 0){

            this->setIDsalto(0);
            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,445,0,"NO ESCAPARAS!!");
            al_flip_display();//refresca la pantalla.
            al_rest(1.0);//pone en pausa el juego

         }else{
            this->setIDsalto(114);
         }
      break;

      case 4:
         std::cout << "Salir" << std::endl;
         if (sec.getVidaActual() > 0){

            this->setIDsalto(0);
            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,445,0,"NO ESCAPARAS!!");
            al_flip_display();//refresca la pantalla.
            al_rest(1.0);//pone en pausa el juego

         }else{
            this->setIDsalto(1);
         }
      break;

      case 5:
         this->setIDsalto(0);
         std::cout << "btn 5 Ataque!" << '\n';

         if (sec.getVidaActual() > 0){

            ataque();

         }

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

            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,445,0,"NO ESCAPARAS!!");
            al_flip_display();//refresca la pantalla.
            al_rest(1.0);//pone en pausa el juego

         }else{

            this->setIDsalto(112);
         }
      break;

   }
}
///////////////////////////////////////////////////////////////////////
void PantallaCombate::refrescarPantalla(){

   Save save;

   al_draw_bitmap(al_load_bitmap("./images/111Fondo.png"),0,0,0);

   this->cargarModuloA(sec.getImagen());

   this->cargarModuloB("./images/111Panel_b.png");

   this->jumpsTimes(save.getSaltosRestantes());

   dibujarVidaSecuaz();

   this->vidaHeroe();

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
void PantallaCombate::dibujarPista(){

   Save save;

   Locacion loc;

   FILE *p=fopen("./Dat/Locaciones.dat","rb");
   if(p==NULL){
      std::cout << "NO SE PUEDO ABRIR LOCACIONES:DAT!!" << '\n';
   }

   while(fread(&loc,sizeof(Locacion),1,p)){

      if(strcmp(save.getLugarPista(),loc.getNombre())==0){

         break;
      }
   }
   fclose(p);



   ////////ejemplo de pista:

   this->cargarModuloB("./images/111Panel_b.png");

   this->cortarString(loc.getPistas(save.getSectorActual()),randPistaVillano,37,421,106,20,78,200,3);

   al_draw_text(this->getFont(),al_map_rgb(78,200,3),417,376,0,"<----- VOLVER AL MENU ANTERIOR");
}
//////////////////////////////////////////////////////////////////////

void PantallaCombate::destruir(){

   std::cout << "destruccion de PantallaCombate" << std::endl;

}
///////////////////////////////////////////////////////////////////////

void PantallaCombate::ataque(){

   Save save;

   std::cout << "***********************" << '\n';
   std::cout << "GOLPE: " << save.getDano()<<" - " <<sec.getVidaActual() << " :VIDA"<<'\n';

   sec.golpear(save.getDano());//golpea al villano.

   std::cout << "HP:" << sec.getVidaActual()<< '\n';
   std::cout << "***********************" << '\n';

   //animacion:


   ALLEGRO_BITMAP *golpe3;
   golpe3 = al_load_bitmap("./images/Golpe3.png");
   al_convert_mask_to_alpha(golpe3, al_map_rgb(255, 0, 255));//convierte trasparente al fucia;

   ALLEGRO_BITMAP *golpe2;
   golpe2 = al_load_bitmap("./images/Golpe2.png");
   al_convert_mask_to_alpha(golpe2, al_map_rgb(255, 0, 255));//convierte trasparente al fucia;

   ALLEGRO_BITMAP *golpe1;
   golpe1 = al_load_bitmap("./images/Golpe1.png");
   al_convert_mask_to_alpha(golpe1, al_map_rgb(255, 0, 255));//convierte trasparente al fucia;

   ALLEGRO_BITMAP *golpe;
   golpe = al_load_bitmap("./images/Golpe.png");
   al_convert_mask_to_alpha(golpe, al_map_rgb(255, 0, 255));//convierte trasparente al fucia;

   al_draw_bitmap(golpe,124,194,0);
   al_flip_display();//refresca la pantalla.
   al_rest(0.2);//pone en pausa el juego

   refrescarPantalla();

   al_draw_bitmap(golpe1,124,194,0);
   al_flip_display();//refresca la pantalla.
   al_rest(0.2);//pone en pausa el juego

   refrescarPantalla();

   al_flip_display();//refresca la pantalla.
   al_rest(0.5);//pone en pausa el juego.

   this->cargarModuloA(sec.getImagen());

   ///////Hasta aca el golpe del jugador

   save.golpear(sec.getDano());
   save.grabar();

   dibujarVidaSecuaz();
   al_flip_display();

   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,445,0,"ESO ME DOLIO!!");

   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,460,0,"TOMA ESTO!!!");
   al_flip_display();//refresca la pantalla.

   al_rest(1.1);//pone en pausa el juego

   this->cargarModuloA("./images/111Panel_a.png");
   this->cargarModuloA(sec.getImagen());
   //al_flip_display();//refresca la pantalla.

   al_draw_bitmap(golpe2,1,1,0);
   al_flip_display();//refresca la pantalla.
   al_rest(0.2);//pone en pausa el juego

   refrescarPantalla();

   al_draw_bitmap(golpe3,1,1,0);
   al_flip_display();//refresca la pantalla.
   al_rest(0.2);//pone en pausa el juego

   if(save.getVida()<=0){

      this->setIDsalto(116);
   }


}

//////////////////////////////////////////////////////////////////////

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
