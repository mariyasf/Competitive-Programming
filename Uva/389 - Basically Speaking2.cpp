#include<bits/stdc++.h>
using namespace std;
char m[7] = {0};
int main()
{
    char s[7];
    int b,c;
    int sum =0;
    while(cin>>s>>b>>c)
    {
        sum = strtol(s,NULL, b);///Convert string to long integer
        if(sum ==0)
            cout <<"      0" << endl ;
        else
        {

            for(int i =0; i<7; i++)
            {
                int temp = sum % c;
                sum /= c;

                if(temp >=10)
                {
                    char n;
                    n = temp + 55;
                    m[6-i] = n;
                }

                else m[6-i] = temp +48 ;

            }

            if(sum)
                cout <<"  ERROR" <<endl;

            else
            {
                int i, j;
                i = j = 0;
                while(m[j]=='0')
                {
                    j++;
                    cout <<" ";
                }

                for(int i = j; i <7; i++)
                {
                    cout << m[i];
                }
                cout <<endl;
            }
        }
    }

    return 0;

}
