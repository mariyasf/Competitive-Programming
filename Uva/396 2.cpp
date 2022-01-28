#include <stdio.h>

int main (void)
{
    double m,n,a,b,c;

    while(scanf("%lf %lf",&m,&n)==2 && m && n)
    {


        c=1;
        a=m;
        b=m-n;

        if(b>n) b=n;

        while(b)
        {
            c = c*(a/b);
            a--;
            b--;
        }


        printf("%.0lf things taken %.0lf at a time is %.0lf exactly.\n",m,n,c);

    }
}
