#include <stdio.h>

#include <math.h>

#include <stdlib.h>

long primes[4000];

int pi;

int isPrime(long num)

{

    int i;

    long lim;

    lim = (long)sqrt(num);

    for (i = 0; i < pi && primes[i] <= lim; i++)

        if (num % primes[i] == 0)

            return 0;

    return 1;

}

void genPrime(long lim)

{

    long n;

    primes[0] = 2;

    primes[1] = 3;

    pi = 2;

    for (n = 5; n <= lim; n += 2)

        if (isPrime(n))

        {

            primes[pi] = n;

            pi++;

        }

}
int main()

{

    long num, lim, i ;

//memset(primes, 0, sizeof(primes));

    lim = (long)(pow(2, 15));

    genPrime(lim);

    while (scanf("%ld", &num) == 1 && num != 0)

    {
        int i, x, y,count=0;
        for(i = 0; primes[i]< num; i++)
        {
            //x = primes[i];
            y = num-primes[i];
            if(primes[i] > num/2)	break;
            if(isPrime(y))	count++;
        }
        printf("%d\n", count);
    }

    return 0;

}
