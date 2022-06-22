// Write a C/C++ program to compute First and Follow for each of  the grammer.
// Consider the following Grammer:
// E -> TB
// B -> +TB | ∈
// T -> F Y
// Y -> *F Y | ∈
// F -> (E) | i
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m = 0, p;
char a[10][10];
char f[10];
void follow(char c);
void first(char c);
void follow(char c)
{
    if (a[0][0] == c)
        f[m++] = '$';
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < strlen(a[i]); j++)
        {
            if (a[i][j] == c)
            {
                if (a[i][j + 1] != '\0')
                    first(a[i][j + 1]);
                if (a[i][j + 1] == '\0' && c != a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}

void first(char c)
{
    if (!isupper(c))
        f[m++] = c;
    for (int k = 0; k < n; k++)
    {
        if (a[k][0] == c)
        {
            if (a[k][2] == '$')
                follow(a[k][0]);
            else if (islower(a[k][2]))
                f[m++] = a[k][2];
            else
                first(a[k][2]);
        }
    }
}

int main()
{
    int z = 1;
    char c, ch;
    cout << "Enter the no of production : ";

    cin >> n;
    cout << "Enter the productions:" << endl;

    for (int i = 0; i < n; i++)
        scanf("%s%c", a[i], &ch);

    while (z == 1)
    {
        m = 0;
        printf("enter the element first and follow is to be found:");
        cin >> c;

        first(c);

        cout << endl
             << "FIRST(" << c << ") = { ";

        set<char> frst;
        for (int i = 0; i < m; i++)
        {
            frst.insert(f[i]);
        }
        for (auto i : frst)
            cout << i << ", ";
        printf("}\n");

        strcpy(f, " ");

        m = 0;
        follow(c);
        cout << "FOLLOW(" << c << ") = { ";

        set<char> flw;
        for (int i = 0; i < m; i++)
        {
            if (f[i] != '?')
                flw.insert(f[i]);
        }
        for (auto i : flw)
            cout << i << ", ";

        printf("}\n\n");
        cout << "continue(0/1).......? ";
        cin >> z;
    }
}

// 8
// E=TB
// B=+TB
// B=∈
// T=FY
// Y=*FY
// Y=∈
// F=(E)
// F=i
// E
// B
// T
// Y
