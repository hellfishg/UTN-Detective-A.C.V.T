#include <iostream>
#include <cstdio>
#include "string.h"
#include "Locacion.hh"

void loc1 ();
void loc2 ();
void loc3 ();
void loc4 ();
void loc5 ();
void loc6 ();
void loc7 ();
void loc8 ();
void loc9 ();

int main(void)
{
     loc1 ();
     loc2 ();
     loc3 ();
     loc4 ();
     loc5 ();
     loc6 ();
     loc7 ();
     loc8 ();
     loc9 ();


    Locacion vLoc[9];

    FILE *p;
    p=fopen ("./Locaciones.dat","rb");

    if(p==NULL)
    {
        std::cout<<"Error de apertura de archivo!!"<<std::endl;
    }

    for (int i=0; i<9; i++)
    {
        fread(&vLoc[i], sizeof(Locacion), 1, p);
    }

    fclose(p);

    for (int i=0; i<9; i++)
    {
        std::cout << vLoc[i].getDescripcion() << '\n';
    }


    return 0;
}

void loc1 ()
{
    Locacion loc1;

    loc1.setNombre("IMPERIO RUSO");
    loc1.setDescripcion("./images/Loc_RusiaDesc.jpg");
    loc1.setFoto("./images/Loc_Rusia_5.jpg");
    loc1.setLugares("POSADA", "BAR", "TEMPLO");

    loc1.grabar();
}

void loc2 ()
{
    Locacion loc2;

    loc2.setNombre("VIRREINATO DEL RIO DE LA PLATA");
    loc2.setDescripcion("./images/Loc_ArgentinaDesc.jpg");
    loc2.setFoto("./images/Loc_Argentina_1.jpg");
    loc2.setLugares("POSADA", "PULPERIA", "PARROQUIA");

    loc2.grabar();

}

void loc3 ()
{
    Locacion loc3;

    loc3.setNombre("JERUSALEN");
    loc3.setDescripcion("./images/Loc_JerusalenDesc.jpg");
    loc3.setFoto("./images/Loc_Jerusalen_2.jpg");
    loc3.setLugares("POSADA", "BAR", "MEZQUITA");

    loc3.grabar();

}

void loc4 ()
{
    Locacion loc4;

    loc4.setNombre("JAPON");
    loc4.setDescripcion("./images/Loc_JaponDesc.jpg");
    loc4.setFoto("./images/Loc_Japon_2.jpg");
    loc4.setLugares("POSADA", "BAR", "DOJO");

    loc4.grabar();
}

void loc5 ()
{
    Locacion loc5;

    loc5.setNombre("ROMA");
    loc5.setDescripcion("./images/Loc_RomaDesc.jpg");
    loc5.setFoto("./images/Loc_Roma_1.jpg");
    loc5.setLugares("POSADA", "BAR", "BAÑOS PUBLICOS");

    loc5.grabar();
}

void loc6 ()
{
    Locacion loc6;

    loc6.setNombre("PARIS");
    loc6.setDescripcion("./images/Loc_ParisDesc.jpg");
    loc6.setFoto("./images/Loc_Paris_3.jpg");
    loc6.setLugares("HOTEL", "BAR", "IGLESIA");

    loc6.grabar();
}

void loc7 ()
{
    Locacion loc7;

    loc7.setNombre("PARIS");
    loc7.setDescripcion("./images/Loc_FranciaDesc.jpg");
    loc7.setFoto("./images/Loc_Francia.jpg");
    loc7.setLugares("POSADA", "BAR", "TEMPLO");

    loc7.grabar();
}

void loc8 ()
{
    Locacion loc8;

    loc8.setNombre("EGIPTO");
    loc8.setDescripcion("./images/Loc_EgiptoDesc.jpg");
    loc8.setFoto("./images/Loc_Egipto.jpg");
    loc8.setLugares("POSADA", "PIRAMIDE", "TEMPLO");

    loc8.grabar();
}

void loc9 ()
{
    Locacion loc9;

    loc9.setNombre("EGIPTO");
    loc9.setDescripcion("./images/Loc_EEUUDesc.jpg");
    loc9.setFoto("./images/Loc_EEUU.jpg");
    loc9.setLugares("POSADA", "PIRAMIDE", "TEMPLO");

    loc9.grabar();
}
