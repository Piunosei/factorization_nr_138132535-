#include <gmp.h>
#include <stdio.h>

int main() {
  mpz_t a,b,N, M, M2, mod, tmp, result, p,P;

  mpz_inits(a,b,N, M, M2, mod, tmp, result, p,P, NULL);
    int i=0;
    
    mpz_set_str(b, "1", 10);
    mpz_set_str(a, "2", 10);
    mpz_set_str(N, "900075698453", 10);
    mpz_set_str(P, "1", 10);
    mpz_set_str(M, "0", 10);
    gmp_printf("N = %Zd\n", N);
    
    
    while(1){
      //M=N*b  
      mpz_add(M,M,N);
      // M2 = M^2
      mpz_mul(M2,M,M);
      
   
      while(i<100){
    

	// tmp = M^2-1
	mpz_sub_ui(tmp, M2,1);

	// tmp = a^(M^2-1) mod (M^2)
	mpz_powm(tmp, a,tmp, M2);

	// tmp = tmp - 1
	mpz_sub_ui(tmp, tmp, 1);

	// p = gcd(result, M)
	mpz_gcd(p, tmp, M);

	mpz_gcd(P,N,p);
	
    if(mpz_cmp_ui(P,1)!=0 && mpz_cmp(N,P)!=0){
       gmp_printf("P= %Zd\na=%Zd\nb=%Zd\n ",P,a,b);
       return 0;
    }

    mpz_add_ui(a,a,1);
    i++;
    }  
    
    mpz_set_ui(a,2);
    i=0;
    mpz_add_ui(b,b,1);    
    }
    mpz_clears(a, M, M2, mod, tmp, result, p, NULL);
    return 0;
}
