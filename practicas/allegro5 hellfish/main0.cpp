#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>//Carga ventanas nativas del sistama
using namespace std;

//iniciar el display
ALLEGRO_DISPLAY *display;


ALLEGRO_TIMER *timer;





int main(void) {

   al_init();
   al_install_mouse();//instancia el mouse.

   timer= al_create_timer (1.0 / 60);//Crea el FPS.
   display = al_create_display (800,600);//el tamaño de la ventana.

   if(!al_init()){
      al_show_native_message_box (NULL,"Titulo","error","Display window could be show","Botton1",ALLEGRO_MESSAGEBOX_ERROR);

   } //Carga los principios de allegro5.Como el constructor.

   if (!display) {//se instancia el display y muestra.
      al_show_native_message_box (display, "Titulo","Settings","Ventana",NULL,ALLEGRO_MESSAGEBOX_ERROR);

   }

   ALLEGRO_BITMAP *imagen;

   imagen= al_load_bitmap ("pepe.png");

   while (true) {//Todo el codigo:

      //al_draw_bitmap(imagen,0,0);





   }








    return 0;
}
