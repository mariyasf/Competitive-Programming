#include<bits/stdc++.h>
using namespace std;

int main()
{

    char a[7];

    int b,c;

    b = c = 0;

    int sum =0;

    while(scanf("%s %d %d",a,&b,&c)!=EOF)
    while(cin>>a>>b>>c)
    {

        sum = strtol(a,NULL, b);

        if(sum ==0)
            cout <<"      0" << endl ;

        else
        {

            char m[7] = {0};

            for(int i =0; i!=7; ++i)
            {

                int temp = sum % c;

                if(temp >=10)
                {

                    char n;

                    n = temp + 55;

                    m[6-i] = n;

                }

                else m[6-i] = temp +48 ;

                sum /= c;

            }

            if(sum !=0)
                cout <<"  ERROR" <<endl;

            else
            {

                int i, j;

                i = j = 0;

                while(m[j]=='0')
                {
                    ++j;
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
