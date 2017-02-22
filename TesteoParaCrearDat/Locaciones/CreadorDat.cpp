#include <iostream>
#include <cstdio>
#include "string.h"
#include "Locacion.hh"

void loc0();
void loc1();
void loc2();
void loc3();
void loc4();
void loc5();
void loc6();
void loc7();
void loc8();
void loc9();
void loc10();
void loc11();
void loc12();
void loc13();
void loc14();
void loc15();
void loc16();
void loc17();


int main(void)
{
     loc0 ();
     loc1 ();
     loc2 ();
     loc3 ();
     loc4 ();
     loc5 ();
     loc6 ();
     loc7 ();
     loc8 ();
     loc9 ();
     loc10();
     loc11();
     loc12();
     loc13();
     loc14();
     loc15();
     loc16();
     loc17();

    Locacion vLoc[18];

    FILE *p;
    p=fopen ("./Locaciones.dat","rb");

    if(p==NULL)
    {
        std::cout<<"Error de apertura de archivo!!"<<std::endl;
    }

    for (int i=0; i<18; i++)
    {
        fread(&vLoc[i], sizeof(Locacion), 1, p);
    }

    fclose(p);

    for (int i=0; i<18; i++)
    {
        std::cout << vLoc[i].getDescripcion() << '\n';
    }


    return 0;
}

void loc0 ()
{
    Locacion loc0;

    loc0.setNombre("BASE");
    loc0.setFecha("FUERA DEL TIEMPO");
    loc0.setDescripcion("./images/Loc_BaseDesc.jpg");
    loc0.setFoto("./images/Loc_Base.jpg");
    loc0.setLugares(" ", " ", " ");

    loc0.grabar();
}

void loc1 ()
{
    Locacion loc1;

    loc1.setNombre("IMPERIO RUSO");
    loc1.setFecha("1740 DC");
    loc1.setDescripcion("./images/Loc_RusiaDesc.jpg");
    loc1.setFoto("./images/Loc_Rusia.jpg");
    loc1.setLugares("POSADA", "BAR", "TEMPLO");
    loc1.setPistas("Dijo que le gustaria conocer la catedral de Kazan.", "Comento que tenía ganas de viajar al siglo XVII.", "Dijo que iba a ir a un país que comprendía 22.800.000 km².");

    loc1.grabar();
}

void loc2 ()
{
    Locacion loc2;

    loc2.setNombre("ARGENTINA");
    loc2.setFecha("1810 DC");
    loc2.setDescripcion("./images/Loc_ArgentinaDesc.jpg");
    loc2.setFoto("./images/Loc_Argentina.jpg");
    loc2.setLugares("POSADA", "PULPERIA", "PARROQUIA");
    loc2.setPistas("Dijo que iria al siglo XIX.", "Dijo que quería visitar el Nuevo Mundo.", "Dijo que queria presenciar el fin de uno de los Virreinatos mas importantes");

    loc2.grabar();

}

void loc3 ()
{
    Locacion loc3;

    loc3.setNombre("JERUSALEN");
    loc3.setFecha("1154 DC");
    loc3.setDescripcion("./images/Loc_JerusalenDesc.jpg");
    loc3.setFoto("./images/Loc_Jerusalen.jpg");
    loc3.setLugares("POSADA", "BAR", "MEZQUITA");
    loc3.setPistas("Me dijo que iba a la ciudad tomada por Godofredo de Bouillón.", "Comento que tenia curiosidad por ver una de las mas famosas Guerras Santas.", "Dijo que visitaria el siglo XII");

    loc3.grabar();

}

void loc4 ()
{
    Locacion loc4;

    loc4.setNombre("JAPON");
    loc4.setFecha("1467 DC");
    loc4.setDescripcion("./images/Loc_JaponDesc.jpg");
    loc4.setFoto("./images/Loc_Japon.jpg");
    loc4.setLugares("POSADA", "BAR", "DOJO");
    loc4.setPistas("Dijo que iba a un pais cuya bandera es roja y blanca", "Dijo que iria al siglo XV", "Dijo que queria presenciar la Guerra Ōnin");

    loc4.grabar();
}

