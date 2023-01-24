#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    map<char,int>vp{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    long long sum =0;
    for(int i=0; i<s.size(); i++)
    {
        if(vp[s[i]] < vp[s[i+1]])
            sum -= vp[s[i]];
        else sum += vp[s[i]];
    }
    cout<<sum<<endl;



    return 0;
}

