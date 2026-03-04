#include <gmp.h>
#include <stdio.h>

int main() {
  mpz_t a,b,N, M, R, mod, tmp, result, p,P;

  mpz_inits(a,b,N, M, R, mod, tmp, result, p,P, NULL);
  int i=0;
  unsigned long int c = 1; 
  mpz_set_str(b, "1", 10);
  mpz_set_str(a, "2", 10);
  mpz_set_str(N, "390644893234047643", 10);
  mpz_set_str(P, "1", 10);
  mpz_set_str(M, "0", 10);
  gmp_printf("N = %Zd\n", N);
    
    
  while(1){
    //M=N*b  
    mpz_add(M,M,N);
    
    while(c<=20){
      mpz_pow_ui(R, M, c);
      while(i<100){
	
	// tmp = R-1
	mpz_sub_ui(tmp, R,1);

	// tmp = a^(R-1) mod (N)
	mpz_powm(tmp, a,tmp, N);

	// tmp = tmp - 1
	mpz_sub_ui(tmp, tmp, 1);

	// P = gcd(tmp, N)
	

	mpz_gcd(P,N,tmp);
	
	if(mpz_cmp_ui(P,1)!=0 && mpz_cmp(N,P)!=0){
	  gmp_printf("P= %Zd\na=%Zd\nb=%Zd\nc=%li\n",P,a,b,c);
	  return 0;
	}

	mpz_add_ui(a,a,1);
	i++;
      }  
      mpz_set_ui(a,2);
      i=0;
      c++;
      }
      c=1;
    
      mpz_add_ui(b,b,1);    
    }
    
    return 0;
}
