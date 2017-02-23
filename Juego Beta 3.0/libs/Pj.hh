#ifndef PJ_HH
#define PJ_HH

#include "Bibliotecas.hh"

class Pj:public Ventana{


private:


    char palabra [30];
    char charito;
    int len;
    ALLEGRO_FONT *font1 = al_load_font("./fonts/orbitron-black.ttf",30,0);

    int aux=0;

public:

    Pj();

    void dibujar(DatosMouse *dm);
    void destruir();

};

///////////////////////////////////////////////////////////////////////
//Metodos:
Pj::Pj(){

 this->setID(117);

 this->cargarDatosVentana(1,al_load_bitmap("./images/PantallaIngreso.png"));

 this->cargarBoton(1,270,505,506,561,al_load_bitmap("./images/Iniciar.jpg"));

}
///////////////////////////////////////////////////////////////////////

void Pj::dibujar(DatosMouse *dm){

//////////////////////////////////////////////////////////////////////////////
this->colocarBotones();
al_draw_bitmap(this->getFondo(),0,0,0);

al_flip_display();



 ALLEGRO_EVENT_QUEUE *EventQueue;
 ALLEGRO_EVENT Event;

 bool Exit = false;

 al_init();
 al_install_keyboard();

 EventQueue = al_create_event_queue();
 al_register_event_source(EventQueue, al_get_keyboard_event_source());

memset(palabra,'\0',30);

while(Exit==false){

   al_wait_for_event(EventQueue, &Event);
   if (Event.type == ALLEGRO_EVENT_KEY_DOWN){

      int entero = Event.keyboard.keycode;

      charito = entero+96;

      std:: cout << charito << std:: endl;


      if(entero >=1 && entero <= 26 || entero == 75){//Es character.

         if(entero == 75){
            charito=' ';
         }

         len=strlen(palabra);
         palabra[len]=charito;
         palabra[len+1]=(char)NULL;

         if(aux<0){
            aux=0;
         }else{
            aux--;
         }
      }

      if(entero == 63){

         palabra[len-aux]=(char)NULL;
         al_draw_bitmap(this->getFondo(),0,0,0);
         al_flip_display();

         aux++;
         if(aux > len){
            aux=0;
         }

      }

      std::cout << palabra << '\n';
      al_draw_text(font1, al_map_rgb(78, 200, 3), 233, 468, 0, palabra);
      al_flip_display();


      if(entero==67){

         Save save;
         save.setNombre(palabra);
         save.grabar();

         this->setIDsalto(11);
         al_draw_bitmap(this->getFondo(),0,0,0);
         al_draw_text(font1, al_map_rgb(78, 200, 3), 233, 468, 0, "NOMBRE ACEPTADO");

         this->colocarBotones();
         al_flip_display();

         Exit=true;

         break;
      }




      //75 espacio
      //63 bakspace
      //67 enter.

   }

}



//////////////////////////////////////////////////////////////////////////////




ALLEGRO_FONT *font = al_load_font("./fonts/orbitron-black.ttf",36,0);//la fuente en la carpeta



/////////////////////////////////////////////////////////////////////////////////////////////
    int selc=comprobarClickBoton(dm);

    switch (selc){
    case 1:
        this->setIDsalto(11);
        std::cout << "Salir" << std::endl;

        Save save;
        std::cout << "El nombre:|" <<save.getNombre()<<"|"<< '\n';
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
