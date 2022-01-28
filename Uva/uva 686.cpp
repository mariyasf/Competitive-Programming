#include<bits/stdc++.h>
using namespace std;

#define MAX 32768
int arr[MAX], Prime[MAX], c = 0;

void sieve()
{
    int i,j;
    for(int i = 2; i < MAX; i++)
    {
        if(arr[i]==0)
        {
            Prime[c++] = i;
            for (int j = i*i;  j <= MAX; j+=i)

                 arr[j] = 1;
            /*for(int j = 2; i*j < MAX; j++)
                arr[i*j] = 1;
                */
        }
    }
}
int main()
{
    sieve();

    long num;
    while (cin>>num,num)

    {
        int i, x, y,count=0;
        for(i = 0; Prime[i]< num; i++)
        {
            y = num-Prime[i];
            if(Prime[i] > num/2)
                break;
            if(arr[y]==0)
                count++;
        }
        cout<<count<<endl;

    }

    return 0;
}
