#ifndef MENUOPCIONES_H_INCLUDED
#define MENUOPCIONES_H_INCLUDED

#include "Bibliotecas.hh"

class MenuOpciones:public Ventana
{

private:


public:

    MenuOpciones();

    void dibujar(DatosMouse *dm);
    //void destruir();

    void cargarPantalla(int,int,int );

};

///////////////////////////////////////////////////////////////////////
//Metodos:
MenuOpciones::MenuOpciones()
{

    this->setID(13);//Colocar la ID de la ventana.

    this->cargarDatosVentana(3,al_load_bitmap("13FondoOpciones.jpg"));//El primer dato int pide la cantidad de botones totales.

    //Cargar botones uno a uno:
    this->cargarBoton(1,400,90,500,190,al_load_bitmap("BotonSonidoOff.png"));
    this->cargarBoton(2,510,90,610,190,al_load_bitmap("BotonSonidoOn.png"));
    this->cargarBoton(3,400,400,570,460,al_load_bitmap("VolverMenu.jpg"));

}
///////////////////////////////////////////////////////////////////////
void MenuOpciones::dibujar(DatosMouse * dm)
{

    al_draw_bitmap(this->getFondo(),0,0,0);

    this->colocarBotones();//Dibuja los botones del vector botones heredado.
    ALLEGRO_FONT *font = al_load_font("orbitron-black.ttf",36,0);//la fuente en la carpeta
    ALLEGRO_FONT *font2 = al_load_font("orbitron-black.ttf",24,0);


    al_draw_text(font, al_map_rgb(255, 255, 255), 400, 10, ALLEGRO_ALIGN_CENTER, "MENU OPCIONES");
    al_draw_text(font2, al_map_rgb(255, 255, 255), 100, 100, ALLEGRO_ALIGN_LEFT, "SONIDO: ");
    al_draw_text(font2, al_map_rgb(255, 255, 255), 100, 250, ALLEGRO_ALIGN_LEFT, "DIFICULTAD: ");
    al_draw_text(font2, al_map_rgb(255, 255, 255), 100, 300, ALLEGRO_ALIGN_LEFT, "REINICIAR RANKING ");
    al_draw_text(font2, al_map_rgb(255, 255, 255), 100, 300, ALLEGRO_ALIGN_LEFT, "SALIR ");

    al_destroy_font(font);
    al_destroy_font(font2);

    int selc=comprobarClickBoton(dm);

    switch (selc)  //Regresa el numero del boton tocado.
    {
    case 1:
        this->setIDsalto(1);
        std::cout << "Nuevo Juego" << std::endl;
        break;

    case 2:
        this->setIDsalto(1);
        std::cout << "Cargar Partida" << std::endl;
        break;

    case 3:
        this->setIDsalto(1);
        std::cout << "Salir" << std::endl;
        break;

    }

}




#endif // MENUOPCIONES_H_INCLUDED
