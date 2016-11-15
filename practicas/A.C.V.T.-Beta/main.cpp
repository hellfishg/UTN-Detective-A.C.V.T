#include "Bibliotecas.h"

#include "ScreenManager.h"

int main(void) {

   if(!al_init()){//Carga los principios de allegro5.Como el constructor.
      al_show_native_message_box (NULL,"Titulo","error","Display window could be show","Botton1",ALLEGRO_MESSAGEBOX_ERROR);
      return -1;
   }

/////////////////////////////////////////////////////////////////////////////////
   ALLEGRO_DISPLAY * display;
   display = al_create_display (800,600);//FinDeJuego Display.

   al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);//resible nativo en la ventana.
   // al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);//Fullscreen en tu resolucion.
   al_set_window_position(display,200,100);//Setea la posicion inicial de la ventana;
   al_set_window_title(display,"El JUEGO");//Nombre de la marquesina en la ventana;

   if (!display) {// El display y muestra cartel si no.
      al_show_native_message_box (display, "Titulo","Settings","Ventana",NULL,ALLEGRO_MESSAGEBOX_ERROR);
      al_rest(0);
      al_destroy_display(display);
      return -1;
   }

////////////////////////////////////////////////////////////////////////////////

   al_install_mouse();//configura el mouse;
   al_init_image_addon();//configura la carga de imagenes por archivo;

///////////////////////////////////////////////////////////////////////////////
   ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();//Cola de eventos.

   //Definicion de tipos de escuchas de eventos:
   al_register_event_source(event_queue, al_get_display_event_source(display));
   al_register_event_source(event_queue, al_get_mouse_event_source());

///////////////////////////////////////////////////////////////////////////////

   ScreenManager screenManager;//FinDeJuegor mostrar pantalla principal primera vez.

   ALLEGRO_EVENT events;
   DatosMouse *punteroMouse=new DatosMouse();
   bool FinDeJuego=false;//Variable que maneja el hilo de ejecucion.

///////////////////////////////////////////////////////////////////////////////

   while(!FinDeJuego){//hilo de ejecucion:

      punteroMouse->CargarDatos(0,0,0);//Limpia el objeto mouse;

      if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
         punteroMouse->CargarDatos(events.mouse.x,events.mouse.y,events.mouse.button);
      }

      if(punteroMouse->getBoton() == 1) {
         FinDeJuego=screenManager.cargarEscena(punteroMouse);
      }
      // if(punteroMouse->getBoton() == 2){
      //    std::cout << "x=" << punteroMouse->getX() << ",y=" << punteroMouse->getY() << std::endl;
      // }//Para ver donde esta el mouse, funcion de debug.

      al_flip_display();

      if (!FinDeJuego) {
            al_wait_for_event (event_queue, &events);//Escucha los eventos:
      }

      if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){//Definicion del evento.
         FinDeJuego=true;
      }
   }
///////////////////////////////////////////////////////////////////////////////

   std::cout << "Salimos" << std::endl;

  //regresa la memoria usada:
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
  // al_destroy_bitmap(player);
  // al_destroy_font(font);

    return 0;
}

//FUNCIONES GLOBALES:
