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

/* vill1();
   vill2();
   vill3();
   vill4();
   vill5();*/

   //TESTEO DE LA COPIA DEL .DAT
   Villano vVill[5];

   FILE *p;
   p=fopen ("./Villanos.dat","rb");

   if(p==NULL){std::cout<<"Error de apertura de archivo!!"<<std::endl;}

   for (int i=0; i<5; i++) {

      fread(&vVill[i] , sizeof (Villano), 1 , p);
   }
   fclose(p);


   for(int i=0;i<50;i++){

      std::cout << vVill[1].obtenerPista() << '\n';



   }

/*   for (int i=0; i<5; i++) {

      std::cout << vVill[i].getNombre() << '\n';
   }*/
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

   char des[1700]={"Amigo personal de Moriarty y temido en prácticamente toda África, cazador de todas las criaturas conocidas y un tirador excepcional. Acceso a todo tipo de armas avanzadas, como rifles de aire presurizado y armas ocultas en artefactos cotidianos, y era él quien se las proporcionaba al Profesor. Es descrito por Watson como un hombre de edad avanzada con una calva y un gran bigote blanco, alto y delgado."};
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

   char des[1700]={"Es un hombre de buen nacimiento y excelente educación, dotado por la naturaleza con una fenomenal habilidad matemática. A la edad de 21 años escribió un tratado sobre el teorema del binomio que ha tenido éxito en Europa. En virtud de ello, ganó la cátedra en matemáticas en una de nuestras universidades más pequeñas y tenía todos los aspectos de una carrera más brillante delante de él.Pero el hombre tenía tendencias hereditarias de la clase más diabólica. Una cepa criminal corría en su sangre, lo cual, en lugar de ser modificado, fue aumentado y lo hizo infinitamente más peligroso por sus extraordinarios poderes mentales. Oscuros rumores se reunieron alrededor de él en la ciudad universitaria, y finalmente se vio obligado a renunciar a su cátedra y venir a Londres."};
   v1.setDescripcion(des);

   char fot[40]={"./images/Vill_Moriarty.png"};
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

   char des[1700]={"Gilgamesh el Inmortal príncipe nacido 3000 años a.C. en la antigua ciudad de Uruk (Mesopotamia), que se cuestiona porqué debe morir. Gilgamesh pierde a su padre en una guerra con un pueblo rival y es cuando decide que no morirá nunca. Una vez que es coronado rey de Uruk, entrena su mente y su cuerpo, se vuelve sabio, justo y convierte a Uruk en la ciudad más próspera de todo el mundo conocido.   Una de tantas noches, cansado del engaño de los que se dicen sabios y de experimentar y buscar una cura para la muerte, Gilgamesh sube a la cima del zigurat y pregunta a los dioses por qué debe morir. En ese momento ve una estrella fugaz pasar sobre su cabeza y estrellarse en la lejanía del desierto. El rey sube a un caballo y se dirige al lugar del impacto. Sorprendentemente, encuentra una nave espacial y se introduce en ella. Allí encuentra a un ser de otro planeta, más precisamente de Marte, llamado Utnapishtim, quien le revela que proviene de un mundo donde los seres no mueren gracias a que su tecnología ha llegado a un nivel superior. Gilgamesh le pide el secreto de la inmortalidad a cambio de curarle las heridas. El extranjero acepta. Una vez curadas las heridas, Utnapishtim le pide que atraviese un portal de luz y le anuncia que ya es inmortal. Antes de marcharse, la criatura le advierte que un día llegará a odiar la inmortalidad y que ese día deberá buscarlo en las estrellas para que él le regale la muerte. Gilgamesh le pregunta \"¿cómo te encontraré?\", a lo que la criatura le responde \"tendrás millones de años para encontrarme\"."};
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

   char des[1700]={"La condesa Isabet Báthory de Ecsed  Hungría, 7 de agosto de 1560-Castillo de Čachtice, actual Trenčín, Eslovaquia, 21 de agosto de 1614, fue una aristócrata húngara, perteneciente a una de las familias más poderosas de Hungría. Ha pasado a la historia por haber sido acusada y condenada de ser responsable de una serie de crímenes motivados por su obsesión por la belleza que le han valido el sobrenombre de la Condesa Sangrienta. Según la leyenda, utilizaba la sangre de sus jóvenes sirvientas y pupilas para mantenerse joven en una época en que una mujer de 44 años se acercaba peligrosamente a la ancianidad. La leyenda cuenta que Erzsébet vio a su paso por un pueblo a una anciana decrépita y se burló de ella, y la anciana, ante su burla, la maldijo diciéndole que la noble también envejecería y se vería como ella algún día."};
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

char des[1700]={"El Dr. Henry Jekyll es un \" hombre grande, bien hecho, de cara lisa, de cincuenta años, que ocasionalmente siente que está luchando entre el bien y el mal dentro de sí mismo, llevando así a la lucha entre sus personalidades duales De Jekyll y Edward Hyde. Ha pasado gran parte de su vida tratando de reprimir los malos deseos que no eran apropiados para un hombre de su estatura. Creo un suero, o poción, en un intento de enmascarar este mal oculto dentro de su personalidad. Sin embargo, al hacerlo, Jekyll se transforma en Mr. Hyde, una horrible y malvada criatura sin compasión ni remordimiento. Jekyll tiene muchos amigos y tiene una personalidad amistosa, pero como Hyde, se vuelve misterioso y violento. Con el paso del tiempo, Hyde crece en el poder, eventualmente, Hyde crece para ser más fuerte que Jekyll."};
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
