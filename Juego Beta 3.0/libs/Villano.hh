#ifndef VILLANO_HH
#define VILLANO_HH

#include <iostream>
#include <cstdio>
#include "string.h"
#include "PistasVillanos.hh"

class Villano{

private:

   char nombre[30];
   char descripcion[850];
   char caracteristicas[3];//las 3 caracteristicas.
   char foto[30];

public:

   Villano(){}


   const char * obtenerPista();//busca y devuelve una pista random de su clase encontrada en PistasVillanos.dat

   void grabar();//Graba el villano a Villanos.dat


   //getters:
   const char * getNombre(){return nombre;}
   const char * getDescripcion(){return descripcion;}
   const char * getFoto(){return foto;}
   const char * getCaracteristica(int num){
      return &caracteristicas[num];
   }


   //setters:
   void setNombre (char nom[30]){strcpy(nombre,nom);}
   void setDescripcion (char des[850]){strcpy(descripcion,des);}
   void setCaracteristica (int num,char car[15]){

      strcpy(&caracteristicas[num],car);
   }
   void setFoto(char fot[30]){strcpy(foto,fot);}



};
///////////////////////////////////////////////////////////////////////////
//Metodos:

const char * Villano::obtenerPista(){

   PistasVillanos PV;
   return PV.obtenerPistaRandom(caracteristicas);
}

void Villano::grabar(){

   FILE *p;

   p=fopen ("../dat/Villanos.dat","ab");

   if(p=NULL){std::cout<<"Error de apertura de archivo!!"<<std::endl;}

   fwrite (this,sizeof *this,1,p);

   fclose(p);

   //quede en: Pensar donde correr esta clase para armar el archivo.

}

#endif //VILLANO_HH
