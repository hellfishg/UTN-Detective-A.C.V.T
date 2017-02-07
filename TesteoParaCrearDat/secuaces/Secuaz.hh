#ifndef SECUAZ_HH
#define SECUAZ_HH

//#include "Biblotecas.hh"

#include <iostream>
#include <cstdio>
#include "string.h"
#include "stdlib.h"
#include "Save.hh"
#include "Villano.hh"
#include "PistasVillanos.hh"


class Secuaz{

private:

   char imagen[30];
   char imagenDerrota[30];
   int dano;
   int vidaTotal;
   int vidaActual;

public:

   int golpear(int golpe);//Le das un daño y te regresa su vida actual.

   void randomSecuaz();//Carga las estadisticas de una secuaz random.

   char * obtenerPista();

   void grabar();//Graba en la base de datos un secuaz.

   //getters:
   char * getImagen(){return imagen;}
   char * getIMagenDerrota(){return imagenDerrota;}
   int getDano(){return dano;}
   int getVidaTotal(){return vidaTotal;}
   int getVidaActual(){return vidaActual;}

   //setters:
   void setImagen(char i[30]){strcpy(imagen,i);}
   void setImagenDerrota(char i[30]){strcpy(imagenDerrota,i) ;}
   void setDano(int d){dano=d;}
   void setVidaTotal(int v){vidaTotal=v ;}
   void setVidaActual(int v){vidaActual=v;}

};

int Secuaz::golpear(int golpe){

   vidaActual=vidaActual-golpe;
   if(vidaActual<0){vidaActual=0;}

   return vidaActual;
}

void Secuaz::randomSecuaz(){

   //srand(time(0));

   int cant=3; //cantidad de secuaces en la base de datos.Cambiar aca si cambian!!

   int ran=rand()%cant+1;

   std::cout << ran << '\n';

   FILE *p=fopen ("./Secuaces.dat","rb");
   if(p==NULL){std::cout<<"Error de apertura en Secuaces.dat!!"<<std::endl;}

   for(int i=0;i<ran;i++){

      fread (this,sizeof (Secuaz),1,p);

   }

   vidaActual=vidaTotal;//llena la vida.

   fclose(p);
}

char * Secuaz::obtenerPista(){
   //obtener la pista del villano de la partida.

   Save save;
   Villano vil;

   FILE *p=fopen("./Villanos.dat","rb");
   if(p==NULL){std::cout << "ERROR AL ABRIR VILLANOS.DAT!" << '\n';}

   while( fread(&vil,sizeof (Villano),1,p)){

      if( strcmp( vil.getNombre(), save.getVillano() )==0 ){

         fclose(p);

         return vil.obtenerPista();
      }
   }
}

void Secuaz::grabar(){

   FILE *p=fopen ("./Secuaces.dat","ab");

   if(p==NULL){std::cout<<"Error de apertura en secuaces.dat!!"<<std::endl;}

   fwrite (this,sizeof (Secuaz),1,p);

   fclose(p);
}


#endif //SECUAZ_HH
