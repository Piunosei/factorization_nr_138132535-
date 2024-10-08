/*
Lepore factorization nr. 138132535  simple  is free software
Lepore factorization nr. 138132535 simple is Alberico Lepore creation
this file is free software
The Lepore factorization nr. 138132535 simple is free software; you can redistribute it and/or modify
it under the terms of either:
    the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.
You should have received copies of the
GNU Lesser General Public License here https://www.gnu.org/licenses/.
*/







/* gmp_version -- 6.1.2
Copyright 1996, 1999-2001 Free Software Foundation, Inc.
This file is part of the GNU MP Library.
The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of either:
  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.
or
  * the GNU General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any
    later version.
or both in parallel, as here.
The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.
You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the GNU MP Library.  If not,
see https://www.gnu.org/licenses/.  */


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gmp.h>


int prendi_numero(char in[]);


int main(){


  mpz_t N,p,q,mom1,mom2,mom3,M,X,a,zero,uno,due,exp,b,M2,y,z,r,A,B,resto,copia_di_exp,TEST,max_a;

mpz_init(N);

char numero_N[10000];/*set this value*/
prendi_numero(numero_N);
mpz_init_set_str(N, numero_N, 10);

gmp_printf ("\nN=\n%Zd\n",N);


mpz_init(q);
mpz_init(mom1);
mpz_init(mom2);
mpz_init(mom3);
mpz_init(M);
mpz_init(M2);
mpz_init(X);
mpz_init(r);
mpz_init(z);
mpz_init(A);
mpz_init(B);
mpz_init(resto);
mpz_init(copia_di_exp);
mpz_init_set_str (p, "1", 10);
mpz_init_set_str (a, "2", 10);
mpz_init_set_str (zero, "0", 10);
mpz_init_set_str (uno, "1", 10);
mpz_init_set_str (due, "2", 10);
mpz_init_set_str (exp, "1", 10);
mpz_init_set_str (b, "1", 10);
mpz_init_set_str (y, "1", 10);
mpz_init_set_str (max_a, "20", 10);/*////////////////////////////////SET THIS VALUE////////////////////*/

/*
mpz_init_set_str (TEST, "390644893234047643", 10);
 mpz_set(N,TEST);
*/
 
 while(1){
mpz_mul(M,b,N);
mpz_mul(M2,M,M);

 mpz_set(exp,uno); 
while(mpz_cmp(M2,exp)>0){
  mpz_mul(exp,exp,due);
   
}

mpz_div(exp,exp,due);
mpz_set(copia_di_exp,exp);
 mpz_mul(mom2,b,b);

 mpz_set(a,due);
 while((mpz_cmp(p,uno)==0  ||  mpz_cmp(p,M)==0 ||  mpz_cmp(p,b)==0  ||  mpz_cmp(p,mom2)==0) &&  mpz_cmp(a,max_a)<=0){
 
mpz_mul(z,M2,a);
mpz_set(r,M2);
mpz_set(y,uno);
mpz_set(exp,copia_di_exp);
 
 while(mpz_cmp(exp,uno)>=0){
   mpz_mul(mom1,y,y);
   if(mpz_cmp(r,exp)>=0){
     mpz_mul(mom1,mom1,a);
     mpz_sub(r,r,exp);
   }
   mpz_mod(y,mom1,z);
   mpz_div(exp,exp,due);
 }
 mpz_sub(y,y,a);
 mpz_mod(y,y,z);
 


if(mpz_cmp(y,M)>=0){
     mpz_set(A,y);
     mpz_set(B,M);
   }else{
     mpz_set(A,M);
     mpz_set(B,y);
   }
 
   while(mpz_cmp(B,zero)>0){
     mpz_mod(resto,A,B);
     mpz_set(A,B);
     mpz_set(B,resto);
     
   }
   mpz_set(p,A);

gmp_printf ("\nAAAAAAAAAAAAAAAAAAAAAAA=%Zd\n",a);
   mpz_add(a,a,uno);
 }
 gmp_printf ("\npppppppppp=%Zd\n",p);
gmp_printf ("\naaaaaaaaa=%Zd\n",a);
 gmp_printf ("\nbbbbbbbbbbb=%Zd\n",b);


if(mpz_cmp(N,p)>=0){
     mpz_set(A,N);
     mpz_set(B,p);
   }else{
     mpz_set(A,p);
     mpz_set(B,N);
   }
 
   while(mpz_cmp(B,zero)>0){
     mpz_mod(resto,A,B);
     mpz_set(A,B);
     mpz_set(B,resto);
     
   }
   mpz_set(p,A);

   mpz_mod(mom3,N,p);
 
 if(mpz_cmp(p,uno)!=0  &&  mpz_cmp(p,N)!=0 &&  mpz_cmp(mom3,zero)==0 && mpz_cmp(a,max_a)<0){
   break;
 }
 mpz_set(p,uno);////////////////////////////////////////
 mpz_add(b,b,due);
  gmp_printf ("\na=%Zd\n",a);
 gmp_printf ("\nb=%Zd\n",b);
 }
 mpz_sub(a,a,uno);
 gmp_printf ("\na=%Zd\n",a);
 gmp_printf ("\nb=%Zd\n",b);




 
gmp_printf ("\np=\n%Zd\n",p);

}






int prendi_numero(char in[]){

    char decimale[1000];
    int numero_di_cifre_decimali=0;
    FILE *fp;
    int i=0;

    fp = fopen("input.txt", "r");
    if (fp==NULL){
        printf("\nImpossibile aprire file\n");
        system("PAUSE");
        exit(1);
    }
    while(!feof(fp)){
        fscanf(fp,"%s",decimale);

    }
    fclose(fp);

    numero_di_cifre_decimali=strlen(decimale)-1;
    while(i<=numero_di_cifre_decimali){
        in[i]=decimale[i];
        i++;
    }
    return numero_di_cifre_decimali;
}
