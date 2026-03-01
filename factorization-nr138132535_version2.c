#include <gmp.h>
#include <stdio.h>

int main() {
  mpz_t a,b,N, M, M2, mod, tmp, result, p,P;

  mpz_inits(a,b,N, M, M2, mod, tmp, result, p,P, NULL);
    int i=0;
    
    mpz_set_str(b, "1", 10);
    mpz_set_str(a, "2", 10);
    mpz_set_str(N, "390644893234047643", 10);
    mpz_set_str(P, "1", 10);
    
    gmp_printf("N = %Zd\n", N);
   
    while(1){
      //M=N*b  
      mpz_mul(M,N,b);
    while(i<100){
    // M2 = M^2
    mpz_mul(M2, M, M);

    // mod = a * M^2
    mpz_mul(mod, a, M2);

    // tmp = a^(M^2) mod (a*M^2)
    mpz_powm(tmp, a, M2, mod);

    // tmp = tmp - a
    mpz_sub(tmp, tmp, a);

    // result = (a^(M^2) - a) mod (a*M^2)
    mpz_mod(result, tmp, mod);

    // p = gcd(result, M)
    mpz_gcd(p, result, M);

    //gmp_printf("result = %Zd\n", result);
    //gmp_printf("p = gcd(result, M) = %Zd\na=%Zd\nb=%Zd\n ",p,a,b);
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