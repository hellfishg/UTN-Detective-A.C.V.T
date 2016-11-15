#ifndef BOTON_HH
#define BOTON_HH

#include "Bibliotecas.hh"

class Boton {
private:
   int xIzq;
   int xDer;

   int ySup;
   int YInf;

   ALLEGRO_BITMAP *imagen;

public:

//Getters:
   int getXIzq (){return xIzq;}
   int getXDer (){return xDer;}
   int getYSup (){return ySup;}
   int getYInf (){return YInf;}
   ALLEGRO_BITMAP * getImagen(){return imagen;}
//Setters:
   void setPosition(int xi,int xd,int ys,int yi);
   void setImagen(ALLEGRO_BITMAP *i){imagen=i;}


};


void Boton::setPosition(int xi,int xd,int ys,int yi){
   xIzq=xi;
   xDer=xd;//lol.

   ySup=ys;
   YInf=yi;

}


#endif //BOTON_HH
