#ifndef BOTON_HH
#define BOTON_HH

#include "Bibliotecas.hh"

class Boton {
private:
   int xIzq;
   int ySup;

   int xDer;
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
   void setPosition(int xi,int ys,int xd,int yi);
   void setImagen(ALLEGRO_BITMAP *i){imagen=i;}


};


void Boton::setPosition(int xi,int ys,int xd,int yi){
   xIzq=xi;
   ySup=ys;

   xDer=xd;//lol.
   YInf=yi;

}


#endif //BOTON_HH
