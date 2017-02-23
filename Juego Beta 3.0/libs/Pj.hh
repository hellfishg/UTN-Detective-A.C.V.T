#ifndef PJ_HH
#define PJ_HH

#include "Bibliotecas.hh"

class Pj:public Ventana{


   private:

   public:

       Pj();

       void dibujar(DatosMouse *dm);
       void destruir();

   };

   ///////////////////////////////////////////////////////////////////////
   //Metodos:
   Pj::Pj(){

       this->setID(14);

       this->cargarDatosVentana(1,al_load_bitmap("./images/PantallaIngreso.png"));

       this->cargarBoton(1,300,500,450,560,al_load_bitmap("./images/VolverMenu.jpg"));

   }
   ///////////////////////////////////////////////////////////////////////

   void Pj::dibujar(DatosMouse *dm)
   {


       al_draw_bitmap(this->getFondo(),0,0,0);
       this->colocarBotones();

       ALLEGRO_FONT *font = al_load_font("./fonts/orbitron-black.ttf",36,0);//la fuente en la carpeta
       ALLEGRO_FONT *font2 = al_load_font("./fonts/orbitron-black.ttf",24,0);




       al_draw_text(font, al_map_rgb(255, 255, 255), 400, 10, ALLEGRO_ALIGN_CENTER, "LOS MEJORES!!");


/////////////////////////////////////////////////////////////////////////////////////////////
       int selc=comprobarClickBoton(dm);

       switch (selc){
       case 1:
           this->setIDsalto(1);
           std::cout << "Salir" << std::endl;
           break;
       }

   }
   ///////////////////////////////////////////////////////////////////////
   void Pj::destruir()
   {

       std::cout << "destruccion de ranking" << std::endl;

   }
   ///////////////////////////////////////////////////////////////////////


   ////////////////////////////////////////////////////////////////////////
#endif //PJ_HH
