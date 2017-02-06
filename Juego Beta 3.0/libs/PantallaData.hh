#ifndef PANTALLADATA_HH_INCLUDED
#define PANTALLADATA_HH_INCLUDED

#include "Bibliotecas.hh"

class PantallaData:public Pantalla {
private:

   int inicio=0;
   int modo;
   /*
   0=bienvenida/1=BDBienve/2=BDSiguiente/
   3=OrdenDeArresBienbenida/4=OrdenDeArrestoCarga
   */

   Villano vil[5];
   int villanoSelc;//guarda el villano seleccionado.
   char carac[6][12]={"INGLES","MISTICO","CAZADOR","ARISTOCRATA","ERUDITO",""};
   int secCarac[3];

   char ordenDeArresto[30];


public:

   PantallaData();

   void dibujar(DatosMouse *dm);
   void destruir();

   //METODOS PARA MECANICAS BOTONES:
   void graficosIniciales();//tambien usada en el constructor.

   //De Base de datos villanos:
   void btn8_a_BDBienve();
   void btn10_BDSiguiente();
   void cargarDBVill();

   //De carga de orden de arresto:
   void btn10_OrdenABienve();
   void btn09_leerDBArresto();
   void secC(int pos);
   void btn09_buscar();
   void btn10_OrdenArrestoEjecutar();

   void repetido(int pos);//funcion auxiliar para regresar la posicion no repetida.

};

///////////////////////////////////////////////////////////////////////
//Constructor:
PantallaData::PantallaData(){

   this->setID(114);//Colocar la ID de la ventana.

}

void PantallaData::dibujar(DatosMouse * dm){

   if(inicio==0){//Lo que se carga solo la primera vez.

      al_draw_bitmap(this->getFondo(),0,0,0);
      this->colocarBotones();//Dibuja los botones del vector botones heredado.

      graficosIniciales();//Carga la venta con lo textos.


      al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),613,453,0,"4 Time Jumps");

       modo=0;
       villanoSelc=1;
       inicio++;
   }


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
         this->setIDsalto(0);
         std::cout << "btn 5" << std::endl;
      break;

      case 6:
         this->setIDsalto(0);
         std::cout << "btn 6" << std::endl;

         if(modo==4){
            secC(0);
         }
      break;

      case 7:
         this->setIDsalto(0);
         std::cout << "btn 7" << std::endl;

         if(modo==4){
            secC(1);
         }
      break;

      case 8:
         this->setIDsalto(0);
         std::cout << "btn 8" << std::endl;

         if(modo==0){
            btn8_a_BDBienve();
         }

         if(modo==4){
            secC(2);
         }

      break;

      case 9:
         this->setIDsalto(0);
         std::cout << "btn 9" << std::endl;

         if(modo==3){
            //carga la pantalla de orden de arresto:
            btn09_leerDBArresto();
         }

         if(modo==0){
            //Orden De arresto bienbenida.
            btn10_OrdenABienve();
         }

         if(modo==1){
            //carga a sebastian.
            cargarDBVill();
         }

         if(modo==4){
            //buscar villanos:
            btn09_buscar();
         }

      break;

      case 10:

         if(modo==0){
            this->setIDsalto(111);
            std::cout << "regresar" << std::endl;
         }

         if(modo==1 || modo==3){
            //regresa al menu principal:
            graficosIniciales();
            modo=0;
         }

         if(modo==2){
            //siguiente villano.
            btn10_BDSiguiente();
         }

         if(modo==4){
            //confirmar orden de arresto.
            btn10_OrdenArrestoEjecutar();
         }

      break;
   }
}
///////////////////////////////////////////////////////////////////////
//METODOS PARA MECANICAS DE BOTONES:

void PantallaData::graficosIniciales(){

   this->cargarModuloA("./images/Vill_Vacio.jpg");
   this->cargarModuloB("./images/111Panel_b.png");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,106,0,"BASE DE DATOS ACVT");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,126,0,"");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,146,0,"Bienvenido");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,166,0,"");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,249,0,"<---BASE DE DATOS VILLANOS");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,290,0,"<---ORDENES DE ARRESTO");

   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,376,0,"<------VOLVER AL MENU ANTERIOR");

   //carga la base de datos para todo PantallaData:

   FILE *p=fopen("./Dat/Villanos.dat","rb");
   if(p==NULL){std::cout << "Error de apertura Villanos.dat!!" << '\n';}
   for(int i=0;i<5;i++){
      fread(&vil[i],sizeof (Villano),1,p);
   }
   fclose(p);

}
///////////////////////////////////////////////////////////////////////
//Botones del menu base de datos villanos:

void PantallaData::btn8_a_BDBienve(){//Carga el primer menu de base de datos de villanos.

   this->cargarModuloB("./images/111Panel_b.png");

   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,106,0,"   BASE DE DATOS DE VILLANOS");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,130,0,"Aca pueden verser los villanos ac-");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,146,0,"tivos sin capturar.");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,290,0,"<---INICIAR");

   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,376,0,"<------VOLVER AL MENU ANTERIOR");

   modo=1;
}

