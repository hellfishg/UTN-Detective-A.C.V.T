#ifndef PJ_HH
#define PJ_HH

#include "Bibliotecas.hh"

class Pj{

private:

   char nombre[30];
   char descripcion[1000];
   char descripSkill[80];
   char imagen[40];
   int dano;
   int vida;
   int saltos;

public:

   void grabar();//Grabar en archivo Pjs.dat.

   //getters:
   char * getNombre(){return nombre;}
   char * getDescripcion(){return descripcion;}
   char * getDescripSkill(){return descripSkill;}
   char * getImagen(){return imagen;}
   int getDano(){return dano;}
   int getVida(){return vida;}
   int getSaltos(){return saltos;}

   //setters:
   void setNombre(char n[30]){ strcpy(nombre,n);}
   void setDescripcion(char d[1000]){strcpy(descripcion,d);}
   void setDescripSkill(char d[80]){strcpy(descripSkill,d);}
   void setImagen(char i[40]){strcpy(imagen,i);}
   void setDano(int d){dano=d;}
   void setVida(int v){vida=v;}
   void setSaltos(int s){saltos=s;}

};

//Definir funciones:
void Pj::grabar(){

   FILE * p;
   p=fopen ("./Dat/Pjs.dat","ab");

   if(p==NULL){std::cout << "ERROR ARCHIVO Pjs.dat!!" << '\n';}

   fread(this,sizeof (Pj),1,p);

   fclose(p);
}

#endif //PJ_HH
