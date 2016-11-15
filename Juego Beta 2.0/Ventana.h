#ifndef VENTANA_H
#define VENTANA_H

#include "Bibliotecas.h"

class Ventana {
private:
   int cantBotones;
   Boton *botones;
   ALLEGRO_BITMAP *fondo;
public:

   void cargarBoton(int NrBoton,int xi,int xd,int ys,int yi,ALLEGRO_BITMAP *btn);

   ALLEGRO_BITMAP * getFondo(){return fondo;}
   int getCantBotones(){return cantBotones;}
   Boton * getBoton(int indice){return &botones[indice];}

   void cargarDatosVentana(int,ALLEGRO_BITMAP *);
   int obtenerBotonClick(DatosMouse *dm);
   bool clickEnRectangulo(int xM,int yM,int x1,int y1,int x2, int y2);
   virtual void dibujar(DatosMouse *){};
   virtual void destruir(){};

};

void Ventana::cargarDatosVentana(int cantB, ALLEGRO_BITMAP * f){

   fondo=f;//Setea el findo de la ventana;
   cantBotones=cantB;//Pide la cantidad que se va usar de botones.
   botones=new Boton[cantB];//Contruye el vector de la cantidad de botones.
}

void Ventana::cargarBoton(int NrBoton,int xi,int xd,int ys,int yi,ALLEGRO_BITMAP *btn){
//Crea un vector con la posicion y la imagen de cada boton:
//NOTA: Este metodo se ejecute depues de definir cargarDatosVentana();

   botones[NrBoton-1].setPosition(xi,xd,ys,yi);//rectangulo de posicion;
   botones[NrBoton-1].setImagen(btn);//imagen;
}

bool Ventana::clickEnRectangulo(int xM,int yM,int x1,int y1,int x2, int y2){

   bool retorno=false;

   if (xM>x1 && xM<x2 && yM>y1 && yM<y2){retorno=true;}//cambiar los nombre que no se entiende.

   return retorno;
}

int Ventana::obtenerBotonClick(DatosMouse *dm){

   int retorno=0;

   for(int i=0;i<cantBotones;i++){

      if(retorno==0 && this->clickEnRectangulo(
         dm->getX(),dm->getY(),
         botones[i].getXIzq(), botones[i].getYSup(),
         botones[i].getXDer(),botones[i].getYInf()))
      {

         retorno=i+1;
      }
   }

   return retorno;
}


#endif //VENTANA_H
