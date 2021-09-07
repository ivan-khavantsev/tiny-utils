#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    unsigned long long n1, n2, i, gcd;
	long double  m1, m2;

    if (argc != 3) {
        fprintf (stderr, "Usage: %s <number> <number>\a\n", argv[0]);
        exit(1);
    }

    //printf("Enter two positive integers: ");
    //scanf("%d %d", &n1, &n2);
    sscanf(argv[1], "%llu", &n1);
    sscanf(argv[2], "%llu", &n2);

    for(i=1; i <= n1 && i <= n2; ++i)
    {
		m1 = n1%i;
		m2 = n2%i;
        // Checks if i is factor of both integers
        if(m1 == 0 && m2 == 0){
        	gcd = i;
        	printf("%llu (%llu, %llu)\n\r", i, n1/i, n2/i);
        }
            
    }

    printf("G.C.D of %llu and %llu is %llu \n\r", n1, n2, gcd);

    return 0;
}
