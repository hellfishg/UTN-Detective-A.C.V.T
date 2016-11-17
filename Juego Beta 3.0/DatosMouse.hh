#ifndef DATOSMOUSE_HH
#define DATOSMOUSE_HH

class DatosMouse {
private:
   int x;//Posicion x,
   int y;//Posicion y,
   int boton;//Este es el boton presionado: 1=izq. 2=der.

public:

   DatosMouse(){

   }

   void CargarDatos(int,int,int);

   int getX(){return x;}
   int getY(){return y;}
   int getBoton(){return boton;}

};
///////////////////////////////////////////////////////////////////////////
//Metodos:

void DatosMouse::CargarDatos(int x,int y, int b){

   this->x=x;
   this->y=y;
   this->boton=b;
}


#endif //DATOSMOUSE_H
