#ifndef PANTALLACOMBATE_HH_INCLUDED
#define PANTALLACOMBATE_HH_INCLUDED

class PantallaCombate:public Pantalla {
private:

public:

   PantallaCombate();

   void dibujar(DatosMouse *dm);
   void destruir();

};


///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaCombate::PantallaCombate(){

   this->setID(115);//Colocar la ID de la ventana.


}
///////////////////////////////////////////////////////////////////////
void PantallaCombate::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);
   this->colocarBotones();//Dibuja los botones del vector botones heredado.
/////////////////////////////////////////////////////////////////////////

   this->cargarModuloA("ModuloA_Secuaz1.png");

   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,120,0,"<------ATACAR");
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,160,0,"<------DEFENDER");
   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,200,0,"<------USAR HABILIDAD ESPECIAL");

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
         //this->setIDsalto(111);
         //std::cout << "btn 5 - Destino1" << std::endl;
      break;

      case 6:
         //this->setIDsalto(111);
         //std::cout << "btn 6 - Destino2" << std::endl;
      break;

      case 7:
         //this->setIDsalto(111);
         //std::cout << "btn 7 - Destino3" << std::endl;
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
void PantallaCombate::destruir(){

   std::cout << "destruccion de PantallaCombate" << std::endl;

   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////

#endif // PANTALLACOMBATE_HH_INCLUDED
