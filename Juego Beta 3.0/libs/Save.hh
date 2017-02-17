#ifndef SAVE_HH
#define SAVE_HH

#include <iostream>
#include <cstdio>
#include "string.h"

 class Save{

private:

   char nombre[30];
   int vida;
   int saltosRestantes;
   int pjEnUso;
   char villano[30];
   char locActual[30];//ver si se va manejar con chars.

   //ver de incorporar la eleccion de las caracteristicas elegidas anteriormente de la busqueda de villanos.

   //para ranking tambien:
   char locHechas[10][30];
   int saltosHechos=0;
   int secuacesDerrotados;

public:

   Save();
   void grabar();
   void incrementarSaltosHechos();
   bool reconLocal(char s[30]); //regresa true si existe la localizacion.

   //getters:
   char * getNombre(){return nombre;}
   int getVida(){return vida;}
   int getSaltosRestantes(){return saltosRestantes;}
   int getPj(){return pjEnUso;}
   char * getVillano(){return villano;}
   char * getLocActual(){return locActual;}

   char * getLocHechas(int i){return locHechas[i];}

   int getSaltosHechos(){return saltosHechos;}
   int getSecuDerrotados(){return secuacesDerrotados;}
   //Setters:
   void setNombre(char n[30]){strcpy(nombre,n);}
   void setVida(int v){vida=v;}
   void setSaltosRestantes(int s){saltosRestantes=s;}
   void setPj(int pj){pjEnUso=pj;}
   void setVillano(char v[30]){strcpy(villano,v);}
   void setLocActual(char loc[30]){strcpy(locActual,loc);}


   void setSaltosHechos(int s){saltosHechos=s;}
   void setSecuacesDerrotados(int s){secuacesDerrotados=s;}

   void setLocHechas(char loc[30]){ strcpy(locHechas[saltosHechos],loc );}


};
///////////////////////////////////////////////////////////////////////
Save::Save(){

   FILE *p=fopen("./Dat/Save.dat","rb");
   if(p==NULL){

      std::cout << "SAVE.DAT SE INICIA POR PRIMERA VEZ!" << '\n';
      grabar();

   }else{

      fread(this,sizeof (Save),1,p);
      fclose(p);
   }
}
///////////////////////////////////////////////////////////////////////
void Save::incrementarSaltosHechos(){

   saltosHechos++;
}
///////////////////////////////////////////////////////////////////////
bool Save::reconLocal(char s[30]){

   for(int i=0;i<=saltosHechos;i++){

      if(strcmp(s,locHechas[i])==0){

         return true;
      }
   }

   return false;
}
///////////////////////////////////////////////////////////////////////
void Save::grabar(){

   FILE *p=fopen("./Dat/Save.dat","wb");
   if(p==NULL){std::cout << "ERROR DE APERTURA DE SAVE.DAT!" << '\n';}
   fwrite(this,sizeof (Save),1,p);
   fclose(p);
}
///////////////////////////////////////////////////////////////////////
#endif //SAVE_HH
