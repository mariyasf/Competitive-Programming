/*                Problem ID : 498_-_Polly_the_Polynomial.cpp */
/*             Date: 2023-02-06 23:15:39 */
#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define all(c) c.begin(), c.end()
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long int>
#define vpii vector<pair<int, int>>
#define mpi map<int, int>
#define mpl map<ll, ll>
#define mpsi map<string, ll>
#define maap(x, y) make_pair(x, y)
#define rall(x) x.rbegin(), x.rend()
#define nl "\n"
#define NO cout << "NO" << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define YES cout << "YES" << endl;
int Ceil(int a, int b)
{
    return (a + b - 1) / b;
}
int Floor2(int a, int b)
{
    return floor((double)a / (double)b);
}
ll Max(ll a, ll b)
{
    return (a >= b ? a : b);
}
vll setint(string s)
{
    vll v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-')
        {
            string x = "";
            while (s[i] != ' ' && i < s.size())
            {
                x += s[i];
                i++;
            }
            v.pb(stoi(x));
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            string x = "";
            while (s[i] != ' ' && i < s.size())
            {
                x += s[i];
                i++;
            }
            v.pb(stoi(x));
        }
    }
    return v;
}
int32_t main()
{
    fast;
    string s;
    while (getline(cin, s))
    {
        vll v;
        v = setint(s);

        ll n = v.size();

        string xSet;
        getline(cin, xSet); 

        vll x;
        x = setint(xSet);
        ll c = 0;
        for (auto it : x)
        {
            vll res(n, 0);
            res[0] = v[0];

            for (int i = 1; i < n; i++)
            {
                res[i] = (res[i - 1] * it) + v[i];
            }

            if (c == x.size() - 1)
                cout << res[n - 1] << endl;
            else
                cout << res[n - 1] << ' ';
            c++;
        } 
    }
    return 0;
}
