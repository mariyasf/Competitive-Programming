#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max 10000

ll Stack[max], pos = -1;

void push(int n)
{
    if (pos == max - 1)
    {
        cout << "stack is already full...\n";
        return ;
    }
    else
    {
         pos++;
        Stack[pos] = n;
    }
}

void pop()
{
    if (pos == -1)
    {
        cout << "stack is already empty....\n";
        return ;
    }
    else
    {
        int x;
        x=Stack[pos];
        pos--;

        cout<<"Pop the item "<<x<<endl;
    }

}

void top()
{
    if (pos == -1)
    {
        cout << "stack is already empty\n";
        return ;
    }

    else
    {
        cout<<"Top element is "<< Stack[pos]<<endl;
    }

}
void empty()
{
    if(pos == -1)
    {
        cout<<"Stack is empty!"<<endl;
    }
    else
    {
        cout<<"Stack is not empty!"<<endl;
    }
}

void display()
{
    for(int i=pos;i>=0;i--)
    {
        cout<<Stack[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        push(a) ;

    }
    display();
    push(100);
    display();
    pop();
    top();
    empty();



    return 0;
}
