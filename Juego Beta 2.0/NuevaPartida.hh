#ifndef NUEVAPARTIDA_HH
#define NUEVAPARTIDA_HH

#include "Bibliotecas.hh"

class NuevaPartida:public Ventana{

private:
   int PJ;

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

   this->cargarDatosVentana(4,al_load_bitmap("11Fondo.png"));//El primer dato int pide la cantidad de botones totales.

   //Cargar botones uno a uno:
   this->cargarBoton(1,500,560,713,600,al_load_bitmap("btn_transparente.png"));

   this->cargarBoton(2,413,560,476,600,al_load_bitmap("btn11_flecha_izq.png"));

   this->cargarBoton(3,735,561,800,600,al_load_bitmap("btn11_flecha_der.png"));

   this->cargarBoton(4,26,7,184,32,al_load_bitmap("btn_transparente.png"));

   PJ=1;
}
///////////////////////////////////////////////////////////////////////
void NuevaPartida::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);
   this->colocarBotones();//Dibuja los botones del vector botones heredado.

   ALLEGRO_FONT *font1;

   //Boton volver e iniciar.
   font1 = al_load_font("orbitron-black.ttf",15,0);
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
         this->setIDsalto(111);
         std::cout << "Iniciar Partida" << std::endl;

      break;

      case 2:
         PJ=PJ-1;
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

   int selec=s;

   switch (s){

      case 1:
         retrato=al_load_bitmap("jhonTitor.png");
         al_draw_bitmap(retrato,462,33,0);

         //En archivo:
         font1 = al_load_font("orbitron-black.ttf",12,0);
         al_draw_text(font1, al_map_rgb(78, 200, 3), 437,337, 0, "JHON TITOR: Su nombre real se desconoce.");

         //En archivo:
         font1 = al_load_font("orbitron-black.ttf",12,0);
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,450, 0, "+Viajero experimentado: Reduce el costo");
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,464, 0, "de cada viaje en -0,5");
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,492, 0, "-Pensador: Empieza con menos vida.");
      break;

      case 2:
         retrato=al_load_bitmap("jhonaTitor.png");
         al_draw_bitmap(retrato,462,33,0);

         //En archivo:
         font1 = al_load_font("orbitron-black.ttf",12,0);
         al_draw_text(font1, al_map_rgb(78, 200, 3), 437,337, 0, "MARY HALLIGAN: Se la ha visto en numerosas lineas.");

         //En archivo:
         font1 = al_load_font("orbitron-black.ttf",12,0);
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,450, 0, "+Experta tiradora: Daño doble.");
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,492, 0, "-Licencia vencida: -2 saltos temporales");
      break;

      case 3:
         retrato=al_load_bitmap("guybrush.png");
         al_draw_bitmap(retrato,462,33,0);

         //En archivo:
         font1 = al_load_font("orbitron-black.ttf",12,0);
         al_draw_text(font1, al_map_rgb(78, 200, 3), 437,337, 0, "Guybrush Threppod: Famoso pirata.");

         //En archivo:
         font1 = al_load_font("orbitron-black.ttf",12,0);
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,450, 0, "+Aguanta la respiracion 10 min bajo el agua");
         al_draw_text(font1, al_map_rgb(78, 200, 3), 68,492, 0, "-Hermano de lechuck.");
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
