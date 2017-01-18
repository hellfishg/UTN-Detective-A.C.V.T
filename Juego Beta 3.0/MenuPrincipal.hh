#ifndef MENUPRINCIPAL_HH
#define MENUPRINCIPAL_HH

#include "Bibliotecas.hh"

class MenuPrincipal:public Ventana{

private:


public:

   MenuPrincipal();

   void dibujar(DatosMouse *dm);
   void destruir();

   void cargarPantalla(int,int,int );

};

///////////////////////////////////////////////////////////////////////
//Metodos:
MenuPrincipal::MenuPrincipal(){

   this->setID(1);//Colocar la ID de la ventana.

   this->cargarDatosVentana(5,al_load_bitmap("./images/1FondoMenu.jpg"));//El primer dato int pide la cantidad de botones totales.

   //Cargar botones uno a uno:
   this->cargarBoton(1,570,247,800,280,al_load_bitmap("./images/btn1_NuevaPartida.jpg"));

   this->cargarBoton(2,570,282,800,315,al_load_bitmap("./images/btn1_CargarPartida.jpg"));

   this->cargarBoton(3,570,317,800,350,al_load_bitmap("./images/btn1_Opciones.jpg"));

   this->cargarBoton(4,570,352,800,383,al_load_bitmap("./images/btn1_Ranking.jpg"));

   this->cargarBoton(5,570,389,800,419,al_load_bitmap("./images/btn1_SalirDelJuego.jpg"));

}
///////////////////////////////////////////////////////////////////////
void MenuPrincipal::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);

   this->colocarBotones();//Dibuja los botones del vector botones heredado.


   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
      case 1:
         this->setIDsalto(11);
         std::cout << "Nuevo Juego" << std::endl;
      break;

      case 2:
         this->setIDsalto(12);
         std::cout << "Cargar Partida" << std::endl;
      break;

      case 3:
         this->setIDsalto(13);
         std::cout << "Opciones" << std::endl;
      break;

      case 4:
         this->setIDsalto(14);
         std::cout << "Ranking" << std::endl;
      break;

      case 5:
         this->setIDsalto(-1);
         std::cout << "Salir del Sistema" << std::endl;
      break;
   }

}
///////////////////////////////////////////////////////////////////////
void MenuPrincipal::destruir(){

   std::cout << "destruccion de menuPrincipal" << std::endl;

   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////


#endif //MenuPrincipal_HH
/*
//Para escribir por pantalla:
ALLEGRO_FONT *font = al_load_font("./fonts/orbitron-black.ttf",36,0);

al_draw_text(font, al_map_rgb(255, 255, 255), 400, 10, ALLEGRO_ALIGN_CENTER, "LOS MEJORES!!");
                     */
