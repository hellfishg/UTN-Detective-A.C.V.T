#ifndef PANTALLAINICIAL_HH
#define PANTALLAINICIAL_HH

#include "Bibliotecas.hh"

class PantallaInicial:public Pantalla {

private:

   int modo=0;

public:

   PantallaInicial();

   void dibujar(DatosMouse *dm);
   void destruir();

   void incializarSave();
   void cargarLocacion();
   void elegirVillanoRan();

   void generarNuevasLocaciones();

};


///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaInicial::PantallaInicial(){

   this->setID(15);//Colocar la ID de la ventana.

}
///////////////////////////////////////////////////////////////////////
void PantallaInicial::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);
   this->colocarBotones();//Dibuja los botones del vector botones heredado.

/////////////////////////////////////////////////////////////////////////
   this->cargarModuloA("./images/Loc_Base.jpg");
   Save save;


   char text[]={"Bienvenido agente!... colocar texto aca"};

   this->cortarString(text,"",37,417,106,20,78,200,3);

   if(modo==0){

      incializarSave();

      generarNuevasLocaciones();

      this->saveCheck();//funcion de testeo

      modo++;
   }

////////////////////////////////////////////////////////////////////////

   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
      case 1:
         this->setIDsalto(111);
         std::cout << "Viaje" << std::endl;
      break;

      case 2:
         this->setIDsalto(0);
         std::cout << "Buscar" << std::endl;
      break;

      case 3:
         this->setIDsalto(114);
         std::cout << "Data" << std::endl;
      break;

      case 4:
         this->setIDsalto(0);
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

void PantallaInicial::incializarSave(){

   cargarLocacion();
   elegirVillanoRan();

   Save save;

   save.setNombre("Mongoide VII");
   save.setSaltosHechos(0);
   save.setSecuacesDerrotados(0);
   save.setLocActual(save.getLugarPista());
   save.setLocHechas("BASE");
   save.setSecuacesDerrotados(0);
   save.setOrdenDeArresto("DESCONOCIDO");

   switch (save.getPj()) {
      case 1:
         //+Saltos -vida:

         save.setSaltosRestantes(9);
         save.setVida(150);
         save.setDano(10);

      break;
      case 2:
         //+Daño -Saltos:

         save.setSaltosRestantes(7);
         save.setVida(200);
         save.setDano(15);

      break;
      case 3:
         //+Vida -Daño:

         save.setSaltosRestantes(8);
         save.setVida(250);
         save.setDano(8);

      break;
   }


   save.grabar();

}
///////////////////////////////////////////////////////////////////////
void PantallaInicial::cargarLocacion(){

   Save save;
   Locacion loc;
   bool aux=true;

   while(aux){

      loc.random();//autocarga una locacion random

      if( strcmp(loc.getNombre(),save.getLocActual())!=0 ){//ran==locActual?

         aux=false;
      }
   }

   std::cout << "Locacion:" <<loc.getNombre() <<'\n';

   save.setLugarPista(loc.getNombre());
   save.grabar();
}
////////////////////////////////////////////////////////////////////////
void PantallaInicial::elegirVillanoRan(){

   Save save;
   Villano vil;

   int ran=rand()%5+1;

   FILE *p=fopen("./Dat/Villanos.dat","rb");

   if(p==NULL){std::cout << "ERROR DE APERTURA VILLANOS.DAT!!" << '\n';}

   for(int i=0;i<ran;i++){

      fread(&vil,sizeof(Villano),1,p);
   }

   std::cout << "Random: "<<ran<<":" << vil.getNombre() << '\n';

   save.setVillano(vil.getNombre());


   save.grabar();
}
//////////////////////////////////////////////////////////////////
void PantallaInicial::generarNuevasLocaciones(){

   Save save;

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

////////////////////////////////////////////////////////////////////////



void PantallaInicial::destruir(){

   std::cout << "destruccion de PantallaInicial" << std::endl;

   // for(int i;i< this->getCantBotones();i++){
      // al_destroy

      //bitmap(this->getBoton(1)->getImagen());//Da error en consola.ver.
   // }
}
///////////////////////////////////////////////////////////////////////



#endif //PANTALLAACCION_HH


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

//Creo un boton transparente para usar de marco.
//Para decirle el color transparente de una bitmap.

// ALLEGRO_BITMAP *boteee=al_load_bitmap("Test_transparencia.png");
//
// al_convert_mask_to_alpha(boteee,al_map_rgb(255,0,255));
//
// this->cargarBoton(2,288,300,289,570,botee);
