#ifndef LOCACION_HH_INCLUDED
#define LOCACION_HH_INCLUDED

//#include "Bibliotecas.hh"
#include <iostream>
#include <cstdio>
#include "string.h"

class Locacion{

private:

   char nombre[30];
   char descripcion[40]; // se usa path de una imagen
   char foto[40]; // se usa path de una imagen
   char lugares[3][20];

public:

   Locacion(){}

   void grabar();

//////getters:
   char * getNombre(){return nombre;}
   char * getDescripcion(){return descripcion;}
   char * getFoto(){return foto;}
   char * getLugares(){return *lugares;}

   //setters:
   void setNombre (char nom[30]){strcpy(nombre,nom);}
   void setDescripcion (char des[40]){strcpy(descripcion,des);}
   void setFoto(char fot[30]){strcpy(foto,fot);}
   void setLugares (char l1[20], char l2[20],char l3[20]){strcpy(lugares[0],l1); strcpy(lugares[1],l2); strcpy(lugares[2],l3);}


};
///////////////////////////////////////////////////////////////////////////
//Metodos:



void Locacion::grabar(){

   FILE *p;

   p=fopen ("./Locaciones.dat","ab");

   if(p==NULL){std::cout<<"Error de apertura Locaciones.dat!!"<<std::endl;}

   fwrite (this,sizeof(Locacion),1,p);

   fclose(p);
}









#endif // LOCACION_HH_INCLUDED
