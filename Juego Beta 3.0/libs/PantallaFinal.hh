#ifndef PANTALLAFINAL_HH
#define PANTALLAFINAL_HH

#include "Bibliotecas.hh"

class PantallaFinal:public Pantalla {

private:

   Locacion loc;
   int finalSelec=0;
   int btnNext=0;

   void finalAct();
   void guardarVictoria();//guarda en rankigs.dat si el final fue bueno.

public:

   PantallaFinal();

   void dibujar(DatosMouse *dm);
   void destruir();


};

///////////////////////////////////////////////////////////////////////
//Metodos:
PantallaFinal::PantallaFinal(){

   this->setID(116);//Colocar la ID de la ventana.



}
///////////////////////////////////////////////////////////////////////
void PantallaFinal::dibujar(DatosMouse * dm){

   al_draw_bitmap(this->getFondo(),0,0,0);
   this->colocarBotones();//Dibuja los botones del vector botones heredado.


/////////////////////////////////////////////////////////////////////////

   finalAct();




/////////////////////////////////////////////////////////////////////////
   int selc=comprobarClickBoton(dm);

   switch (selc) {//Regresa el numero del boton tocado.
      case 1:
         this->setIDsalto(0);
         std::cout << "Viaje" << std::endl;

      break;

      case 2:
         this->setIDsalto(0);
         std::cout << "Buscar" << std::endl;
      break;

      case 3:
         this->setIDsalto(0);
         std::cout << "Data" << std::endl;
      break;

      case 4:
         this->setIDsalto(14);
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

         btnNext++;
      break;

   }

}
///////////////////////////////////////////////////////////////////////

void  PantallaFinal::guardarVictoria(){


}

////////////////////////////////////////////////////////////////////////

