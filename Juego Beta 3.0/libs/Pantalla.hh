#ifndef Pantalla_HH
#define Pantalla_HH

#include "Bibliotecas.hh"

class Pantalla:public Ventana {

private:
   ALLEGRO_BITMAP *moduloA;
   ALLEGRO_BITMAP *moduloB;

   ALLEGRO_FONT *font;

   int vida;
   int saltosRestantes;


   int zona;


public:


   void cargarModuloA(char *cad);
   void cargarModuloB(char *cad);

   ALLEGRO_FONT * getFont(){return font;}

   //int getZona(){return zona;}
   //void setZona(int z){zona=z;}

   void setZonaIni (int d);
   int getZonaIni ();

   Pantalla();



//////////////////////////////////////////////////////////////////


};

Pantalla::Pantalla(){



   font=al_load_font("./fonts/orbitron-black.ttf",17,0);


   this->cargarDatosVentana(10,al_load_bitmap("./images/111Fondo.png"));//El primer dato int pide la cantidad de botones totales.

   //Cargar botones uno a uno:
   this->cargarBoton(1,367,494,447,534,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(2,456,496,533,535,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(3,545,495,623,535,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(4,633,495,711,535,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(5,365,111,397,141,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(6,365,154,397,184,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(7,365,197,397,227,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(8,365,240,397,270,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(9,365,283,397,313,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(10,365,368,397,397,al_load_bitmap("./images/btn_transparente.png"));



}
///////////////////////////////////////////////////////////////////////

void Pantalla::setZonaIni (int d)
{
    FILE *p = fopen("./zona.dat","wb");
    fwrite(&d, sizeof(int),1, p);
    fclose(p);
}


////////////////////////////////////////////////////////////////////

int Pantalla::getZonaIni ()
{
    int d;

    FILE *p = fopen("./zona.dat","rb");
    if (p == NULL) {this->setZonaIni(d);}

    fread(&d, sizeof(int),1, p);
    fclose(p);

    return d;

}

////////////////////////////////////////////////////////////////


void Pantalla::cargarModuloA(char *cad){


   this->moduloA=al_load_bitmap(cad);
   al_draw_bitmap(this->moduloA,28,113,0);//Dibuja moduloA;
}

void Pantalla::cargarModuloB(char *cad){

   this->moduloB=al_load_bitmap(cad);
   al_draw_bitmap(this->moduloB,416,105,0);//Dibuja moduloB;

}
#endif //Pantalla_HH
/*
///////////////////////////////////////////////////////////////////////////////////////////
//REFERENCIA MEDIA PARA CARTELES EN BOTONES DEL PANEL B:
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,106,0,"   CARTEL DE PRESENTACION");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,119,0,"<---boton 5");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,160,0,"<---boton 6");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,206,0,"<---boton 7");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,251,0,"<---boton 8");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,290,0,"<---boton 9");

al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,376,0,"<---boton 10");
///////////////////////////////////////////////////////////////////////////////////////////
*/
