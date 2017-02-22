#ifndef LOCACION_HH_INCLUDED
#define LOCACION_HH_INCLUDED

#include "Bibliotecas.hh"

class Locacion{

private:

   char nombre[30];
   char fecha [20];
   char descripcion[40]; // se usa path de una imagen
   char foto[40]; // se usa path de una imagen
   char lugares[3][20];
   char pistas [3][300];

public:

   void grabar();

   Locacion random();//regresa una locacion random pidiendo el numero de registro.



//////getters:
   char * getNombre(){return nombre;}
   char * getFecha(){return fecha;}
   char * getDescripcion(){return descripcion;}
   char * getFoto(){return foto;}
   char * getLugares(){return *lugares;}
   char * getLug1(){return lugares[0];}
   char * getLug2(){return lugares[1];}
   char * getLug3(){return lugares[2];}
   char * getPistas(int num){return pistas[num];}


   //setters:
   void setNombre (char nom[30]){strcpy(nombre,nom);}
   void setFecha (char f[20]){strcpy(fecha, f);}
   void setDescripcion (char des[40]){strcpy(descripcion,des);}
   void setFoto(char fot[30]){strcpy(foto,fot);}
   void setLugares (char l1[20], char l2[20],char l3[20]){strcpy(lugares[0],l1); strcpy(lugares[1],l2); strcpy(lugares[2],l3);}
   void setPistas (char p1[200], char p2 [200], char p3[200]){strcpy(pistas[0], p1); strcpy(pistas[1], p2); strcpy(pistas[2], p3);}

};
///////////////////////////////////////////////////////////////////////////
//Metodos:

Locacion Locacion::random(){

   int cant=18; //cantidad de locaciones en la base de datos.Cambiar aca si cambian!!

   int ran=rand()%cant+1;

   FILE *p=fopen ("./Dat/Locaciones.dat","rb");
   if(p==NULL){std::cout<<"Error de apertura en Locaciones.dat!!"<<std::endl;}

   for(int i=0;i<ran;i++){

      fread (this,sizeof (Locacion),1,p);
   }

   fclose(p);
}

void Locacion::grabar(){

   FILE *p;

   p=fopen ("./Locaciones.dat","ab");

   if(p==NULL){std::cout<<"Error de apertura Locaciones.dat!!"<<std::endl;}

   fwrite (this,sizeof * this,1,p);

   fclose(p);
}


#endif // LOCACION_HH_INCLUDED
