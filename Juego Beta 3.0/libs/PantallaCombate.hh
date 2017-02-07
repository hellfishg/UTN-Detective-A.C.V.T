#ifndef PANTALLACOMBATE_HH_INCLUDED
#define PANTALLACOMBATE_HH_INCLUDED

#include "Bibliotecas.hh"

class PantallaCombate:public Pantalla {
private:

   int inicio=0;
   int modo;
   Secuaz sec;

   int vidaSecuaz;//borrar.
public:

   PantallaCombate();
   void setVida (int v){vidaSecuaz = v;}//Borrar.

   void dibujar(DatosMouse *dm);
   void destruir();

   void graficosIniciales();

};


///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaCombate::PantallaCombate(){

   this->setID(115);//Colocar la ID de la ventana.

   vidaSecuaz = 1;//borrar
}
///////////////////////////////////////////////////////////////////////

void PantallaCombate::dibujar(DatosMouse * dm){

   ALLEGRO_BITMAP *lifeH = al_load_bitmap("./images/111Vida_100.png");// Vida del heroe
   ALLEGRO_BITMAP *lifeV = al_load_bitmap("./images/111Vida_100.png");// Vida del villano

   al_draw_bitmap(lifeH,438,43,0);

   if (vidaSecuaz == 1){

      al_draw_bitmap(lifeV,80,45,0);
      this->setVida(2);
   }
   
if(inicio==0){

   //al_draw_bitmap(this->getFondo(),0,0,0);


   this->colocarBotones();//Dibuja los botones del vector botones heredado.

   graficosIniciales();

   modo=0;
   inicio++;
}

/////////////////////////////////////////////////////////////////////////

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
            switch (vidaSecuaz)
            {
            case 2:
                lifeV = al_load_bitmap("./images/111Vida_50.png");
                al_draw_bitmap(lifeV,80,45,0);
                this->setVida(3);
                break;

            case 3:
                lifeV = al_load_bitmap("./images/111Vida_25.png");
                al_draw_bitmap(lifeV,80,45,0);
                this->setVida(4);
                break;

            case 4:
                lifeV = al_load_bitmap("./images/111Vida_0.png");
                al_draw_bitmap(lifeV,80,45,0);

                al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,370,0,"HE MORIDO!!!!! ");
                al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,400,0,"MI JEFE ESTA EN EGIPTO ");
                this->setIDsalto(111);

                break;
            }
      break;

      case 6:
         //this->setIDsalto(111);
         //std::cout << "btn 6 - Destino2" << std::endl;
      break;

      case 7:
         //this->setIDsalto(111);
         //std::cout << "btn 7 - Destino3" << std::endl;
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
         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),29,370,0,"NO PUEDES ESCAPAR!!");
      break;

   }

}
///////////////////////////////////////////////////////////////////////
void PantallaCombate::graficosIniciales(){

   sec.randomSecuaz();

   this->cargarModuloA(sec.getImagen());

   this->cargarModuloB("./images/111Panel_b.png");

   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,120,0,"<------ATACAR");
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,160,0,"<------DEFENDER");
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,200,0,"<------USAR HABILIDAD ESPECIAL");
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------VOLVER AL MENU ANTERIOR");
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),613,453,0,"4 Time Jumps");


}
///////////////////////////////////////////////////////////////////////
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