void PantallaFinal::finalAct(){

   Save save;

   this->saveCheck();

   if( (save.getSaltosRestantes()<0 || save.getVida()<=0)){
      //Final sin tiempo y sin vida:


      char text1[]={"Que desastre, el villano se ha escapado, ahora deberás reportarte a la agencia para ver como resuelves este infortunio. cuando vuelves a la agencia, todo luce muy diferente a como lo recordabas, hasta las personas son distintas. Ahora que llegaste deberás reportarte en la sala de mando."};

      char text2[]={"Cuando te presentas ante el director de la agencia, él se encuentra de espaldas a ti. Cuando se da vuelta, lo que ves te deja sin aliento. Resulta que cuando el villano escapo, realizo tantos cambios, que para cuando regresas, él se había convertido en director de la A.C.V.T."};

      char text3[]={"Al darse cuenta de que eres el agente que lo perseguía, te cuenta todos los cambios que hizo en la historia, haciéndote notar tu mal desempeño al intentar atraparlo, luego ordena que te encierren, acusándote de traicionar a la agencia. Ahora pasaras el resto de tus días congelado en un tubo criogénico por haber permitido que el villano escapara y alterara la historia."};


      switch (btnNext) {
         case 0:

            this->cargarModuloA("./images/Final_0.jpg");
            this->cargarModuloB("./images/111Panel_b.png");


            this->cortarString(text1,"",37,417,106,20,78,200,3);

            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------SIGUIENTE");


         break;

         case 1:

            this->cargarModuloA("./images/Final_1.jpg");
            this->cargarModuloB("./images/111Panel_b.png");

            this->cortarString(text2,"",36,417,106,20,78,200,3);

            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------SIGUIENTE");

         break;

         case 2:

            this->cargarModuloA("./images/Final_3.jpg");
            this->cargarModuloB("./images/111Panel_b.png");

            this->cortarString(text3,"",36,417,106,20,78,200,3);

            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------SIGUIENTE");

         break;
      }


      finalSelec=1;
      std::cout << "/* message */" <<  finalSelec<<'\n';
   }

   if(strcmp(save.getOrdenDeArresto(),save.getVillano())!=0 && finalSelec==0){
      //Final sin orden de arresto:

      char text1[]={"La orden de arresto no correspondia con el villano!! ahora deberás reportarte a la agencia para ver como lo resuelves. cuando vuelves a la agencia, todo luce muy diferente a como lo recordabas, hasta las personas son distintas. Ahora que llegaste deberás reportarte en la sala de mando."};

      char text2[]={"Cuando te presentas ante el director de la agencia, él se encuentra sentado en un sillón de espaldas a ti. Cuando se da vuelta, lo que ves te deja sin aliento. Resulta que cuando el villano escapo, realizo tantos cambios, que para cuando regresas, él se había convertido en director de la A.C.V.T."};

      char text3[]={"Al darse cuenta de que eres el agente que lo perseguía, te cuenta todos los cambios que hizo en la historia, haciéndote notar tu mal desempeño al intentar atraparlo, luego ordena que te encierren, acusándote de traicionar a la agencia. Ahora pasaras el resto de tus días congelado en un tubo criogénico por haber permitido que el villano escapara y alterara la historia."};


      switch (btnNext) {
         case 0:

            this->cargarModuloA("./images/Final_0.jpg");
            this->cargarModuloB("./images/111Panel_b.png");


            this->cortarString(text1,"",37,417,106,20,78,200,3);

            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------SIGUIENTE");

         break;

         case 1:

            this->cargarModuloA("./images/Final_1.jpg");
            this->cargarModuloB("./images/111Panel_b.png");

            this->cortarString(text2,"",36,417,106,20,78,200,3);

            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------SIGUIENTE");

         break;

         case 2:

            this->cargarModuloA("./images/Final_3.jpg");
            this->cargarModuloB("./images/111Panel_b.png");

            this->cortarString(text3,"",36,417,106,20,78,200,3);

            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------SIGUIENTE");

         break;
      }

   }

   if(strcmp(save.getOrdenDeArresto(),save.getVillano())==0 && save.getSaltosHechos() >= save.getPistasCorrectas()){
      //Final victoria:

      char text1[]={"Enhorabuena, has atrapado al villano, ahora será trasladado a los cuarteles de la A.C.V.T, donde será interrogado, y luego encerrado en un tubo criogénico por el resto de sus días, ya que si escapara podría provocar más cambios en la historia. En cuanto a ti, puedes tomarte un merecido descanso, al menos por ahora..."};

      char text2[]={"Felicidades, debido a tu buen desempeño como agente serás ascendido de detective a subdirector de operaciones encubiertas, donde tus habilidades nos serán muy útiles para poder desbaratar organizaciones criminales que traten de alterar la historia. Además te daremos herramientas nuevas para renovar el equipamiento que posees, para que tu trabajo pueda ser realizado más eficientemente."};

      char text3[]={"Contamos con tu ayuda para que esta división de la agencia siga operando tan eficientemente como antes, no nos decepciones!!"};

      switch (btnNext){

         case 0:

            this->cargarModuloA("./images/Final_4.jpg");
            this->cargarModuloB("./images/111Panel_b.png");

            this->cortarString(text1,"",36,417,106,20,78,200,3);

            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------SIGUIENTE");


         break;

         case 1:

            this->cargarModuloA("./images/Loc_Base.jpg");
            this->cargarModuloB("./images/111Panel_b.png");

            this->cortarString(text2,"",36,417,106,20,78,200,3);

            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------SIGUIENTE");

         break;

         case 2:

            this->cargarModuloA("./images/Final_2.jpg");
            this->cargarModuloB("./images/111Panel_b.png");


            this->cortarString(text3,"",36,417,106,20,78,200,3);

            al_draw_text(this->getFont(),al_map_rgb(235, 22, 22),417,376,0,"<------SIGUIENTE");

         break;

      }

   }

   if(btnNext>2){

      this->cargarModuloA("./images/Final_6.jpg");
      this->cargarModuloB("./images/Final_5.jpg");
   }
}

////////////////////////////////////////////////////////////////////////


void PantallaFinal::destruir(){

   std::cout << "Destruccion de PantallaFinal" << std::endl;


}
///////////////////////////////////////////////////////////////////////


#endif //PantallaFinal_HH


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
