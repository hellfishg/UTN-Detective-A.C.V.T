#ifndef PISTASVILLANOS_HH
#define PISTASVILLANOS_HH

#include "Bibliotecas.hh"

class PistasVillanos{

private:

   char pistas[5][4][75];

public:

   const char  * obtenerPistaRandom(char car[3][12]);
   void grabar();

   void setPistas(char p[5][4][75]);


////////////////////////////////////////////////////
//BORRAR ESTE METODO DESPUES:
   void test(){

     for(int i=0;i<5;i++){

         std::cout<<'\n';

         for(int u=0;u<4;u++){

            std::cout << pistas[i][u] << '\n';
         }
      }
   }
///////////////////////////////////////////////////

};
///////////////////////////////////////////////////////////////////////////
//Metodos:

const char * PistasVillanos::obtenerPistaRandom(char car[3][12]){

   //srand(time(0));

   int ran1=rand()%3;
   int ran2=rand()%3+1;

   for(int i=0;i<5;i++){


      if( strcmp( pistas[i][0], car[ran1] ) == 0 ){

         return  pistas[i][ran2];
      }
   }
}


void PistasVillanos::setPistas(char p[5][4][75]){
//usado unicamente para grabar la base de datos. una vez.
   for(int i=0;i<5;i++){
      for(int u=0;u<4;u++){

         strcpy(pistas[i][u],p[i][u]);
      }
   }
}

void PistasVillanos::grabar(){

   FILE *p;

   p=fopen ("./PistasVillanos.dat","ab");

   if(p==NULL){std::cout<<"Error de apertura de archivo!!"<<std::endl;}

   fwrite (this,sizeof *this,1,p);

   fclose(p);

}

#endif //PISTASVILLANOS_HH

/*
   srand(time(0)); //genera semilla basada en el reloj del sistema
   rand()%100+1;

   Nota: Debes incluir la libreria stdlib.h
*/
