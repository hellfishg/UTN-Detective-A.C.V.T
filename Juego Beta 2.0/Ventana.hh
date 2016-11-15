#ifndef VENTANA_HH
#define VENTANA_HH

#include "Bibliotecas.hh"

class Ventana {
private:
   int ID;//Identificacion de la ventana. Ver descripcion abajo de todo.
   int IDsiguiente;//apunta al salto de ventana prox.
   ALLEGRO_BITMAP *fondo;
   int cantBotones;
   Boton *botones;
public:

   int getID(){return ID;}
   int getIDsalto(){return IDsiguiente;}

   ALLEGRO_BITMAP * getFondo(){return fondo;}
   int getCantBotones(){return cantBotones;}
   Boton * getBoton(int indice){return &botones[indice];}

   void setID(int i){ID=i;}
   void setIDsalto(int i){IDsiguiente=i;}

   void cargarDatosVentana(int,ALLEGRO_BITMAP *);
   void cargarBoton(int NrBoton,int xiz,int ysu,int xde,int yin,ALLEGRO_BITMAP *btn);
   int comprobarClickBoton(DatosMouse *dm);
   bool clickEnRectangulo(int xM,int yM,int x1,int y1,int x2, int y2);
   void colocarBotones();

   virtual void dibujar(DatosMouse *){};
   virtual void destruir(){};

};
/////////////////////////////////////////////////
void Ventana::cargarDatosVentana(int cantB, ALLEGRO_BITMAP * f){

   //IDE: definir aca su identificador.
   fondo=f;//Setea el fondo de la ventana.
   cantBotones=cantB;//Pide la cantidad que se va usar de botones.
   botones=new Boton[cantB];//Contruye el vector de la cantidad de botones.
}
///////////////////////////////////////////////////
void Ventana::cargarBoton(int NrBoton,int xiz,int ysu,int xde,int yin,ALLEGRO_BITMAP *btn){

//NOTA: Este metodo se ejecute depues de definir cargarDatosVentana();
//Crea un vector con la posicion y la imagen de cada boton:

   botones[NrBoton-1].setPosition(xiz,ysu,xde,yin);//rectangulo de posicion;
   botones[NrBoton-1].setImagen(btn);//imagen;
}

///////////////////////////////////////////////////
bool Ventana::clickEnRectangulo(int xM,int yM,int x1,int y1,int x2, int y2){

   bool retorno=false;

   if (xM>x1 && xM<x2 && yM>y1 && yM<y2){retorno=true;}//cambiar los nombre que no se entiende.

   return retorno;
}
////////////////////////////////////////////////////
int Ventana::comprobarClickBoton(DatosMouse *dm){

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
/////////////////////////////////////////////////
void Ventana::colocarBotones(){
   Boton *botTemp;

   for(int i=0;i<this->getCantBotones();i++){

      botTemp=this->getBoton(i);
      al_draw_bitmap(botTemp->getImagen(),botTemp->getXIzq(),botTemp->getYSup(),0);

   }
}
///////////////////////////////////////////////////
#endif //VENTANA_HH

/*Las pantallas esta numeradas segun el orden de seleccion. Cada opcion del menu
posee un numero que sera utilizado para conformar el numero final de pantalla.

EJ: El menu principal seria la pantalla 0 y posee 4 opciones. Cada opcion seria
de 1 al 4. generando las pantallas 1,2,3,4.

Si preciono la opcion 1, la pantalla siguiente sera 11 o 12 o13.
Si dentro de la 12 seguimos pasando menues. seran agregados al menu correspondiente.
por ejemplo 121 ,122. 123 etc.

De esta forma se tiene un orden logico de los menues, y si se quiere agregar un menu, no hay que andar moviendo todas las selecciones.
*/
