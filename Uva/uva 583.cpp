#include<stdio.h>
#include<conio.h>
int main()
{
    int number,i,temp;
    scanf("%d",&number);//taking number
    if(number<0)//if given number is negative we need to times it with -1
    {
        printf("%d = -1 x ",number);//just printing
        number=number*-1;//multiplication by -1
    }
    else
    {
        printf("%d = ",number);//just printing
    }
    for(i=2; i*i<=number; i++) //dividing start from 2 and loop condition is i<=sqrt(number)
    {
        if(number%i==0)//if it is divisible then we proceed
        {
            printf("%d x ",i);
            number=number/i;//number is changing
            temp=i;
            i=1;//i is initialized again
        }
    }
    printf("%d\n",number);
    getch();
    return 0;
}
