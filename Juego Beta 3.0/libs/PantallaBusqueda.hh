#ifndef PANTALLABUSQUEDA_HH_INCLUDED
#define PANTALLABUSQUEDA_HH_INCLUDED

#include "Bibliotecas.hh"

class PantallaBusqueda:public Pantalla {
private:
    Locacion loc;

public:

   PantallaBusqueda();

   void dibujar(DatosMouse *dm);
   void destruir();
   void cargarLocacion();

};


///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaBusqueda::PantallaBusqueda(){

   this->setID(112);//Colocar la ID de la ventana.


}
///////////////////////////////////////////////////////////////////////
void PantallaBusqueda::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);
   this->colocarBotones();//Dibuja los botones del vector botones heredado.
/////////////////////////////////////////////////////////////////////////

   //this->cargarModuloA("jhonTitor.png")

   cargarLocacion();
   cargarModuloA(loc.getFoto());

   char flecha1[30] = {"<--------- "};
   char flecha2[30] = {"<--------- "};
   char flecha3[30] = {"<--------- "};
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,120,0,strcat(flecha1,loc.getLug1()));
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,160,0,strcat(flecha2,loc.getLug2()));
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,200,0,strcat(flecha3,loc.getLug3()));
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------VOLVER AL MENU ANTERIOR");
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),613,453,0,"4 Time Jumps");

   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
      case 1:
         this->setIDsalto(113);
         std::cout << "Viaje" << std::endl;

      break;

      case 2:
         this->setIDsalto(112);
         std::cout << "Buscar" << std::endl;
      break;

      case 3:
         this->setIDsalto(114);
         std::cout << "Data" << std::endl;
      break;

      case 4:
         this->setIDsalto(12);
         std::cout << "Salir" << std::endl;
      break;

      case 5:
         this->setIDsalto(115);
         std::cout << "btn 5 - hacia pantallaCombate" << std::endl;
      break;

      case 6:
         this->setIDsalto(115);
         std::cout << "btn 6 - pantallaCombate" << std::endl;
      break;

      case 7:
         this->setIDsalto(115);
         std::cout << "btn 7 - pantallaCombate" << std::endl;
      break;

      case 8:
         this->setIDsalto(0);
         std::cout << "btn 8" << std::endl;
      break;

      case 9:
         this->setIDsalto(0);
         std::cout << "btn 9" << std::endl;
      break;

      case 10:
         this->setIDsalto(111);
         std::cout << "regresar" << std::endl;
      break;

   }



}
//////////////////////////////////////////////////////////////////////

void PantallaBusqueda::cargarLocacion()
{
   FILE *p;

   Locacion loc2;
   Save save;

   p=fopen ("./Dat/Locaciones.dat","rb");

   if(p==NULL){std::cout<<"Error de apertura Locaciones.dat!!"<<std::endl;}

   while (fread (&loc2,sizeof (Locacion),1,p))
   {
       if (strcmp(save.getLocActual(),loc2.getNombre())==0)
       {
           loc = loc2;
       }
   }
   fclose(p);
}

///////////////////////////////////////////////////////////////////////
void PantallaBusqueda::destruir(){

   std::cout << "destruccion de PantallaBusqueda" << std::endl;

   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////

#endif // PANTALLABUSQUEDA_HH_INCLUDED

/*
///////////////////////////////////////////////////////////////////////////////////////////
//REFERENCIA MEDIA PARA CARTELES EN BOTONES DEL PANEL B:
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,106,0,"   CARTEL DE PRESENTACION");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,119,0,"<---boton 5");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,160,0,"<---boton 6");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,206,0,"<---boton 7");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,251,0,"<---boton 8");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,290,0,"<---boton 9");

al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,376,0,"<---boton 10");
///////////////////////////////////////////////////////////////////////////////////////////
*/
