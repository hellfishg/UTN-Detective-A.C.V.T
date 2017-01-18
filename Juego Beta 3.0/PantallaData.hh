#ifndef PANTALLADATA_HH_INCLUDED
#define PANTALLADATA_HH_INCLUDED

class PantallaData:public Pantalla {
private:

public:

   PantallaData();

   void dibujar(DatosMouse *dm);
   void destruir();

};


///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaData::PantallaData(){

   this->setID(114);//Colocar la ID de la ventana.


}

void PantallaData::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);
   this->colocarBotones();//Dibuja los botones del vector botones heredado.
/////////////////////////////////////////////////////////////////////////

   this->cargarModuloA("./images/Ladron.jpg");

    al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,106,0,"Se desconoce su nombre real.");
    al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,126,0,"CARACTERISTICAS: ");
    al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,146,0,"Pelo verde, amante de los gatos,");
    al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,166,0,"odia a los pitufos");
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
         this->setIDsalto(0);
         std::cout << "Data" << std::endl;
      break;

      case 4:
         this->setIDsalto(12);
         std::cout << "Salir" << std::endl;
      break;

      case 5:
         this->setIDsalto(0);
         std::cout << "btn 5" << std::endl;
      break;

      case 6:
         this->setIDsalto(0);
         std::cout << "btn 6" << std::endl;
      break;

      case 7:
         this->setIDsalto(0);
         std::cout << "btn 7" << std::endl;
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
///////////////////////////////////////////////////////////////////////
void PantallaData::destruir(){

   std::cout << "destruccion de PantallaData" << std::endl;

   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////


#endif // PANTALLADATA_HH_INCLUDED
