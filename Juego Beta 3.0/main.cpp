#include "./libs/Bibliotecas.hh"
#include "./libs/ScreenManager.hh"

int main(void) {

   if(!al_init()){//Carga los principios de allegro5.Como el constructor.
      al_show_native_message_box (NULL,"Titulo","error","Se rompio la ventana","Botton1",ALLEGRO_MESSAGEBOX_ERROR);
      return -1;
   }

/////////////////////////////////////////////////////////////////////////////////
   ALLEGRO_DISPLAY * display;
   //al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);//resizable nativo en la ventana.//
   //al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);//Fullscreen en tu resolucion.
   display = al_create_display (800,600);//FinDeJuego Display.

   al_set_window_position(display,0,0);//setea la posicion inicial de la ventana;
   al_set_window_title(display,"Detective A.C.V.T");//Nombre de la marquesina en la ventana;

   if (!display) {// el display y muestra error si no cargo.
      al_show_native_message_box (display, "Titulo","Settings","Ventana",NULL,ALLEGRO_MESSAGEBOX_ERROR);
      al_rest(0);
      al_destroy_display(display);
      return -1;
   }


////////////////////////////////////////////////////////////////////////////////

   al_install_mouse();//configura el mouse;
   al_init_image_addon();//configura la carga de imagenes por archivo;
   al_init_font_addon();
   al_init_ttf_addon();
   
   srand(time(0));//Carga la semilla de random.


///////////////////////////////////////////////////////////////////////////////
   ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();//Cola de eventos.

   //Definicion de tipos de escuchas de eventos:
   al_register_event_source(event_queue, al_get_display_event_source(display));
   al_register_event_source(event_queue, al_get_mouse_event_source());

///////////////////////////////////////////////////////////////////////////////
   DatosMouse *punteroMouse=new DatosMouse();


   ScreenManager screenManager(punteroMouse);//FinDeJuegor mostrar pantalla principal primera vez.


   ALLEGRO_EVENT events;
   int FinDeJuego=0;//Variable que maneja el hilo de ejecucion.

///////////////////////////////////////////////////////////////////////////////

   while(FinDeJuego!=-1){//hilo de ejecucion:
      al_wait_for_event (event_queue, &events);//Escucha los eventos:

      punteroMouse->CargarDatos(0,0,0);//Limpia el objeto mouse;

      if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){//Definicion del evento.
         FinDeJuego=-1;
      }
      if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
         punteroMouse->CargarDatos(events.mouse.x,events.mouse.y,events.mouse.button);
      }

      if(events.type == ALLEGRO_EVENT_MOUSE_WARPED){
         //no se, era para arreglar lo del doble clic   k.
      }

      if(punteroMouse->getBoton() == 1) {
         FinDeJuego=screenManager.cargarEscena(punteroMouse);
      }
      if(punteroMouse->getBoton() == 2){
         std::cout << "x=" << punteroMouse->getX() << ",y=" << punteroMouse->getY() << std::endl;
      }//Para ver donde esta el mouse, funcion de debug.


      al_flip_display();
   }
///////////////////////////////////////////////////////////////////////////////


   std::cout << "Salimos" << std::endl;

  //regresa la memoria usada:
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
  // al_destroy_bitmap(   );
  // al_destroy_font(   );

    return 0;
}

//FUNCIONES GLOBALES:
