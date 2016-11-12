#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>//Carga ventanas nativas del sistama//es un addom.
#include <allegro5/allegro_image.h>

class Ventana {
//Encargado del manejo de las visualizacion y propiedades de la ventana visible.
private:
   ALLEGRO_DISPLAY *display;
   int alto;
   int ancho;

public:

   Ventana (int alt,int anc){

      alto=alt;
      ancho=anc;

      al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);//resible nativo en la ventana.
     //al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);//Fullscreen en tu resolucion.


     display = al_create_display (ancho,alto);//Instancia Display.

     al_set_window_position(display,200,100);//setea la posicion inicial de la ventana;
     al_set_window_title(display,"El JUEGO");//Nombre de la marquesina en la ventana;

     if (!display) {// el display y muestra cartel si no.
        al_show_native_message_box (display, "Titulo","Settings","Ventana",NULL,ALLEGRO_MESSAGEBOX_ERROR);
        al_rest(1);
        al_destroy_display(display);
     }

        al_clear_to_color(al_map_rgb(17, 45, 106));//refresca la pantalla. Necesita flip_display para hacer esto visible.


   }

   ALLEGRO_DISPLAY * getDisplay(){return display;}


};

class Menu {
private:
   /* ACA ME QUEDE; VER COMO IMPLEMENTAR INSTANCIAS*/
public:
   Menu (void);
   virtual ~Menu ();

};

int main(void) {

   if(!al_init()){//Carga los principios de allegro5.Como el constructor.
      al_show_native_message_box (NULL,"Titulo","error","Display window could be show","Botton1",ALLEGRO_MESSAGEBOX_ERROR);
      return -1;
   }

   Ventana ven (600,800);

   al_flip_display();//Refresca los cambios acumulados y los visibiliza.
////////////////////////////////////////////////////////////////////////////////

   ALLEGRO_COLOR azulElectrico = al_map_rgb(44,117,255);
   ALLEGRO_COLOR amarillo = al_map_rgb(255,255,0);

   al_install_mouse();//instancia el mouse.
   al_init_image_addon();

   ALLEGRO_BITMAP *player =al_load_bitmap("guybrush.png");


   bool done=false;//Variable que maneja el hilo de ejecucion.

   int x;//Mouse
   int y;//Mouse

///////////////////////////////////////////////////////////////////////////////
   ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();//Cola de eventos.
   //Definicion de tipos de escuchas de eventos:
   al_register_event_source(event_queue, al_get_display_event_source(ven.getDisplay()));
   al_register_event_source(event_queue, al_get_mouse_event_source());


///////////////////////////////////////////////////////////////////////////////
      while(!done){//hilo de ejecucion:

         ALLEGRO_EVENT events;
         al_wait_for_event (event_queue, &events);//Escucha los eventos:

         if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){//Definicion del evento.

            done=true;
         }

         if(events.type == ALLEGRO_EVENT_MOUSE_AXES){

            x= events.mouse.x;
            y= events.mouse.y;
         }

         if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){

            if(events.mouse.button & 1){
               al_draw_bitmap(player, x, y, 0);

            }

            if(events.mouse.button & 2){

            }
         }



         al_flip_display();

      }
///////////////////////////////////////////////////////////////////////////////




     //regresa la memoria usada:
     al_destroy_display(ven.getDisplay());
     al_destroy_event_queue(event_queue);
     al_destroy_bitmap(player);

    return 0;
}

//FUNCIONES GLOBALES:



/////////////////////////////////////////////////////////////////////////////////
//ALLEGRO ADDONS:
/////////////////////////////////////////////////////////////////////////////////
   //Ventanitas de error nativas:
   // #include <allegro5/allegro_native_dialog.h>//Carga ventanas nativas del sistama//es un addom.
   //
   // al_show_native_message_box (display,"TituloRR","Error Critico!!","Porque si.","BUENO",ALLEGRO_MESSAGEBOX_ERROR); //Crea una advertencia sobre algo.

/////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
   //Cargar fuentes: Definir antes los includes y compilador:
   // #include <allegro5/allegro_ttf.h>//Agrega ttf.
   // #include <allegro5/allegro_font.h>//Agrega fonts


/* al_init_font_addon();
      al_init_ttf_addon();

      ALLEGRO_FONT *font = al_load_font("Orbitron black.ttf",36,1);//la fuente en la carpeta
      al_draw_text(font, al_map_rgb(44,117,255),ScreenWidth /2 ,ScreenWeight /2 ,
       ALLEGRO_ALIGN_CENTRE, "www.codingmadeeasy.ca");

      al_flip_display();
      al_destroy_font(font);*/
////////////////////////////////////////////////////////////////////////////////
