#ifndef SAVE_HH
#define SAVE_HH

#include "Bibliotecas.hh"

 class Save{

private:

   char nombre[30];//nombre del usuario.
   int vida;//vida actual.
   int pjEnUso;//pj en uso de la partida.
   char villano[30];//el villano de la partida.
   int dano;//daño que hace el pj.

   int saltosRestantes;//cantidad de saltos restantes.

   char locActual[30];//donde esta actualmente.
   char viajesLoc[4][30];
   char lugarPista[30];//donde guarda el lugar rastro.
   int saltosHechos;//registro de saltos hechos.
   char locHechas[10][30];//registro de lugares correctos visitados.

   char ordenDeArresto[30];//cuando se pida.

   //para ranking tambien:
   int secuacesDerrotados;//para calcular en ranking.

public:

   Save();
   void grabar();
   void incrementarSaltosHechos();
   bool reconLocal(char s[30]); //regresa true si existe la localizacion.

   //getters:
   char * getNombre(){return nombre;}
   int getVida(){return vida;}
   int getDano(){return dano;}
   int getSaltosRestantes(){return saltosRestantes;}
   int getPj(){return pjEnUso;}
   char * getVillano(){return villano;}
   char * getLocActual(){return locActual;}
   char * getViajesLoc(int i){return viajesLoc[i];}

   char * getLugarPista(){return lugarPista;}
   char * getLocHechas(int i){return locHechas[i];}

   int getSaltosHechos(){return saltosHechos;}
   int getSecuDerrotados(){return secuacesDerrotados;}
   char * getOrdenDeArresto(){return ordenDeArresto;}
   //Setters:
   void setNombre(char n[30]){strcpy(nombre,n);}
   void setVida(int v){vida=v;}
   void setDano(int d){dano=d;}
   void setSaltosRestantes(int s){saltosRestantes=s;}
   void setPj(int pj){pjEnUso=pj;}
   void setVillano(char v[30]){strcpy(villano,v);}
   void setLocActual(char loc[30]){strcpy(locActual,loc);}

   void setLugarPista(char l[30]){strcpy(lugarPista,l);}

   void setSaltosHechos(int s){saltosHechos=s;}
   void setSecuacesDerrotados(int s){secuacesDerrotados=s;}

   void setLocHechas(char loc[30]){ strcpy(locHechas[saltosHechos],loc );}

   void setViajesLoc(char loc[30],int i){
      strcpy(viajesLoc[i],loc);
   }

   void setOrdenDeArresto(char n[30]){strcpy(ordenDeArresto,n);}
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
   saltosRestantes--;
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
