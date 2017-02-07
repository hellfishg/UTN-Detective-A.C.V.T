#ifndef VILLANO_HH
#define VILLANO_HH

#include <iostream>
#include <cstdio>
#include "string.h"
#include "PistasVillanos.hh"

class Villano{

private:

   char nombre[30];
   char descripcion[40];
   char caracteristicas[3][12];//las 3 caracteristicas.
   char foto[40];

public:

   Villano(){}


   const char * obtenerPista();//busca y devuelve una pista random de su clase encontrada en PistasVillanos.dat

   void grabar();//Graba el villano a Villanos.dat


   //getters:
   const char * getNombre(){return nombre;}
   const char * getDescripcion(){return descripcion;}
   const char * getFoto(){return foto;}
   const char * getCaracteristica(int num){
      return  caracteristicas[num];
   }

   //setters:
   void setNombre (char nom[30]){strcpy(nombre,nom);}
   void setDescripcion (char des[40]){strcpy(descripcion,des);}
   void setCaracteristica (char car[3][12]){

      for (int i=0; i<3; i++){

         strcpy(caracteristicas[i],car[i]);
      }
   }
   void setFoto(char fot[30]){strcpy(foto,fot);}



};
///////////////////////////////////////////////////////////////////////////
//Metodos:

const char * Villano::obtenerPista(){


   PistasVillanos pv;

   FILE *pi;
   pi=fopen ("./PistasVillanos.dat","rb");

   if(pi==NULL){std::cout<<"Error de apertura de archivo!!"<<std::endl;}

   for (int i=0; i<5; i++) {

      fread(&pv , sizeof (PistasVillanos), 1 , pi);
   }
   fclose(pi);

   char string[75]={"holas"};

   strcpy(string, pv.obtenerPistaRandom(caracteristicas));

   return string;

}

void Villano::grabar(){

   FILE *p;

   p=fopen ("./Villanos.dat","ab");

   if(p==NULL){std::cout<<"Error de apertura de archivo!!"<<std::endl;}

   fwrite (this,sizeof * this,1,p);

   fclose(p);
}

#endif //VILLANO_HH
