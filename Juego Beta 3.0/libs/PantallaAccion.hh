#ifndef PANTALLAACCION_HH
#define PANTALLAACCION_HH

#include "Bibliotecas.hh"

class PantallaAccion:public Pantalla {

private:

   Locacion loc;

   Locacion buscarLocacion(char c[30]);
   void cargarLocacion();
   void analizarFinDeJuego();

public:

   PantallaAccion();

   void dibujar(DatosMouse *dm);
   void destruir();

};


///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaAccion::PantallaAccion(){

   this->setID(111);//Colocar la ID de la ventana.

   analizarFinDeJuego();

}
///////////////////////////////////////////////////////////////////////
void PantallaAccion::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);
   this->colocarBotones();//Dibuja los botones del vector botones heredado.


   this->vidaHeroe();
   this->fechaLocActual();

   Save save;

   this->jumpsTimes(save.getSaltosRestantes());
/////////////////////////////////////////////////////////////////////////

   cargarLocacion();


   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
      case 1:
         this->setIDsalto(113);
         std::cout << "Viaje" << std::endl;

      break;

      case 2:
      std::cout << "Buscar" << std::endl;

      if(strcmp(save.getLocActual(), save.getViajesLoc(0))!=0 &&
         strcmp(save.getLocActual(), save.getViajesLoc(1))!=0 &&
         strcmp(save.getLocActual(), save.getViajesLoc(2))!=0){


            this->setIDsalto(112);

      }else{

         al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"NO SE DETECTAN SECUACES AQUI!");
         al_flip_display();
         al_rest(1.5);

         this->setIDsalto(0);
      }

      break;

      case 3:
         this->setIDsalto(114);
         std::cout << "Data" << std::endl;
      break;

      case 4:
         this->setIDsalto(1);
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
         this->setIDsalto(0);
         std::cout << "regresar" << std::endl;
      break;

   }

}
///////////////////////////////////////////////////////////////////////
void PantallaAccion::cargarLocacion(){

   Save save;

   loc=buscarLocacion(save.getLocActual());

   cargarModuloA(loc.getFoto());
   cargarModuloB(loc.getDescripcion());

}

////////////////////////////////////////////////////////////////////////
Locacion PantallaAccion::buscarLocacion(char c[30]){

   Locacion loc;

   FILE *p=fopen ("./Dat/Locaciones.dat","rb");

   if(p==NULL){std::cout<<"Error de apertura Locaciones.dat!!"<<std::endl;}

   while( fread (&loc,sizeof (Locacion),1,p) ){

      if( strcmp(loc.getNombre(),c)==0){

         std::cout << "LOCACION:"<<loc.getNombre() << '\n';

         fclose(p);
         return loc;
      }
   }
}
////////////////////////////////////////////////////////////////////////

void PantallaAccion::analizarFinDeJuego(){

   Save save;

   if(save.getSaltosRestantes()<0 || save.getVida()<=0){

      this->setIDsalto(116);
   }

   if(save.getPistasCorrectas()==save.getSaltosHechos()){

      this->setIDsalto(116);
   }
}

///////////////////////////////////////////////////////////////////////

void PantallaAccion::destruir(){

   std::cout << "destruccion de PantallaAccion" << std::endl;


}
///////////////////////////////////////////////////////////////////////

#endif //PantallaAccion_HH


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

//this->getBoton(1)->setImagen(al_load_bitmap("btn12_Volver.png"));

///////////////////////////////////////////////////////////////////////
