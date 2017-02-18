#ifndef PANTALLAVIAJE_HH_INCLUDED
#define PANTALLAVIAJE_HH_INCLUDED

#include "Bibliotecas.hh"

class PantallaViaje:public Pantalla {
private:

   char viajesLoc[4][30];


public:

   PantallaViaje();

   void dibujar(DatosMouse *dm);
   void destruir();

   void generarNuevasLocaciones();//Crea nuevas locaciones randoms sin repetir y elije una para ser la pista correcta y lo guarda en save.
   void saltoTemp(int s);

};


///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaViaje::PantallaViaje(){

   this->setID(113);//Colocar la ID de la ventana.

}
///////////////////////////////////////////////////////////////////////
void PantallaViaje::dibujar(DatosMouse * dm){

   generarNuevasLocaciones();

   al_draw_bitmap(this->getFondo(),0,0,0);
   this->colocarBotones();//Dibuja los botones del vector botones heredado.
/////////////////////////////////////////////////////////////////////////

   this->cargarModuloA("./images/ModuloA_TimeMachine.png");

   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,120,0,"<------FRANCIA, 1489 DC");


   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,160,0,"<------EGITPO, 2800 AC");


   al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,200,0,"<------NUEVO MEJICO, 1800 DC");


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
         this->setIDsalto(111);
         this->setZonaIni(1);
         std::cout << "btn 5 "  << this->getZonaIni() << std::endl;
      break;

      case 6:
         this->setIDsalto(111);
         this->setZonaIni(2);
         std::cout << "btn 6 " << this->getZonaIni() << std::endl;
      break;

      case 7:
         this->setIDsalto(111);
         this->setZonaIni(3);
         std::cout << "btn 7 " << this->getZonaIni() << std::endl;
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
void PantallaViaje::saltoTemp(int s){
   //Carga todos los datos de del salto temporal:

   Save save;

   if(s<=3){
      //Salto correcto:

      if( strcmp(save.getLugarPista(),save.getViajesLoc(s))==0){

         save.setLocActual(save.getViajesLoc(s));

         save.incrementarSaltosHechos();

         save.setLocHechas(save.getLocActual());

         generarNuevasLocaciones();

         save.setViajesLoc( "                     ", 3);

      }else{
         //Salto falso:

         save.setSaltosRestantes( save.getSaltosRestantes() -1 );

         save.setLocActual(save.getViajesLoc(s));
      }
   }

   if(s==4){
      //Si es regreso:

      save.setSaltosRestantes( save.getSaltosRestantes() -1 );

      save.setLocActual(save.getLocHechas(save.getSaltosHechos()));
   }
}
///////////////////////////////////////////////////////////////////////
void PantallaViaje::generarNuevasLocaciones(){

   Save save;

   //De testeo.
/*   save.setLocActual("ROMA");
   save.setSaltosHechos(0);
   save.setLocHechas("BASE");
   save.setSaltosHechos(1);
   save.setLocHechas("EEUU");
   save.grabar();*/
   //borrar despues

   //Genera el salto-anterior hecho:
   save.setViajesLoc(save.getLocHechas(save.getSaltosHechos()),3);

   Locacion loc;

   for(int cont=0;cont<3;cont++){

      int aux=0;

      while(aux!=3){

         loc.random();//autocarga una locacion random

         aux=0;

         if( strcmp(loc.getNombre(),save.getLocActual())!=0 ){//ran==locActual?

            if(! (save.reconLocal(loc.getNombre())) ){//ran==locHechas?

               for(int a=0;a<3;a++){

                  if( strcmp(loc.getNombre(),save.getViajesLoc(a))!=0 ){//ran==yaElegidos?

                     std::cout << "Ya elegidos: "<<loc.getNombre()<<"!="<<save.getViajesLoc(a) << '\n';

                     aux++;
                  }
               }
            }
         }
      }

      save.setViajesLoc(loc.getNombre(),cont);
   }

   for(int i=0;i<4;i++){//salida de consola.
      std::cout << save.getViajesLoc(i) << '\n';
   }

   //Elije una ubicacion correcta y la guarda en save:

    save.setLugarPista( save.getViajesLoc(rand()%3));
    save.grabar();

    std::cout <<"Lugar del villano: " <<save.getLugarPista() << '\n';
}

///////////////////////////////////////////////////////////////////////
void PantallaViaje::destruir(){

   std::cout << "destruccion de PantallaViaje" << std::endl;

   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////


#endif // PANTALLAVIAJE_HH_INCLUDED

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
