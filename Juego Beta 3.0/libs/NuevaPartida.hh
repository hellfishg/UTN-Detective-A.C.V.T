#ifndef NUEVAPARTIDA_HH
#define NUEVAPARTIDA_HH

#include "Bibliotecas.hh"

class NuevaPartida:public Ventana{

private:
   int PJ=1;


public:

   NuevaPartida();

   void dibujar(DatosMouse *dm);
   void destruir();

   void cargarPantalla(int,int,int );

   int seleccionPJ(int s);


};

///////////////////////////////////////////////////////////////////////
//Metodos:
NuevaPartida::NuevaPartida(){

   this->setID(11);//Colocar la ID de la ventana.

   this->cargarDatosVentana(4,al_load_bitmap("./images/11Fondo.png"));//El primer dato int pide la cantidad de botones totales.

   //Cargar botones uno a uno:
   this->cargarBoton(1,500,560,713,600,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(2,413,560,476,600,al_load_bitmap("./images/btn11_flecha_izq.png"));

   this->cargarBoton(3,735,561,800,600,al_load_bitmap("./images/btn11_flecha_der.png"));

   this->cargarBoton(4,26,7,184,32,al_load_bitmap("./images/btn_transparente.png"));

   PJ=1;
}
///////////////////////////////////////////////////////////////////////
void NuevaPartida::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);
   this->colocarBotones();//Dibuja los botones del vector botones heredado.

   ALLEGRO_FONT *font1;

   //Boton volver e iniciar.
   font1 = al_load_font("./fonts/orbitron-black.ttf",15,0);
   al_draw_text(font1, al_map_rgb(78, 200, 3), 71, 17, 0, "VOLVER");
   al_draw_text(font1, al_map_rgb(78, 200, 3), 540,574, 0, "INICIAR PARTIDA");
//////////////////////////////////////////////////////////////////


   if(PJ==4){PJ=1;}
   if(PJ==0){PJ=3;}

   seleccionPJ(PJ);


/////////////////////////////////////////////////////////////////////

   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
      case 1:
         this->setIDsalto(15);
         std::cout << "Iniciar Partida" << std::endl;

      break;

      case 2:
         PJ--;
         std::cout << "boton izq" << std::endl;
      break;

      case 3:
         PJ++;
         std::cout << "boton der" << std::endl;
      break;

      case 4:
         this->setIDsalto(1);
         std::cout << "salir" << std::endl;
      break;
   }


   al_destroy_font(font1);

}
///////////////////////////////////////////////////////////////////////
int NuevaPartida::seleccionPJ(int s){

   ALLEGRO_BITMAP *retrato;
   ALLEGRO_FONT *font1;

   Save save;
   save.setPj(s);//Salva el pj elegido.
   save.grabar();

   int selec=s;

   switch (s){

      case 1:
         retrato=al_load_bitmap("./images/Pj_Jerome.jpeg");
         al_draw_bitmap(retrato,462,33,0);

         //En archivo:
         font1 = al_load_font("./fonts/orbitron-black.ttf",12,0);

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,337, 0, "JHON TITOR: Nació en Irlanda del Norte en el año");

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,357, 0, "1845 y vivió toda su infancia en un orfanato.");

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,377, 0,"Fue reclutado  a la edad de 17 años por el Coronel");

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,397, 0,"Smith al notar su potencial.");

         //En archivo:
         font1 = al_load_font("./fonts/orbitron-black.ttf",12,0);
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,464, 0, "+Viajero experimentado: Reduce el costo");
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,477, 0, "de cada salto temporal");
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,528, 0, "-Pensador: Empieza con menos vida.");


      break;

      case 2:
         retrato=al_load_bitmap("./images/Pj_Catlyn.jpeg");
         al_draw_bitmap(retrato,462,33,0);

         //En archivo:
         font1 = al_load_font("./fonts/orbitron-black.ttf",12,0);

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,337, 0, "MARY HALLIGAN: Oriunda de Saint Etienne, Era la");

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,357, 0, "heredera de una poderosa familia local del siglo");

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,377, 0,"XV, pero dejo todo atrás cuando estuvo implicada");

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,397, 0,"en un incidente con el bandido Moriarty,");

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,417, 0,"ingresando a la ACVT con el fin de perseguirlo");

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,437, 0, "y atraparlo.");

         //En archivo:
         font1 = al_load_font("./fonts/orbitron-black.ttf",12,0);
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,464, 0, "+Experta tiradora: Daño doble.");
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,528, 0, "-Licencia vencida: -2 saltos temporales");
      break;

      case 3:
         retrato=al_load_bitmap("./images/Pj_Patrick.jpeg");
         al_draw_bitmap(retrato,462,33,0);

         //En archivo:
         font1 = al_load_font("./fonts/orbitron-black.ttf",12,0);

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,337, 0, "Guybrush Threppod: Creció en el Bronx, Cometio");

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,357, 0, "múltiples delitos hakers en el mundo y fue");

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,377, 0,"atrapado. En la cárcel le dieron a elegir,");

         al_draw_text(font1, al_map_rgb(78, 200, 3), 430,397, 0,"o dejar todo atrás o unirse a la ACVT.");

         //En archivo:
         font1 = al_load_font("./fonts/orbitron-black.ttf",12,0);
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,464, 0, "+Modificación genética: Aumenta su vida.");
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,528, 0, "-Pacifista: Menos daño en el combate.");
      break;


      }


   al_destroy_font(font1);
   al_destroy_bitmap(retrato);

   return selec;
}

///////////////////////////////////////////////////////////////////////
void NuevaPartida::destruir(){

   std::cout << "destruccion de NuevaPartida" << std::endl;



   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////


#endif //NuevaPartida_HH
