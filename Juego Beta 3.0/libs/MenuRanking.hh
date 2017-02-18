#ifndef MENURANKING_HH
#define MENURANKING_HH

#include "Bibliotecas.hh"

class MenuRanking:public Ventana
{

private:

public:

    MenuRanking();

    void dibujar(DatosMouse *dm);
    void destruir();
    void createRegistro();
    void createDat();

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
   Ranking *rank0;
   int indice=0;
   createDat();

   FILE *p;
   p=fopen ("./Dat/RankingTotal.dat","rb");

   if(p==NULL){std::cout<<"Error de apertura de archivo!!"<<std::endl;}

   while (fread(&rank0 , sizeof (Ranking), 1 , p))
   {
       indice++;
   }


   Ranking rank1[indice], rank2[5];

   fread(&rank1, sizeof (Ranking), indice, p);

   fclose(p);

   //////////////// Ordenamiento del vector de Ranking ////////////////////////////////////

    int i,j,pos;
    struct Ranking aux;

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
        rank1[i].setNombre(rank1[pos].getNombre());
        rank1[pos].setNombre(aux.getNombre());


        //aux=reg[i];
        //reg[i]=reg[pos];
        //reg[pos]=aux;
    }

   /////////////////////////////////////////////////////////////////////////////////////////


    char puntos [10];

    itoa(rank0.getPuntos(), puntos, 10);

    al_draw_bitmap(this->getFondo(),0,0,0);
    this->colocarBotones();

    ALLEGRO_FONT *font = al_load_font("./fonts/orbitron-black.ttf",36,0);//la fuente en la carpeta
    ALLEGRO_FONT *font2 = al_load_font("./fonts/orbitron-black.ttf",24,0);

    al_draw_text(font, al_map_rgb(255, 255, 255), 400, 10, ALLEGRO_ALIGN_CENTER, "LOS MEJORES!!");

    al_draw_text(font2, al_map_rgb(255, 255, 255), 100, 100, ALLEGRO_ALIGN_CENTER, puntos);
    al_draw_text(font2, al_map_rgb(255, 255, 255), 600, 100, ALLEGRO_ALIGN_CENTER, rank0.getNombre());
    al_draw_text(font2, al_map_rgb(255, 255, 255), 400, 150, ALLEGRO_ALIGN_CENTRE, "PEPE - 14900 PUNTOS");
    al_draw_text(font2, al_map_rgb(255, 255, 255), 400, 200, ALLEGRO_ALIGN_CENTER, "DANIEL - 14500 PUNTOS");

    al_destroy_font(font);
    al_destroy_font(font2);

    int selc=comprobarClickBoton(dm);

    switch (selc){
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
void MenuRanking::createRegistro()
{
    Ranking rank0;
    Save save;

    save.setNombre("GEEEEENTEEEEEES");
    save.setSaltosRestantes(3);
    save.setSecuacesDerrotados(6);
    save.setVida(100);

    rank0.setNombre(save.getNombre());
    rank0.setSaltosRestantes(save.getSaltosRestantes());
    rank0.setSecuacesDerrotados(save.getSecuDerrotados());

    int puntaje = rank0.getSecuacesDerrotados() + save.getVida() - rank0.getSaltosRestantes();

    rank0.setPuntos(puntaje);

    rank0.grabar();
}

void MenuRanking::createDat()
{
   Ranking rankTotal;
   createRegistro();


   FILE *p;
   p=fopen ("./Dat/Ranking.dat","rb");

   if(p==NULL){std::cout<<"Error de apertura de registro Ranking!!"<<std::endl;}

   fread(&rankTotal , sizeof (Ranking), 1 , p);

   fclose(p);

   rankTotal.grabarTotal();

}

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
