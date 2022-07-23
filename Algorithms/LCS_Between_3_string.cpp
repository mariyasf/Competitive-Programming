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

int lcs(string s1, string s2, string s3)
{

    int len1 = s1.size();
    int len2 = s2.size();
    int len3 = s3.size();
    int LCS[len1 + 1][len2 + 1][len3 + 1];
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            for (int k = 0; k <= len3; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    LCS[i][j][k] = 0;
                else if ((s1[i - 1] == s2[j - 1]) && (s1[i - 1] == s3[k - 1]))
                    LCS[i][j][k] = 1 + LCS[i - 1][j - 1][k - 1];
                else
                    LCS[i][j][k] = max(max(LCS[i - 1][j][k],
                                           LCS[i][j - 1][k]),
                                       LCS[i][j][k - 1]);
            }
        }
    }
    return LCS[len1][len2][len3];
}
void solve()
{
    vs v(3);
    mpsi mp;

    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }
    string s;
    int n = 0;

    n = lcs(v[0], v[1], v[2]);
    cout << n << endl;
}
void test()
{
    int t = 1, c = 1;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        cout << "Case " << c++ << ": ";
        solve();
    }
}

int32_t main()
{
    fast;

    test();
    // solve();
    return 0;
}

/**
Input:

3

abcdef
cdef
dcdef

aaaa
bbbb
ccca

aaaa
aaaa
aaa

Output:

Case 1: 4
Case 2: 0
Case 3: 3

*/
