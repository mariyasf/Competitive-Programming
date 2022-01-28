#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max 1000

ll Queue[max];
int in_pos = -1, out_pos = 0;

void push(int n)
{
    if (in_pos == max - 1)
    {
        cout << "Queue is already full\n";
        return;
    }
    else
    {
        in_pos++;
        Queue[in_pos] = n;
    }
}

bool empty()
{
    return (in_pos == out_pos);
}

void pop()
{
    if (empty() == true)
    {
        cout << "Already empty..\n";
    }
    else
    {
        cout << "Pop the element is " << Queue[out_pos] << endl;
        out_pos++;
    }
    cout << endl;
}

void front()
{
    cout << "Front element is " << Queue[out_pos] << endl;
    cout << endl;
}

void back()
{
    cout << "Back element is " << Queue[in_pos] << endl;
    cout << endl;
}

void display()
{
    cout << "The Queue element is :" << endl;
    for (int i = out_pos; i <= in_pos; i++)
    {
        cout << Queue[i] << " ";
    }

    cout << endl;
    cout << endl;
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        push(a);
    }

    display();
    pop();
    display();
    back();
    if (empty())
        cout << "Alread empty..." << endl;
    else
        cout << "Not empty..." << endl;
    front();

    return 0;
}
