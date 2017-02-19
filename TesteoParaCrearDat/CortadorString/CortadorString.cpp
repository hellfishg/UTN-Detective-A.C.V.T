#include <iostream>
#include <cstdio>
#include "string.h"
#include <cstdlib>


void cortarString();
void testeo();

int main (void){

   //cortarString();
   //testeo();

   srand(time(0));

   for(int i=0;i<10;i++){


      int pepe=rand()%10;
      std::cout << pepe << '\n';
   }

   return 0;
}
/////////////////////////////////////////////////////////////////////////////////////

/*void testeo(){

      char pepe[200]={"Esto es un texto para ver donde corta la cadena de strings. es importante para los string salvados en base de datos, asi poder mostrarlos por pantalla. "};

      int max=strlen(pepe);//cantidad del maxima del vector.

      int lineaM=15;//linea maxima.

      char palabra[15]={""};
      char string[max]={""};

      int contC=0;
      int contL=0;

      for(int i=0;i<max;i++){

         contL++;

         if(pepe[i]==' '){

            palabra[contC]=pepe[i];
            strcat(string,palabra);

            //borrar palabra:
            memset(palabra,'\0',15);
            contC=0;

            if(contL >= lineaM ){

               std::cout << string << '\n';
               memset(string,'\0',max);
               contL=0;
            }

         }else{

            palabra[contC]=pepe[i];
            contC++;
         }

      }

      std::cout << string << '\n';
}*/
/////////////////////////////////////////////////////////////////////////////////////
void cortarString(){

   char pepe[200]={"Esto es un texto para ver donde corta la cadena de strings. es importante para los string salvados en base de datos, asi poder mostrarlos por pantalla."};

   int x=417;//eje x.
   int y=106;//eje y.

   int masY=17;//incremento de saltos de linea.

   int max=strlen(pepe);//cantidad del maxima del vector.

   int lineaM=30;//linea maxima.

   char buffer1;
   char palabra[15]={""};
   char str[max]={""};

   int cPal=0;//contador para uso de palabraBuffer
   int cLin=0;//contador interno para las lineas.

   for(int i=0;i<max;i++){

      cLin++;

      if(pepe[i]==' ' || i==max-1){

         palabra[cPal]=pepe[i];
         cPal++;

         if( cLin >= lineaM || i==max-1 ){

            if(i!=max-1){

               //Cuando imprime normalmente:
               std::cout << str  << '\n';
               //al_draw_text(this->getFont(),al_map_rgb(78, 200, 3),x,y,0,str);

            }else{

               if(strlen(str)+strlen(palabra) <= lineaM){
                  //cuando imprime al final con menos caracteres:
                  strcat(str,palabra);
                  std::cout << str << '\n';

               }else{
                  //Cuando imprime al final con mas caracteres:
                  std::cout << str << '\n';
                  std::cout << palabra << '\n';
               }
            }

            memset(str,'\0',max);//pone el vector en 0;

            cLin= strlen(palabra);//Pone en 0 el contador de linea.
            y+=masY;//incrementa la variable Y.
         }

         strcat(str,palabra);//guarda la palabra en la frace acumulada.

         memset(palabra,'\0',15);//pone el vector en 0;
         cPal=0;

      }else{

         palabra[cPal]=pepe[i];
         cPal++;
      }
   }
}


//////////////////////////////////////////////////////////////////
