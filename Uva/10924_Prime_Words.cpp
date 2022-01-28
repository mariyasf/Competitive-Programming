#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 10000007
#define meme(a) memset(a, 0, sizeof(a))
bool primes[MAX];
ll temp[MAX];
ll c;

void FASTIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Sieve()
{
    meme(primes);
    c = 0;
    primes[0] = primes[1] = 1;

    for (ll i = 2; i * i <= MAX; i++)
    {
        if (primes[i] == 0)
        {

            for (ll j = i * i; j <= MAX; j += i)
                primes[j] = 1;
        }
    }

    for (int i = 2; i < MAX; i++)
    {
        if (primes[i] == 0)
            temp[c] = i, c++;
    }
}

int main()
{
    FASTIO();
    Sieve();
    string s;

    while (cin >> s)
    {
        ll sum = 0;
        int a[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
        int b[26] = {27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52};
        if (s.size() == 1)
        {
            if (s[0] == 'a')
            {

                cout << "It is a prime word." << endl;
                continue;
            }
        }
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                int ans = a[s[i] - 'a'];
                // cout << ans << ' ';
                sum += ans;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                int ans = b[s[i] - 'A'];
                //  cout << ans << ' ';
                sum += ans;
            }
        }
        // cout << sum << endl;

        if (!primes[sum])
        {
            cout << "It is a prime word." << endl;
        }
        else
        {
            cout << "It is not a prime word." << endl;
        }
    }

    return 0;
}