#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(gcd(a, b) == 1)
            printf("%10d%10d    Good Choice\n", a, b);
        else
            printf("%10d%10d    Bad Choice\n", a, b);
        puts("");
    }
    return 0;
    
    /**
    
    long long step, mod;

    while (cin >> step >> mod)
    {
        long long x = step, speed = mod;

        /**while(step%mod)
        {
            int t=step;
            step=mod;
            mod=t%step;
            ///cout<<mod<<" ";
        }
        if(mod==1) printf("%10d%10d    Good Choice\n", x,speed);
        else  printf("%10d%10d    Bad Choice\n", x,speed);

        
       int flag=0;

        for (int i = 0; i < mod; i++)
        {
            speed = (x + step) % mod;
           /// cout << speed << " ";

            if (speed == 1)
            {
                flag = 1;
                break;
            }
            ///arr[speed] == 1;
            x = speed;
        }
        if(flag==1) printf("%10d%10d    Good Choice\n", step,mod);
        else  printf("%10d%10d    Bad Choice\n", step,mod);

        cout << endl;
    }
    
    */
}
