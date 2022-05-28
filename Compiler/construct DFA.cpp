// Write a C / C++ program to construct DFA that will accept odd number of a 's in a string and the string will start with ' b'.

#include <bits/stdc++.h>
using namespace std;
int a = 0, b = 0, f = 0, state = 0, final = 0;

int check(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[0] == 'b')
            f = 1;
        else
        {
            return 0;
        }
        if (s[i] == 'b')
        {
            if (state == 0)
                state = 2;
            else if (state == 2)
                state = 0;
            else if (state == 3)
                state = 1;
            else if (state == 1)

                state = 3;
        }
        else
        {
            if (state == 0)
                state = 1;
            else if (state == 1)
                state = 0;
            else if (state == 2)
                state = 3;
            else if (state == 3)
                state = 2;
        }
    }
    return state;
}
int main()
{
    string s;
    cin >> s;

    state = check(s);
    if (f && (state == 1 || state == 3))
        puts("Accepted");
    else
        puts("Not Accepted");
}