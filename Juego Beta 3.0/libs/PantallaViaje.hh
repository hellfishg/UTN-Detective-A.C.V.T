#ifndef PANTALLAVIAJE_HH_INCLUDED
#define PANTALLAVIAJE_HH_INCLUDED

#include "Bibliotecas.hh"

class PantallaViaje:public Pantalla {
private:

   char viajesLoc[4][30];


   void analizarFinDeJuego();

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

   analizarFinDeJuego();

}
///////////////////////////////////////////////////////////////////////
void PantallaViaje::dibujar(DatosMouse * dm){


   al_draw_bitmap(this->getFondo(),0,0,0);
   this->colocarBotones();//Dibuja los botones del vector botones heredado.
   this->vidaHeroe();
   this->fechaLocActual();
/////////////////////////////////////////////////////////////////////////

   this->cargarModuloA("./images/ModuloA_TimeMachine.png");

   Save save;
   this->jumpsTimes(save.getSaltosRestantes());

   std::cout << "PISTA INCIO VIAJES:" << save.getLugarPista()<< '\n';

   if(strcmp(save.getLocActual(), save.getViajesLoc(0))!=0 &&
      strcmp(save.getLocActual(), save.getViajesLoc(1))!=0 &&
      strcmp(save.getLocActual(), save.getViajesLoc(2))!=0){

      char viaje1[50];
      strcpy(viaje1,save.getViajesLoc(0));
      strcat(viaje1," ");
      strcat(viaje1,buscarFechaLoc(save.getViajesLoc(0)));
      this->cortarString("<---- ",viaje1,37,417,120,20,78, 200, 3);

      char viaje2[50];
      strcpy(viaje2,save.getViajesLoc(1));
      strcat(viaje2," ");
      strcat(viaje2,buscarFechaLoc(save.getViajesLoc(1)));
      this->cortarString("<---- ",viaje2,37,417,160,20,78, 200, 3);

      char viaje3[50];
      strcpy(viaje3,save.getViajesLoc(2));
      strcat(viaje3," ");
      strcat(viaje3,buscarFechaLoc(save.getViajesLoc(2)));
      this->cortarString("<---- ",viaje3,37,417,200,20,78, 200, 3);


   }else{

      char viaje4[50];
      strcpy(viaje4,save.getLocHechas(save.getSaltosHechos()));
      strcat(viaje4," ");
      strcat(viaje4,buscarFechaLoc(save.getLocHechas(save.getSaltosHechos())));
      this->cortarString("<---- ",viaje4,37,417,160,20,78, 200, 3);

   }

   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,376,0,"<------VOLVER AL MENU ANTERIOR");
////////////////////////////////////////////////////////
   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
      case 1:
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
         this->setIDsalto(1);
         std::cout << "Salir" << std::endl;
      break;

      case 5:
      if(strcmp(save.getLocActual(), save.getViajesLoc(0))!=0 &&
         strcmp(save.getLocActual(), save.getViajesLoc(1))!=0 &&
         strcmp(save.getLocActual(), save.getViajesLoc(2))!=0){
            std::cout << "btn 5 "  << std::endl;

            saltoTemp(0);
            this->setIDsalto(111);
         }
      break;

      case 6:
      if(strcmp(save.getLocActual(), save.getViajesLoc(0))!=0 &&
         strcmp(save.getLocActual(), save.getViajesLoc(1))!=0 &&
         strcmp(save.getLocActual(), save.getViajesLoc(2))!=0){
            std::cout << "btn 6 " << std::endl;

            saltoTemp(1);
            this->setIDsalto(111);

         }else{//Salto de regreso en pista mala.

            saltoTemp(3);
            this->setIDsalto(111);

         }
      break;

      case 7:
      if(strcmp(save.getLocActual(), save.getViajesLoc(0))!=0 &&
         strcmp(save.getLocActual(), save.getViajesLoc(1))!=0 &&
         strcmp(save.getLocActual(), save.getViajesLoc(2))!=0){
            std::cout << "btn 7 " << std::endl;

            saltoTemp(2);
            this->setIDsalto(111);
         }
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

   if(s<=2){

      if( strcmp(save.getLugarPista(),save.getViajesLoc(s))==0){
         //Salto correcto:

         save.incrementarSaltosHechos();
         save.setLocHechas(save.getLocActual());
         save.setLocActual(save.getViajesLoc(s));
         save.grabar();

         generarNuevasLocaciones();

         std::cout << "Salio positivo!" << '\n';

      }else{
         //Salto falso:

         save.incrementarSaltosHechos();
         save.setLocHechas(save.getLocActual());
         save.setLocActual(save.getViajesLoc(s));
         save.grabar();

         std::cout << "Salio falso!" << '\n';
      }
   }

   if(s==3){
      //Si es regreso:

      save.setSaltosRestantes( save.getSaltosRestantes() -1 );
      save.setLocActual(save.getLocHechas(save.getSaltosHechos()));
      save.setLocHechas(save.getLocHechas(save.getSaltosHechos()-1));
      save.setSaltosHechos(save.getSaltosHechos()-1);
      save.grabar();

      std::cout << "Salio back!" << '\n';
   }

}
///////////////////////////////////////////////////////////////////////
void PantallaViaje::generarNuevasLocaciones(){

   Save save;

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
    std::cout << "Pista elegida: "<<save.getLugarPista() << '\n';
    std::cout << "//////////////////////////////////////" << '\n';
    save.grabar();

}
//////////////////////////////////////////////////
void PantallaViaje::analizarFinDeJuego(){

   Save save;

   if(save.getSaltosRestantes()<0 || save.getVida()<=0){

      this->setIDsalto(116);
   }

   if(save.getPistasCorrectas()==save.getSaltosHechos()){

      this->setIDsalto(116);
   }
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
