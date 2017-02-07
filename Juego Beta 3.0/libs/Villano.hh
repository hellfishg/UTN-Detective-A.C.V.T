#ifndef VILLANO_HH
#define VILLANO_HH

#include "Bibliotecas.hh"

class Villano{

private:

   char nombre[30];
   char descripcion[40];
   char caracteristicas[3][12];//las 3 caracteristicas.
   char foto[40];

public:

   Villano(){}


   char * obtenerPista();//busca y devuelve una pista random de su clase encontrada en PistasVillanos.dat

   bool reconocerVill(char c[12]);//regresa true si la caracteristicas la tiene.

   void grabar();//Graba el villano a Villanos.dat


   //getters:
   char * getNombre(){return nombre;}
   char * getDescripcion(){return descripcion;}
   char * getFoto(){return foto;}
   char * getCaracteristica(int num){
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

char * Villano::obtenerPista(){


   PistasVillanos pv;

   FILE *pi;
   pi=fopen ("./Dat/PistasVillanos.dat","rb");

   if(pi==NULL){std::cout<<"Error de apertura de archivo!!"<<std::endl;}

   for (int i=0; i<5; i++) {

      fread(&pv , sizeof (PistasVillanos), 1 , pi);
   }
   fclose(pi);

   char string[75]={""};

   strcpy(string, pv.obtenerPistaRandom(caracteristicas));

   return string;

}

bool Villano::reconocerVill(char c[12]){

   for(int i=0;i<3;i++){
      if(strcmp(c,caracteristicas[i])==0){

         return true;
      }
   }

   return false;
}

void Villano::grabar(){

   FILE *p;

   p=fopen ("./Villanos.dat","ab");

   if(p==NULL){std::cout<<"Error de apertura de archivo!!"<<std::endl;}

   fwrite (this,sizeof * this,1,p);

   fclose(p);
}

#endif //VILLANO_HH
