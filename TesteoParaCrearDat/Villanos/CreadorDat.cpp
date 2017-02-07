#include <iostream>
#include <cstdio>
#include "string.h"
#include "PistasVillanos.hh"
#include "Villano.hh"

void vill1();
void vill2();
void vill3();
void vill4();
void vill5();

void pistas();

int main(void) {

   vill1();
   vill2();
   vill3();
   vill4();
   vill5();

   //TESTEO DE LA COPIA DEL .DAT
   Villano vVill[5];

   FILE *p;
   p=fopen ("./Villanos.dat","rb");

   if(p==NULL){std::cout<<"Error de apertura de archivo!!"<<std::endl;}

   for (int i=0; i<5; i++) {

      fread(&vVill[i] , sizeof (Villano), 1 , p);
   }
   fclose(p);


/*   for(int i=0;i<50;i++){

      std::cout << vVill[1].obtenerPista() << '\n';



   }*/

   for (int i=0; i<5; i++) {

      std::cout << vVill[i].getDescripcion() << '\n';
   }
//////////////////////////////////////////////////////////7
   //ARCHIVOS PISTAS:

   //pistas();

   //TESTEO DE LA COPIA DEL pistas.DAT:

/*   PistasVillanos pv;

   FILE *pi;
   pi=fopen ("./PistasVillanos.dat","rb");

   if(pi==NULL){std::cout<<"Error de apertura de archivo!!"<<std::endl;}

   for (int i=0; i<5; i++) {

      fread(&pv , sizeof (PistasVillanos), 1 , pi);
   }
   fclose(pi);*/

   //pv.test();






   return 0;
}

//Funciones para cargar los datos.

void pistas(){

   char p[5][4][75];

   strcpy( p[0][0] , "INGLES" );
      strcpy(p[0][1],"Estabamos jugando Críquet cuando me dijo ...");
      strcpy(p[0][2],"... Dado que no podia encontrar un te que le gustara");
      strcpy(p[0][3],"Me dijo Bloody Hell! vamos a ...");

   strcpy( p[1][0] , "CAZADOR" );
      strcpy( p[1][1] , "... Pero antes iba a comprar balas .270 winchester." );
      strcpy( p[1][2] , "... Era una  buena oportunidad para medirse con la fauna local extinta." );
      strcpy( p[1][3] , "Despues de estar 2 dias y 2 noches en el bosque, me dijo ..." );

   strcpy( p[2][0] , "ARISTOCRATA" );
      strcpy( p[2][1] , "Sus sirvientes me dijieron que el ..." );
      strcpy( p[2][2] , "... No soporta el servicio de esta epoca." );
      strcpy( p[2][3] , "Queria comprar una playa privada en ..." );

   strcpy( p[3][0] , "ERUDITO" );
      strcpy( p[3][1] , "Estaba trascribiendo unos textos y me dijo que ..." );
      strcpy( p[3][2] , "... Dado que siempre quiso conocer la arquitectura del lugar." );
      strcpy( p[3][3] , "Dijo que queria continuar sus estudio de antropologia en ..." );

   strcpy( p[4][0] , "MISTICO" );
      strcpy( p[4][1] , "Por la noche iniciamos un ritual de proteccion y ..." );
      strcpy( p[4][2] , "... .Estaba interezado en la criptozologia local" );
      strcpy( p[4][3] , "... .Para encontrar un antiguo libro maldito." );

      PistasVillanos pv;

      pv.setPistas(p);

      pv.grabar();
}

void vill1(){

   Villano v1;

   char seb[30]={"Sebastian Moran"};
   v1.setNombre(seb);

   char des[40]={"./images/Vill_SebastianDes.jpg"};
   v1.setDescripcion(des);

   char fot[40]={"./images/Vill_Sebastian.jpg"};
   v1.setFoto(fot);

   char vDes[3][12]={"INGLES","CAZADOR","MISTICO"};
   v1.setCaracteristica(vDes);

   v1.grabar();
}
///////////////////////////////////////////////////////////////

void vill2(){

   Villano v1;

   char seb[30]={"James Moriarty"};
   v1.setNombre(seb);

   char des[40]={"./images/Vill_MoriartyDes.jpg"};
   v1.setDescripcion(des);

   char fot[40]={"./images/Vill_Moriarty.jpg"};
   v1.setFoto(fot);

   char vDes[3][12]={"INGLES","ARISTOCRATA","ERUDITO"};
   v1.setCaracteristica(vDes);

   v1.grabar();
}
///////////////////////////////////////////////////////////////

void vill3(){

   Villano v1;

   char seb[30]={"Gilgamesh"};
   v1.setNombre(seb);

   char des[40]={"./images/Vill_GilgameshDes.jpg"};
   v1.setDescripcion(des);

   char fot[40]={"./images/Vill_Gilgamesh.jpg"};
   v1.setFoto(fot);

   char vDes[3][12]={"ARISTOCRATA","CAZADOR","MISTICO"};
   v1.setCaracteristica(vDes);

   v1.grabar();
}
///////////////////////////////////////////////////////////////

void vill4(){

   Villano v1;

   char seb[30]={"Elizabet Bathory"};
   v1.setNombre(seb);

   char des[40]={"./images/Vill_BathoryDes.jpg"};
   v1.setDescripcion(des);

   char fot[40]={"./images/Vill_Bathory.jpg"};
   v1.setFoto(fot);

   char vDes[3][12]={"ARISTOCRATA","ERUDITO","MISTICO"};
   v1.setCaracteristica(vDes);

   v1.grabar();
}
///////////////////////////////////////////////////////////////

void vill5(){

   Villano v1;

   char seb[30]={"Dr. Henry Jekyll"};
   v1.setNombre(seb);

   char des[40]={"./images/Vill_JekyllDes.jpg"};
   v1.setDescripcion(des);

   char fot[40]={"./images/Vill_Jekyll.jpg"};
   v1.setFoto(fot);

   char vDes[3][12]={"INGLES","CAZADOR","ERUDITO"};
   v1.setCaracteristica(vDes);

   v1.grabar();
}
///////////////////////////////////////////////////////////////


/*
//CODIGO DE TESTO DE PUNTERO EN MATRICES:

char tuCulo[12]={"tuCulo"};
char tuCola[12]={"tuCola"};
strcpy(tuCola,tuCulo);
std::cout << tuCola << '\n';

if (strcmp( vDes[0], vDes1[0]) == 0) {

   std::cout << "mmmm" << '\n';
}
char test[12];
strcpy(test,vDes[0]);
std::cout << test << '\n';
*/
