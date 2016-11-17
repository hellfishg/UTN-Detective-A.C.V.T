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

};

///////////////////////////////////////////////////////////////////////
//Metodos:
MenuRanking::MenuRanking()
{
    this->setID(14);

    this->cargarDatosVentana(1,al_load_bitmap("14FondoRanking.jpg"));

    this->cargarBoton(1,300,500,450,560,al_load_bitmap("VolverMenu.jpg"));

}
///////////////////////////////////////////////////////////////////////
void MenuRanking::dibujar(DatosMouse *dm)
{

    al_draw_bitmap(this->getFondo(),0,0,0);
    this->colocarBotones();

    ALLEGRO_FONT *font = al_load_font("orbitron-black.ttf",36,0);//la fuente en la carpeta
    ALLEGRO_FONT *font2 = al_load_font("orbitron-black.ttf",24,0);

    al_draw_text(font, al_map_rgb(255, 255, 255), 400, 10, ALLEGRO_ALIGN_CENTER, "LOS MEJORES!!");

    al_draw_text(font2, al_map_rgb(255, 255, 255), 400, 100, ALLEGRO_ALIGN_CENTER, "ANGEL - 15000 PUNTOS");
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
