#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin>>s;

    if(s.size()==0)
    {
        cout<<0<<endl;
    }

    vector<pair<int,string> >v;
    char ch='a';
    for(int i=0; i<=9; i++)
    {
         string tmp="";
        if(i<2){
            v.push_back({i,tmp});
            continue;
        }
        int c=3;

        if(i == 7 || i==9)c++;
        while(c--)
        {
            tmp+=ch;
            ch++;
        }
        // cout<<tmp<<' ';
        v.push_back({i,tmp});
    }

    for(auto i:v){
        cout<<i.first <<' '<<i.second<<endl;
    }

}
