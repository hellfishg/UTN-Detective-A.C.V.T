#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>//Carga ventanas nativas del sistama
using namespace std;

ALLEGRO_DISPLAY *display;

int main(void) {



   ALLEGRO_DISPLAY *display;//Se crea el puntero display.

   if(!al_init()){
      al_show_native_message_box (NULL,"Titulo","error","Display window could be show","Botton1",ALLEGRO_MESSAGEBOX_ERROR);

   } //Carga los principios de allegro5.Como el constructor.

   display = al_create_display (800,600);//el tamaño de la ventana.

   if (!display) {//se instancia el display y muestra.
      al_show_native_message_box (display, "Titulo","Settings","Ventana",NULL,ALLEGRO_MESSAGEBOX_ERROR);

   }

    al_show_native_message_box (display,"Titulo","errorm error","Error del semental","Botton1",ALLEGRO_MESSAGEBOX_ERROR);
    al_show_native_message_box (display,"Titulo","errorm error","Error del semental","Botton1",ALLEGRO_MESSAGEBOX_WARN);
    al_show_native_message_box (display,"Titulo","errorm error","Error del semental","Botton1",ALLEGRO_MESSAGEBOX_QUESTION);
    al_show_native_message_box (display,"Titulo","errorm error","Error del semental","Botton1",ALLEGRO_MESSAGEBOX_OK_CANCEL);
    al_show_native_message_box (display,"Titulo","errorm error","Error del semental","Botton1",ALLEGRO_MESSAGEBOX_YES_NO);
   //  al_clear_to_color(al_map_rgb(255,0,0));
   //  al_flip_display();

     al_rest(1); //cierra el display.


     al_destroy_display(display);//regresa la memoria usada.

    return 0;
}
