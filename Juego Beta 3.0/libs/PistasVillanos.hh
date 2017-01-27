#ifndef PISTASVILLANOS_HH
#define PISTASVILLANOS_HH

#include <iostream>
#include <cstdio>
#include "string.h"
#include "stdlib.h"//libreria para usar rand

class PistasVillanos{

private:

   char pistas[5][4];

public:

   const char * obtenerPistaRandom(char * car);
   void grabar();



};
///////////////////////////////////////////////////////////////////////////
//Metodos:

const char * PistasVillanos::obtenerPistaRandom(char * car){

   int ran1=rand()%3;
   int ran2=rand()%3;

   for(int i;i<5;i++){

      if( strcmp ( &pistas[i][0], &car[ran1] )){

         return  &pistas[i][ran2];
      }
   }
}

void PistasVillanos::grabar(){

   FILE *p;

   p=fopen ("../dat/PistasVillanos.dat","ab");

   if(p=NULL){std::cout<<"Error de apertura de archivo!!"<<std::endl;}

   fwrite (this,sizeof *this,1,p);

   fclose(p);

}

#endif //PISTASVILLANOS_HH

/*
   srand(time(0)); //genera semilla basada en el reloj del sistema
   rand()%100+1;

   Nota: Debes incluir la libreria stdlib.h
*/
