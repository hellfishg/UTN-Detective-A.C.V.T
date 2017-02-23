#ifndef Pantalla_HH
#define Pantalla_HH

#include "Bibliotecas.hh"

class Pantalla:public Ventana {

private:
   ALLEGRO_BITMAP *moduloA;
   ALLEGRO_BITMAP *moduloB;

   ALLEGRO_FONT *font;


public:


   void cargarModuloA(char *cad);
   void cargarModuloB(char *cad);
   void cargarModuloV(char *cad);

   ALLEGRO_FONT * getFont(){return font;}

   void cortarString(char * tex1, char * tex2, int lineaM, int x, int y, int inc, int c1,int c2,int c3 );

   void saveCheck();//Funcion de testeo para ver estado de save.dat

   Pantalla();

   void jumpsTimes(int a);//imprime la cantidad de saltos restantes.

   void vidaHeroe();//imprime la vida del heroe.

   char *buscarFechaLoc(char *nom);
   void fechaLocActual();
};

Pantalla::Pantalla(){



   font=al_load_font("./fonts/orbitron-black.ttf",17,0);


   this->cargarDatosVentana(10,al_load_bitmap("./images/111Fondo.png"));//El primer dato int pide la cantidad de botones totales.

   //Cargar botones uno a uno:
   this->cargarBoton(1,367,494,447,534,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(2,456,496,533,535,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(3,545,495,623,535,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(4,633,495,711,535,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(5,365,111,397,141,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(6,365,154,397,184,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(7,365,197,397,227,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(8,365,240,397,270,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(9,365,283,397,313,al_load_bitmap("./images/btn_transparente.png"));

   this->cargarBoton(10,365,368,397,397,al_load_bitmap("./images/btn_transparente.png"));



}
///////////////////////////////////////////////////////////////////////
void Pantalla::cortarString(char * tex1, char * tex2, int lineaM, int x, int y, int inc, int c1,int c2,int c3 ){

   //Funcion que permite imprimir por pantalla un string largo usando saltos de linea, Basados en el espacio que tiene la ventana.

   //Parametros: texto a imprimir, texto suplementario(se acopla al final del primero, se puede pasar con un string vacio.), cantidad de chars horizontales, eje x, eje y, espacio de los saltos de linea Y, color 1,2,3 en RGB).

   int max=strlen(tex1)+strlen(tex2);//cantidad del maxima del vector.

   char text[max]={""};
   strcat(text,tex1);
   strcat(text,tex2);

   char str[max]={""};
   char palabra[15]={""};

   int cPal=0;//contador para uso de palabraBuffer
   int cLin=0;//contador interno para las lineas.

   for(int i=0;i<max;i++){

      cLin++;

      if(text[i]==' ' || i==max-1){

         palabra[cPal]=text[i];
         cPal++;

         if( cLin >= lineaM || i==max-1 ){

            if(i!=max-1){

               //Cuando imprime normalmente:
               //std::cout << str  << '\n';
               al_draw_text(this->getFont(),al_map_rgb(c1, c2, c3),x,y,0,str);

            }else{

               if(strlen(str)+strlen(palabra) <= lineaM){
                  //cuando imprime al final con menos caracteres:
                  strcat(str,palabra);
                  //std::cout << str << '\n';
                  al_draw_text(this->getFont(),al_map_rgb(c1, c2, c3),x,y,0,str);

               }else{
                  //Cuando imprime al final con mas caracteres:
                  //std::cout << str << '\n';
                  al_draw_text(this->getFont(),al_map_rgb(c1, c2, c3),x,y,0,str);
                  //std::cout << palabra << '\n';
                  y+=inc;
                  al_draw_text(this->getFont(),al_map_rgb(c1, c2, c3),x,y,0,palabra);
               }
            }

            memset(str,'\0',max);//pone el vector en 0;

            cLin= strlen(palabra);//Pone en 0 el contador de linea.
            y+=inc;//incrementa la variable Y.
         }

         strcat(str,palabra);//guarda la palabra en la frace acumulada.

         memset(palabra,'\0',15);//pone el vector en 0;
         cPal=0;

      }else{

         palabra[cPal]=text[i];
         cPal++;
      }
   }
}

//ejemplo:
//this->cortarString("Esto es un texto para ver donde corta la cadena de strings. es importante para los string salvados en base de datos, asi poder mostrarlos por pantalla.","...yeah!",37,417,106,20,78,200,3);

//////////////////////////////////////////////////////////////////


void Pantalla::cargarModuloA(char *cad){


   this->moduloA=al_load_bitmap(cad);
   al_draw_bitmap(this->moduloA,28,113,0);//Dibuja moduloA;
}

void Pantalla::cargarModuloB(char *cad){

   this->moduloB=al_load_bitmap(cad);
   al_draw_bitmap(this->moduloB,416,105,0);//Dibuja moduloB;

}


void Pantalla::cargarModuloV(char *cad){

   this->moduloB=al_load_bitmap(cad);
   al_draw_bitmap(this->moduloB,477,44,0);//Dibuja moduloV;

}

void Pantalla::jumpsTimes(int a){

   char jumps[5];

   sprintf(jumps,"%d",a);

   this->cortarString(jumps," Times Jumps",37,608,453,20,235,22,22);

}
////////////////////////////////////////////////////////////////
void Pantalla::vidaHeroe(){

   Save save;



   cargarModuloV("./images/111Panel_v.png");

   char *vida= new char[5];

   sprintf(vida,"VIDA: %d\0",save.getVida());

   al_draw_text(this->getFont(),al_map_rgb(221, 30, 30),485,54,0,vida);

}
////////////////////////////////////////////////////////////////
void Pantalla::fechaLocActual(){

   Save save;

   char anio[20];
   char ubica[50];

   sprintf(anio,"%s\0",buscarFechaLoc(save.getLocActual()));

   strcpy(ubica,save.getLocActual());
   strcat(ubica," ");
   strcat(ubica,anio);

   if(anio!=NULL){

      al_draw_text(this->getFont(),al_map_rgb(221, 30, 30),35,56,0,ubica);

   }else{

      std::cout << "no hay anio!" << '\n';
   }


}
/////////////////////////////////////////////////////////////
char *Pantalla::buscarFechaLoc(char *nom){

   Locacion loc;

   FILE *p=fopen("./Dat/Locaciones.dat","rb");

   if(p==NULL){
      std::cout << "NO SE PUEDO ABRIR LOCACIONES:DAT!!" << '\n';
      return NULL;
   }

   while(fread(&loc,sizeof(Locacion),1,p)){

      if(strcmp(nom,loc.getNombre())==0){

         fclose(p);

         return loc.getFecha();
      }
   }

   fclose(p);
   return NULL;
}

////////////////////////////////////////////////////////////////
void Pantalla::saveCheck(){

   Save save;

   std::cout << "|++++++++++++++++++++++++++++++++++++++++++|" << '\n';
   std::cout << "Nombre:"<<save.getNombre() << '\n';
   std::cout << "Vida:"<<save.getVida() << '\n';
   std::cout << "Num PJ:"<<save.getPj() << '\n';
   std::cout << "Vil:"<<save.getVillano() << '\n';
   std::cout << "Dano:"<<save.getDano() << '\n';
   std::cout << "PistaCorrectas:"<<save.getPistasCorrectas() << '\n';
   std::cout << "--------------------------" << '\n';
   std::cout << "SaltoRestantes:"<<save.getSaltosRestantes() << '\n';
   std::cout << "LocActual:"<<save.getLocActual() << '\n';
   std::cout << "Pista:" << save.getLugarPista()<<'\n';
   std::cout << "SaltosHechos:" <<save.getSaltosHechos() <<'\n';
   std::cout << "LocHecha Ultima:" << save.getLocHechas(save.getSaltosHechos())<< '\n';
   std::cout << "--------------------------" << '\n';
   std::cout << "OrdenArresto:" << save.getOrdenDeArresto()<< '\n';
   std::cout << "SecuacesDerrotados:"<< save.getSecuDerrotados()<< '\n';
   std::cout << "|++++++++++++++++++++++++++++++++++++++++++|" << '\n';
}
////////////////////////////////////////////////////////////////
#endif //Pantalla_HH
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