void loc5 ()
{
    Locacion loc5;

    loc5.setNombre("ROMA");
    loc5.setFecha("150 AC");
    loc5.setDescripcion("./images/Loc_RomaDesc.jpg");
    loc5.setFoto("./images/Loc_Roma.jpg");
    loc5.setLugares("POSADA", "BAR", "BA�OS PUBLICOS");
    loc5.setPistas("Dijo que viajaria antes de la era Cristiana.", "Comento que iria a una de las ciudades mas famosas de todos los tiempos.","Dijo que iria a la ciudad fundada por dos niños");

    loc5.grabar();
}

void loc6 ()
{
    Locacion loc6;

    loc6.setNombre("FRANCIA");
    loc6.setFecha("1943 DC");
    loc6.setDescripcion("./images/Loc_FranciaDesc.jpg");
    loc6.setFoto("./images/Loc_Francia.jpg");
    loc6.setLugares("HOTEL", "BAR", "IGLESIA");
    loc6.setPistas("Dijo que queria visitar Europa", "Comento que era admirador de Charles de Gaulle.", "Dijo que queria visitar la guerra que provoco mas muertes en toda la historia.");

    loc6.grabar();
}

void loc7 ()
{
    Locacion loc7;

    loc7.setNombre("PARIS");// epoca de revolucion francesa
    loc7.setFecha("1795 DC");
    loc7.setDescripcion("./images/Loc_ParisDesc.jpg");
    loc7.setFoto("./images/Loc_Paris.jpg");
    loc7.setLugares("POSADA", "BAR", "TEMPLO");
    loc7.setPistas("Dijo que iria a una ciudad cuya bandera es azul y roja.", "Dijo que iria al siglo XVIII.", "Comento que iria a la Ciudad de la Luz.");

    loc7.grabar();
}

void loc8 ()
{
    Locacion loc8;

    loc8.setNombre("EGIPTO");
    loc8.setFecha("2500 AC");
    loc8.setDescripcion("./images/Loc_EgiptoDesc.jpg");
    loc8.setFoto("./images/Loc_Egipto.jpg");
    loc8.setLugares("POSADA", "PIRAMIDE", "TEMPLO");
    loc8.setPistas("Comento que era fanatico de Montu", "Dijo que iria a la epoca de la gran exodo.", "Comento que queria visitar las tumbas de los faraones.");

    loc8.grabar();
}

void loc9 ()
{
    Locacion loc9;

    loc9.setNombre("EEUU");
    loc9.setFecha("1862 DC");
    loc9.setDescripcion("./images/Loc_EEUUDesc.jpg");
    loc9.setFoto("./images/Loc_EEUU.jpg");
    loc9.setLugares("POSADA", "BAR", "IGLESIA");
    loc9.setPistas("Dijo que queria visitar el siglo XIX", "Dijo que quería visitar el Nuevo Mundo.", "Comento que le gustaria conocer a Sacajawea");

    loc9.grabar();
}

void loc10 ()
{
    Locacion loc10;

    loc10.setNombre("MEXICO");
    loc10.setFecha("1399 AC");
    loc10.setDescripcion("./images/Loc_MexicoDesc.jpg");
    loc10.setFoto("./images/Loc_Mexico.jpg");
    loc10.setLugares("TEMPLO", "ARMERIA", "PALACIO");
    loc10.setPistas("Comento que iria al siglo XIV", "Dijo que quería visitar el Nuevo Mundo.", "Comento que queria visitar el lugar de la leyenda de Hun-Hunahpú y Vucub-Hunahpú");

    loc10.grabar();
}

void loc11 ()
{
    Locacion loc11;

    loc11.setNombre("ESCANDINAVIA");
    loc11.setFecha("922 DC");
    loc11.setDescripcion("./images/Loc_EscandinaviaDesc.jpg");
    loc11.setFoto("./images/Loc_Escandinavia.jpg");
    loc11.setLugares("BAR", "ARMERIA", "MUELLE");
    loc11.setPistas("Comento que queria conocer a Harald el Despiadado.", "Dijo que iria al siglo X.", "Dijo que iria a ver a los que se adelantaron a Colon.");

    loc11.grabar();
}

