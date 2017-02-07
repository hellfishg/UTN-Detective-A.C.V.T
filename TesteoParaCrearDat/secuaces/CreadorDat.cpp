#include <iostream>
#include <cstdio>
#include "string.h"
#include "Secuaz.hh"




int main(void){


   Secuaz sec1;
   Secuaz sec2;
   Secuaz sec3;

/*
   sec1.setVidaTotal(30);
   sec2.setVidaTotal(30);
   sec3.setVidaTotal(30);

   sec1.setDano(10);
   sec2.setDano(5);
   sec3.setDano(15);

   sec1.setImagen("sec1");
   sec2.setImagen("sec2");
   sec3.setImagen("sec3");

   sec1.grabar();
   sec2.grabar();
   sec3.grabar();
*/



/*   FILE *p;
p=fopen ("./Secuaces.dat","rb");
if(p==NULL){std::cout<<"Error de apertura en secuaces.dat!!"<<std::endl;}

fread (&sec3,sizeof (Secuaz) ,1,p);

fclose(p);*/

   sec1.randomSecuaz();
   sec2.randomSecuaz();
   sec3.randomSecuaz();

   std::cout << sec1.getImagen()<<": " << sec1.golpear(0)<< '\n';
   std::cout << sec2.getImagen()<<": " << sec2.getDano()<< '\n';
   std::cout << sec3.getImagen() <<": " << sec3.getDano()<< '\n';


   return 0;
}
