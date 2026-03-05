# factorization_nr_138132535-

Integer factorization
****************************************************************************
version2_2 seems to be faster than all the others on large numbers
****************************************************************************
version2_2

Input N (number to factor)

P=1

a=2

b=1

while( P==1 || P==N ){

    M=b*N
    
    while(a < max_a){

        X= (a^(M^2-1)-1) mod (N)

        P=gcd(X,N)

        a++
    }
    a=2
    b++
}

Output P (factor of N)

****************************************************************************
version2_3

Input N (number to factor)

P=1

a=2

b=1

c=1

while( P==1 || P==N ){

	M=b*N

    	while(c < max_c){	  
		
		R=M^c
		
		while(a < max_a){

	        	X= (a^(R-1)-1) mod (N)

		        P=gcd(X,N)

		        a++
    		}
	
	a=2
	c++	
	}
    c=1
    b++
}

Output P (factor of N)


version 2_3 is much faster
