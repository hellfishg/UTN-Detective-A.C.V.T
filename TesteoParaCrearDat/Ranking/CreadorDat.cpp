#include <iostream>
#include <cstdio>
#include "string.h"
#include "Ranking.hh"
#include "Save.hh"

void rank0();
void rank1();
void rank2();
void rank3();
void rank4();

int main(void)
{
   Ranking rankTotal;
   rank0();



   FILE *p;
   p=fopen ("./Ranking.dat","rb");

   if(p==NULL){std::cout<<"Error de apertura de archivo!!"<<std::endl;}

   fread(&rankTotal , sizeof (Ranking), 1 , p);

   fclose(p);

   rankTotal.grabarTotal();

   p=fopen ("./RankingTotal.dat","rb");

   if(p==NULL){std::cout<<"Error de apertura de archivo!!"<<std::endl;}

   fread(&rankTotal , sizeof (Ranking), 1 , p);

   std::cout<< rankTotal.getNombre() <<std::endl;
   std::cout<< rankTotal.getPuntos() <<std::endl;


   return 0;
}

void rank0()
{
    Ranking rank0;
    Save save;

    //save.setNombre("Juana La Loca");
    //save.setSaltosHechos(4);
    //save.setSecuacesDerrotados(10);
    //save.setVida(50);

    //save.grabar();

    rank0.setNombre(save.getNombre());
    rank0.setSaltosHechos(save.getSaltosHechos());
    rank0.setSecuacesDerrotados(save.getSecuDerrotados());

    int puntaje = rank0.getSecuacesDerrotados() + save.getVida() - rank0.getSaltosHechos();

    rank0.setPuntos(puntaje);

    rank0.grabar();
}

void rank1()
{
    Ranking rank1;
    //Save save;
    int puntaje;

    rank1.setNombre("Elver Galarga");
    rank1.setSaltosHechos(2);
    rank1.setSecuacesDerrotados(3);

    puntaje = rank1.getSecuacesDerrotados() + 100 - rank1.getSaltosHechos();

    rank1.setPuntos(puntaje);

    rank1.grabar();
}

void rank2()
{
    Ranking rank2;
    //Save save;
    int puntaje;

    rank2.setNombre("Angel Gentes");
    rank2.setSaltosHechos(90);
    rank2.setSecuacesDerrotados(10);

    puntaje = rank2.getSecuacesDerrotados() + 100 - rank2.getSaltosHechos();

    rank2.setPuntos(puntaje);

    rank2.grabar();
}

void rank3()
{
    Ranking rank3;
    //Save save;
    int puntaje;

    rank3.setNombre("Elmer Zapato");
    rank3.setSaltosHechos(23);
    rank3.setSecuacesDerrotados(31);

    puntaje = rank3.getSecuacesDerrotados() + 100 - rank3.getSaltosHechos();

    rank3.setPuntos(puntaje);

    rank3.grabar();
}
