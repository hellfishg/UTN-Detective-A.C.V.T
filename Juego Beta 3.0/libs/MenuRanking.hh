#ifndef MENURANKING_HH
#define MENURANKING_HH

#include "Bibliotecas.hh"

class MenuRanking:public Ventana
{

private:
    int bandera = 0;
    Ranking rank2[5];
    char puntos1 [10], puntos2 [10], puntos3 [10], puntos4 [10], puntos5 [10];

public:

    MenuRanking();

    void dibujar(DatosMouse *dm);
    void destruir();
    void createDat();
    int contadorRegistros();


};

///////////////////////////////////////////////////////////////////////
//Metodos:
MenuRanking::MenuRanking()
{
    this->setID(14);

    this->cargarDatosVentana(1,al_load_bitmap("./images/14FondoRanking.jpg"));

    this->cargarBoton(1,300,500,450,560,al_load_bitmap("./images/VolverMenu.jpg"));

}
///////////////////////////////////////////////////////////////////////

void MenuRanking::dibujar(DatosMouse *dm)
{
    if (bandera == 0)
    {
        //createDat();// luego se usara para crear el ranking.dat una vez creada la class final, por ahora usa un .dat ya hecho
        int indice = contadorRegistros();
        Ranking rank1[indice];

        FILE *p;
        p=fopen ("./Dat/Rankings.dat","rb");

        if(p==NULL)
        {
            std::cout<<"Error de apertura de archivosssssssss!!"<<std::endl;
        }

        fread(&rank1, sizeof (Ranking), indice, p);
        fclose(p);


        for (int i=0; i<indice; i++) std::cout << rank1[i].getNombre() << "  " << rank1[i].getPuntos() << std::endl;
        std::cout << std::endl;

/////////////////////////////// Ordenamiento del vector de Ranking ////////////////////////////////////

        int i,j,pos;
        Ranking aux;

        for(i=0; i<indice-1; i++)
        {
            pos=i;
            for(j=i+1; j<indice; j++)
            {
                if(rank1[j].getPuntos()>rank1[pos].getPuntos())
                {
                    pos=j;
                }
            }

            aux.setNombre(rank1[i].getNombre());
            aux.setPuntos(rank1[i].getPuntos());
            rank1[i].setNombre(rank1[pos].getNombre());
            rank1[i].setPuntos(rank1[pos].getPuntos());
            rank1[pos].setNombre(aux.getNombre());
            rank1[pos].setPuntos(aux.getPuntos());
        }


        for (int i=0; i<5; i++)
        {
            rank2[i].setPuntos(-1);
            rank2[i].setNombre(rank1[i].getNombre());
            rank2[i].setPuntos(rank1[i].getPuntos());
            std::cout << rank2[i].getPuntos() << '\n';
        }

/////////////////// Fin de ordenamiento ////////////////////////////////////////////////////////////

        sprintf(puntos1,"%d",rank2[0].getPuntos()); //converts to decimal base.
        sprintf(puntos2,"%d",rank2[1].getPuntos()); //converts to decimal base.
        sprintf(puntos3,"%d",rank2[2].getPuntos()); //converts to decimal base.
        sprintf(puntos4,"%d",rank2[3].getPuntos()); //converts to decimal base.
        sprintf(puntos5,"%d",rank2[4].getPuntos()); //converts to decimal base.
        //itoa(rank1[3].getPuntos(), puntos, 10);
        bandera++;

        for (int i=0; i<indice; i++) std::cout << rank1[i].getNombre() << "  " << rank1[i].getPuntos() << std::endl;

        std::cout << "Cantidad de registros: " << indice << std::endl;
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    al_draw_bitmap(this->getFondo(),0,0,0);
    this->colocarBotones();

    ALLEGRO_FONT *font = al_load_font("./fonts/orbitron-black.ttf",36,0);//la fuente en la carpeta
    ALLEGRO_FONT *font2 = al_load_font("./fonts/orbitron-black.ttf",24,0);




    al_draw_text(font, al_map_rgb(255, 255, 255), 400, 10, ALLEGRO_ALIGN_CENTER, "LOS MEJORES!!");

    al_draw_text(font2, al_map_rgb(255, 255, 255), 100, 100, ALLEGRO_ALIGN_CENTER, puntos1);
    al_draw_text(font2, al_map_rgb(255, 255, 255), 600, 100, ALLEGRO_ALIGN_CENTER, rank2[0].getNombre());

    std:: cout << rank2[0].getPuntos() << std::endl;



   al_draw_text(font2, al_map_rgb(255, 255, 255), 100, 150, ALLEGRO_ALIGN_CENTRE, puntos2);
    al_draw_text(font2, al_map_rgb(255, 255, 255), 600, 150, ALLEGRO_ALIGN_CENTER, rank2[1].getNombre());

    std:: cout << rank2[1].getPuntos() << std::endl;


    al_draw_text(font2, al_map_rgb(255, 255, 255), 100, 200, ALLEGRO_ALIGN_CENTER, puntos3);
    al_draw_text(font2, al_map_rgb(255, 255, 255), 600, 200, ALLEGRO_ALIGN_CENTER, rank2[2].getNombre());

   std:: cout << rank2[2].getPuntos() << std::endl;



   al_draw_text(font2, al_map_rgb(255, 255, 255), 100, 250, ALLEGRO_ALIGN_CENTER, puntos4);
    al_draw_text(font2, al_map_rgb(255, 255, 255), 600, 250, ALLEGRO_ALIGN_CENTER, rank2[3].getNombre());

   al_draw_text(font2, al_map_rgb(255, 255, 255), 100, 300, ALLEGRO_ALIGN_CENTER, puntos5);
    al_draw_text(font2, al_map_rgb(255, 255, 255), 600, 300, ALLEGRO_ALIGN_CENTER, rank2[4].getNombre());


    al_destroy_font(font);
    al_destroy_font(font2);



    int selc=comprobarClickBoton(dm);

    switch (selc)
    {
    case 1:
        this->setIDsalto(1);
        std::cout << "Salir" << std::endl;
        break;
    }

}
///////////////////////////////////////////////////////////////////////
void MenuRanking::destruir()
{

    std::cout << "destruccion de ranking" << std::endl;

}
///////////////////////////////////////////////////////////////////////

void MenuRanking::createDat()
{
    Ranking rank0;

    rank0.setNombre("PEPE GRILLO");
    rank0.setSaltosRestantes(3);
    rank0.setSecuacesDerrotados(6);

    int puntaje = rank0.getSecuacesDerrotados() + 100 - rank0.getSaltosRestantes();

    rank0.setPuntos(puntaje);

    rank0.grabar();

}
////////////////////////////////////////////////////////////////////
int MenuRanking::contadorRegistros()
{
    Ranking rank0;
    int indice=0;

    FILE *p;
    p=fopen ("./Dat/Rankings.dat","rb");

    if(p==NULL)
    {
        std::cout<<"Error de apertura de archivo Ranking!!"<<std::endl;
    }

    while (fread(&rank0, sizeof (Ranking), 1, p))
    {
        indice++;
    }

    return indice;
}
////////////////////////////////////////////////////////////////////////

#endif //MENURANKING_HH

/*Las pantallas esta numeradas segun el orden de seleccion. Cada opcion del menu
posee un numero que sera utilizado para conformar el numero final de pantalla.

EJ: El menu principal seria la pantalla 0 y posee 4 opciones. Cada opcion seria
de 1 al 4. generando las pantallas 1,2,3,4.

Si preciono la opcion 1, la pantalla siguiente sera 1-1 o 1-2 1-3.
Si dentro de la 1-2 seguimos pasando menues. seran agregados al menu correspondiente.
por ejemplo 1-2-1 ,1-2-2. 1-2-3 etc.

De esta forma se tiene un orden logico de los menues, y si se quiere agregar un menu, no hay que andar moviendo todas las selecciones.
*/