void PantallaData::cargarDBVill(){
   //carga la primera vez al primer villano en pantalla:

   this->cargarModuloB( vil[0].getDescripcion());
   this->cargarModuloA( vil[0].getFoto());
   al_draw_text(this->getFont(),al_map_rgb(61, 150, 5),417,376,0,"<------SIGUIENTE");

   modo=2;

}

void PantallaData::btn10_BDSiguiente(){

   this->cargarModuloA(vil[villanoSelc].getFoto());
   this->cargarModuloB(vil[villanoSelc].getDescripcion());
   al_draw_text(this->getFont(),al_map_rgb(0, 128, 0),417,376,0,"<------SIGUIENTE");

   villanoSelc++;

   if(villanoSelc == 5){villanoSelc=0;}
}


///////////////////////////////////////////////////////////////////////
//Botones del menu orden de arresto:

void PantallaData::btn10_OrdenABienve(){

   this->cargarModuloB("./images/111Panel_b.png");

   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,106,0,"   ORDENES DE ARRESTO");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,130,0,"Aca se cargan datos para pedir");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,146,0,"la orden de arresto");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,290,0,"<---INICIAR");

   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,376,0,"<------VOLVER AL MENU ANTERIOR");

   //Pone en zero todas las elecciones del usuario. Nota: esto se sacara de la clase save.dat cuando este terminada.
   secCarac[0]=5;
   secCarac[1]=5;
   secCarac[2]=5;

   modo=3;

}

void PantallaData::btn09_leerDBArresto(){

   this->cargarModuloA("./images/Vill_Vacio.jpg");
   this->cargarModuloB("./images/111Panel_b.png");

   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,106,0,"   ORDEN DE ARRESTO");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,160,0,"<-Seña 1:");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,206,0,"<-Seña 2:");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,251,0,"<-Seña 3:");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,290,0,"<------------BUSCAR");
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,376,0,"<---||EMITIR ORDEN DE ARRESTO||");

   modo=4;
}

void PantallaData::secC(int pos){

   btn09_leerDBArresto();//para limpiar la pantalla.

   secCarac[pos]++;

   repetido(pos);

   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),524,160,0, carac[secCarac[0]] );
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),524,206,0, carac[secCarac[1]] );
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),524,251,0, carac[secCarac[2]] );

}

void PantallaData::repetido(int pos){

   if(secCarac[pos]>=6){secCarac[pos]=0;}

   if(secCarac[pos]==5){return;}

   int aux=0;

   while(aux!=1){

      if(secCarac[pos]>5){secCarac[pos]=0;}

      for(int i=0;i<3;i++){

         if(secCarac[pos]==secCarac[i] && pos!=i ){

            aux++;
         }
      }

      if(aux>0){


         secCarac[pos]++;
         aux=0;

      }else{

         aux=1;
      }
   }
}

void PantallaData::btn09_buscar(){

   int markadas=0;

   //es for pone el numero de señas marcadas por el usuario. 1,2 o 3.
   for(int i=0;i<3;i++){
      if(secCarac[i]<5){
         markadas++;
      }
   }

   /*std::cout << "debug:" << '\n';
   std::cout << "marcadas "<<markadas << '\n';*/

   char villano1[20]={""};
   char villano2[20]={""};
   char villano3[20]={""};

   int aux=0;

   for(int i=0;i<5;i++){

      aux=0;

      for(int c=0;c<3;c++){

         if(vil[i].reconocerVill( carac[secCarac[c]] )){
            aux++;

            std::cout << vil[i].getNombre() << '\n';
            std::cout << aux << '\n';
         }
      }

      if(aux==markadas && aux != 0){

         strcpy(villano3,villano2);
         strcpy(villano2,villano1);
         strcpy(villano1, vil[i].getNombre() );

      }
   }

   btn09_leerDBArresto();

   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),524,160,0, carac[secCarac[0]] );
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),524,206,0, carac[secCarac[1]] );
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),524,251,0, carac[secCarac[2]] );


   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,327,0, villano1 );
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),608,327,0, villano2 );
   al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),500,350,0, villano3 );

   //Corroborar si solo existe una posibilidad de arresto y habilitar la orden:

   strcpy(ordenDeArresto,"");//pone en zero la orden de arresto.

   if(strcmp(villano2,"")==0){
      if(strcmp(villano3,"")==0){
         strcpy(ordenDeArresto,villano1);

      }
   }
}

void PantallaData::btn10_OrdenArrestoEjecutar(){

   for(int i=0;i<5;i++){

      if(strcmp(ordenDeArresto,vil[i].getNombre())==0){

         this->cargarModuloA(vil[i].getFoto());
         this->cargarModuloB(vil[i].getDescripcion());
         al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,376,0,"   ||ORDEN DE CAPTURA PEDIDA||");

         modo=5;

      }
   }
}

///////////////////////////////////////////////////////////////////////
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

/*
//REFERENCIA DE CORDENADAS MEDIA PARA CARTELES EN BOTONES DEL PANEL B:
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,106,0,"   CARTEL DE PRESENTACION");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,119,0,"<---boton 5");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,160,0,"<---boton 6");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,206,0,"<---boton 7");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,251,0,"<---boton 8");
al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,290,0,"<---boton 9");

al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),417,376,0,"<---boton 10");
*/
