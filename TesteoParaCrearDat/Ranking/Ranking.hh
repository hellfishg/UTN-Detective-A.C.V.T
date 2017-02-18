#ifndef RANKING_HH_INCLUDED
#define RANKING_HH_INCLUDED

//#include "Bibliotecas.hh"

class Ranking {

private:
    char nombre [30];
    int puntos;
    int saltosHechos;
    int secuacesDerrotados;

public:
    void grabar();
    void grabarTotal();

/////////////////getters/////////////////////////////////////

    char *getNombre(){return nombre;}
    int getPuntos(){return puntos;}
    int getSaltosHechos(){return saltosHechos;}
    int getSecuacesDerrotados(){return secuacesDerrotados;}


//////////setters/////////////////////////////////////////////
    void setNombre (char n[30]){strcpy(nombre,n);}
    void setPuntos (int p){puntos=p;}
    void setSaltosHechos (int s){saltosHechos=s;}
    void setSecuacesDerrotados (int sd){secuacesDerrotados=sd;}

};

void Ranking::grabar(){

   FILE *p;

   p=fopen ("./Ranking.dat","wb");

   if(p==NULL){std::cout<<"Error de apertura Ranking.dat!!"<<std::endl;}

   fwrite (this,sizeof * this,1,p);

   fclose(p);
}
void Ranking::grabarTotal(){

   FILE *p;

   p=fopen ("./RankingTotal.dat","ab");

   if(p==NULL){std::cout<<"Error de apertura Ranking.dat!!"<<std::endl;}

   fwrite (this,sizeof * this,1,p);

   fclose(p);
}


#endif // RANKING_HH_INCLUDED