void loc12 ()
{
    Locacion loc12;

    loc12.setNombre("MONGOLIA");
    loc12.setFecha("1337 DC");
    loc12.setDescripcion("./images/Loc_MongoliaDesc.jpg");
    loc12.setFoto("./images/Loc_Mongolia.jpg");
    loc12.setLugares("BAR", "ARMERIA", "POSADA");
    loc12.setPistas("Dijo que iria al sigle XIV", "Comento que queria visitar el segundo imperio más extenso de la historia.", "Comento que queria conocer a Gengis Kan.");

    loc12.grabar();
}

void loc13 ()
{
    Locacion loc13;

    loc13.setNombre("ESPARTA");
    loc13.setFecha("480 AC");
    loc13.setDescripcion("./images/Loc_EspartaDesc.jpg");
    loc13.setFoto("./images/Loc_Esparta.jpg");
    loc13.setLugares("TEMPLO", "ARMERIA", "POSADA");
    loc13.setPistas("Dijo que iria a la capital de Laconia.", "Comento que queria presenciar las Guerras Medicas.", "Dijo que iria a conocer a los mejores guerreros de la historia");

    loc13.grabar();
}

void loc14 ()
{
    Locacion loc14;

    loc14.setNombre("CHINA");
    loc14.setFecha("100 DC");
    loc14.setDescripcion("./images/Loc_ChinaDesc.jpg");
    loc14.setFoto("./images/Loc_China.jpg");
    loc14.setLugares("BAR", "MURALLA", "POSADA");
    loc14.setPistas("Comento que iria al siglo I", "Dijo que les gustaria conocer la obra que comenzo el emperador Qin Shi Huang.", "Dijo que iria a ver una de las obras mas grandes hechas por el hombre.");

    loc14.grabar();
}

void loc15 ()
{
    Locacion loc15;

    loc15.setNombre("BABILONIA");
    loc15.setFecha("578 AC");
    loc15.setDescripcion("./images/Loc_BabiloniaDesc.jpg");
    loc15.setFoto("./images/Loc_Babilonia.jpg");
    loc15.setLugares("TEMPLO", "POSADA", "MUELLE");
    loc15.setPistas("Dijo que iria a ver una de las siete maravillas del mundo.", "Dijo que queria ver el lugar donde murio Alejandro Magno.", "Comento que iria a ver el Templo de Ishtar de Agadé.");

    loc15.grabar();
}

void loc16 ()
{
    Locacion loc16;

    loc16.setNombre("EDAD DE PIEDRA");
    loc16.setFecha("3500 AC");
    loc16.setDescripcion("./images/Loc_EdadPiedraDesc.jpg");
    loc16.setFoto("./images/Loc_EdadPiedra.jpg");
    loc16.setLugares("CUEVA", "RIO", "BOSQUE");
    loc16.setPistas("Dijo que le daba curiosidad ver el comienzo de todos nosotros", "Comento que iria al pasado, muy atras en el tiempo", "Dijo algo de visitar el momento de uno de los mas reveladores descubrimientos para la humanidad ");

    loc16.grabar();
}

void loc17 ()
{
    Locacion loc17;

    loc17.setNombre("NUEVA NUEVA YORK");
    loc17.setFecha("3530 DC");
    loc17.setDescripcion("./images/Loc_FuturoDesc.jpg");
    loc17.setFoto("./images/Loc_Futuro.jpg");
    loc17.setLugares("TELETRANSPORTE", "ESCUELA DE ROBOTS", "FABRICA DE NIÑOS");
    loc17.setPistas("Comento que estaba aburrido del pasado", "Dijo que siempre le fascinaron las historias sobre el futuro", "Comento que le gustaria ver el renacimiento de una ciudad");

    loc17.grabar();
}
