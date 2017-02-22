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
   int pistasCorrectas;//cantidad de saltos para ganar.

   int saltosRestantes;//cantidad de saltos restantes.

   char anio[10];//de la locacion actual.

   int sectorActual;//hotel/bar/cafeteria.

   char locActual[30];//donde esta actualmente.
   char viajesLoc[4][30];
   char lugarPista[30];//donde guarda el lugar rastro.
   int saltosHechos;//registro de saltos hechos.
   char locHechas[18][30];//registro de lugares correctos visitados.

   char ordenDeArresto[30];//cuando se pida.
   int ordenDeArrestoModo;//para blokear el pedido de orden.

   //para ranking tambien:
   int secuacesDerrotados;//para calcular en ranking.

public:

   Save();
   void grabar();
   void incrementarSaltosHechos();
   bool reconLocal(char s[30]); //regresa true si existe la localizacion.
   int golpear(int golpe);

   //getters:
   char * getNombre(){return nombre;}
   int getVida(){return vida;}
   int getDano(){return dano;}
   int getPistasCorrectas(){return pistasCorrectas;}
   int getSaltosRestantes(){return saltosRestantes;}
   int getPj(){return pjEnUso;}
   char * getVillano(){return villano;}
   char * getLocActual(){return locActual;}
   char * getViajesLoc(int i){return viajesLoc[i];}

   char * getLugarPista(){return lugarPista;}
   char * getLocHechas(int i){return locHechas[i];}

   int getSectorActual(){return sectorActual;}

   int getSaltosHechos(){return saltosHechos;}
   int getSecuDerrotados(){return secuacesDerrotados;}
   char * getOrdenDeArresto(){return ordenDeArresto;}
   int getOrdenDeArrestoModo(){return ordenDeArrestoModo;}
   //Setters:
   void setNombre(char n[30]){strcpy(nombre,n);}
   void setVida(int v){vida=v;}
   void setDano(int d){dano=d;}
   void setPistasCorrectas(int d){pistasCorrectas=d;}
   void setSaltosRestantes(int s){saltosRestantes=s;}
   void setPj(int pj){pjEnUso=pj;}
   void setVillano(char v[30]){strcpy(villano,v);}
   void setLocActual(char loc[30]){strcpy(locActual,loc);}

   void setsectorActual(int s){
      sectorActual=s;
   }
   void setLugarPista(char l[30]){strcpy(lugarPista,l);}

   void setSaltosHechos(int s){saltosHechos=s;}
   void setSecuacesDerrotados(int s){secuacesDerrotados=s;}

   void setLocHechas(char loc[30]){ strcpy(locHechas[saltosHechos],loc );}

   void setViajesLoc(char loc[30],int i){
      strcpy(viajesLoc[i],loc);
   }

   void setOrdenDeArresto(char n[30]){strcpy(ordenDeArresto,n);}
   void setOrdenDeArrestoModo(int o){ordenDeArrestoModo=o;}
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

int Save::golpear(int golpe){

   vida=vida-golpe;
   if(vida<0){vida=0;}

   return vida;
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
