#ifndef MENUOPCIONES_HH_INCLUDED
#define MENUOPCIONES_HH_INCLUDED

#include "Bibliotecas.hh"

class MenuOpciones:public Ventana
{

private:
    int flag1, flag2;

public:

    MenuOpciones();

    void dibujar(DatosMouse *dm);
    //void destruir();

};

///////////////////////////////////////////////////////////////////////
//Metodos:
MenuOpciones::MenuOpciones()
{

    this->setID(13);//Colocar la ID de la ventana.

    this->cargarDatosVentana(3,al_load_bitmap("13FondoOpciones.jpg"));//El primer dato int pide la cantidad de botones totales.

    //Cargar botones uno a uno:
    ALLEGRO_BITMAP *botonne;
    botonne = al_load_bitmap("BotonSonidoOff.png");
    al_convert_mask_to_alpha(botonne, al_map_rgb(255, 0, 255));

    this->cargarBoton(1,400,90,500,190,botonne);
    //this->cargarBoton(1,400,90,500,190,al_load_bitmap("BotonSonidoOff.png"));
    this->cargarBoton(2,400,200,500,300,al_load_bitmap("NivelDificultadInicio.png"));
    this->cargarBoton(3,400,500,570,560,al_load_bitmap("VolverMenu.jpg"));

    flag1 = flag2 = 0;
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
    al_draw_text(font2, al_map_rgb(255, 255, 255), 100, 280, ALLEGRO_ALIGN_LEFT, "DIFICULTAD: ");
    al_draw_text(font2, al_map_rgb(255, 255, 255), 100, 430, ALLEGRO_ALIGN_LEFT, "REINICIAR RANKING ");
    al_draw_text(font2, al_map_rgb(255, 255, 255), 100, 520, ALLEGRO_ALIGN_LEFT, "SALIR ");

    al_destroy_font(font);
    al_destroy_font(font2);

    int selc=comprobarClickBoton(dm);

    switch (selc)  //Regresa el numero del boton tocado.
    {
    case 1:

        switch (flag1)
        {
        case 0:
            this->getBoton(0)->setImagen(al_load_bitmap("BotonSonidoOn.png"));
            flag1 = 1;
            break;

        case 1:

            this->getBoton(0)->setImagen(al_load_bitmap("BotonSonidoOff.png"));
            flag1 = 0;
            break;
        }
        break;
    case 2:
        std::cout << flag2;
        switch (flag2)
        {
        case 0:
            this->getBoton(1)->setImagen(al_load_bitmap("NivelDificultadFacil.png"));
            flag2 = 1;
            break;

        case 1:

            this->getBoton(1)->setImagen(al_load_bitmap("NivelDificultadNormal.png"));
            flag2 = 2;
            break;
        case 2:

            this->getBoton(1)->setImagen(al_load_bitmap("NivelDificultadDificil.png"));
            flag2 = 3;
            break;
        case 3:

            this->getBoton(1)->setImagen(al_load_bitmap("NivelDificultadExperto.png"));
            flag2 = 0;
            break;

        }
        break;

    case 3:
        this->setIDsalto(1);
        std::cout << "Salir" << std::endl;
        break;

    }

}

// al_convert_mask_to_alpha(ALLEGRO_BITMAP *bitmap, ALLEGRO_COLOR mask_color);


#endif // MENUOPCIONES_HH_INCLUDED
