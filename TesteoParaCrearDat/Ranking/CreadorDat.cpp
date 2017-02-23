#include <iostream>
#include <cstdio>
#include "string.h"
#include "Ranking2.hh"


void rank0();
void rank1();
void rank2();
void rank3();
void rank4();
void rank5();
void rank6();
void rank7();
void rank8();


int main(void)
{
    Ranking rankTotal[9];
    rank0();
    rank1();
    rank2();
    rank3();
    rank4();
    rank5();
    rank6();
    rank7();
    rank8();

    FILE *p;
    p=fopen ("./Ranking.dat","rb");

    if(p==NULL)
    {
        std::cout<<"Error de apertura de archivo!!"<<std::endl;
    }

    for (int i=0; i<=8; i++)
    {
        fread(&rankTotal[i], sizeof (Ranking), 1, p);

    }


    for (int i=0; i<=8; i++)
    {
        std::cout<< rankTotal[i].getNombre() <<std::endl;
        std::cout<< rankTotal[i].getPuntos() <<std::endl;
    }

    fclose(p);
    return 0;
}

void rank0()
{
    Ranking rank0;

    rank0.setNombre("Gilgamesh");
    rank0.setSaltosHechos(2);
    rank0.setSecuacesDerrotados(4);

    int puntaje = rank0.getSecuacesDerrotados() + 100 - rank0.getSaltosHechos();

    rank0.setPuntos(1);

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

    rank1.setPuntos(2);

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

    rank2.setPuntos(3);

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

    rank3.setPuntos(4);

    rank3.grabar();
}

void rank4()
{
    Ranking rank4;
    //Save save;
    int puntaje;

    rank4.setNombre("Mr Hyde");
    rank4.setSaltosHechos(23);
    rank4.setSecuacesDerrotados(31);

    puntaje = rank4.getSecuacesDerrotados() + 100 - rank4.getSaltosHechos();

    rank4.setPuntos(5);

    rank4.grabar();
}

void rank5()
{
    Ranking rank5;
    //Save save;
    int puntaje;

    rank5.setNombre("Sebastian Moran");
    rank5.setSaltosHechos(23);
    rank5.setSecuacesDerrotados(59);

    puntaje = rank5.getSecuacesDerrotados() + 100 - rank5.getSaltosHechos();

    rank5.setPuntos(6);

    rank5.grabar();
}
void rank6()
{
    Ranking rank6;
    //Save save;
    int puntaje;

    rank6.setNombre("Elizabeth Bathory");
    rank6.setSaltosHechos(2);
    rank6.setSecuacesDerrotados(5);

    puntaje = rank6.getSecuacesDerrotados() + 100 - rank6.getSaltosHechos();

    rank6.setPuntos(7);

    rank6.grabar();
}
void rank7()
{
    Ranking rank7;
    //Save save;
    int puntaje;

    rank7.setNombre("Gilgamesh");
    rank7.setSaltosHechos(2);
    rank7.setSecuacesDerrotados(8);

    puntaje = rank7.getSecuacesDerrotados() + 100 - rank7.getSaltosHechos();

    rank7.setPuntos(8);

    rank7.grabar();
}


void rank8()
{
    Ranking rank8;
    //Save save;
    int puntaje;

    rank8.setNombre("James Moriarty");
    rank8.setSaltosHechos(2);
    rank8.setSecuacesDerrotados(31);

    puntaje = rank8.getSecuacesDerrotados() + 100 - rank8.getSaltosHechos();

    rank8.setPuntos(9);

    rank8.grabar();
}
