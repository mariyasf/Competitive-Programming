#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
        char ch;
        int freq;
        struct node *left;
        struct node *right;
} Node;

Node *heap[100];
int heapSize = 0;
void Insert(Node *element)
{
        heapSize++;
        heap[heapSize] = element;
        int now = heapSize;
        while (heap[now / 2]->freq > element->freq)
        {
                heap[now] = heap[now / 2];
                now /= 2;
        }
        heap[now] = element;
}
Node *DeleteMin()
{
        Node *minElement, *lastElement;
        int child, now;
        minElement = heap[1];
        lastElement = heap[heapSize--];
        for (now = 1; now * 2 <= heapSize; now = child)
        {
                child = now * 2;
                if (child != heapSize && heap[child + 1]->freq < heap[child]->freq)
                {
                        child++;
                }
                if (lastElement->freq > heap[child]->freq)
                {
                        heap[now] = heap[child];
                }
                else
                {
                        break;
                }
        }
        heap[now] = lastElement;
        return minElement;
}
int bit_size_store[1000], p = 0;
void print(Node *temp, char *code)
{

        if (temp->left == NULL && temp->right == NULL)
        {
                int t = strlen(code);

                bit_size_store[p++] = t;

                printf("%c code: %s\n", temp->ch, code);

                return;
        }

        int length = strlen(code);
        char leftcode[10], rightcode[10];

        strcpy(leftcode, code);
        strcpy(rightcode, code);

        leftcode[length] = '0';
        leftcode[length + 1] = '\0';
        rightcode[length] = '1';
        rightcode[length + 1] = '\0';

        print(temp->left, leftcode);
        print(temp->right, rightcode);
}
int main()
{
        heap[0] = (Node *)malloc(sizeof(Node));
        heap[0]->freq = 0;
        int n;
        cout << "Enter the no of characters: ";

        cin >> n;

        char c[n + 2];
        int frequ[n + 2], i, frequency_sum = 0;

        cout << "Enter the characters and their frequencies: " << endl;
        for (i = 0; i < n; i++)
        {
                cin >> c[i] >> frequ[i];
                frequency_sum += frequ[i];
        }
        string s[n + 2];
        int Before_huffman_sum_of_bit = 0;
        cout << "Enter the characters Bit : " << endl;
        for (i = 0; i < n; i++)
        {
                cout << c[i] << " code: ";
                cin >> s[i];
                // cout << c[i] << " code: " << s[i] << endl;

                Before_huffman_sum_of_bit += (s[i].size() * frequ[i]);
        }
        cout << "Before huffman sum of bit :" << Before_huffman_sum_of_bit << endl;
        cout << endl;

        for (i = 0; i < n; i++)
        {

                Node *temp = (Node *)malloc(sizeof(Node));

                temp->ch = c[i];
                temp->freq = frequ[i];
                temp->left = temp->right = NULL;

                Insert(temp);
        }
        if (n == 1)
        {
                printf("%c code: 0\n", c[0]);
                return 0;
        }
        for (i = 0; i < n - 1; i++)
        {
                Node *left = DeleteMin();
                Node *right = DeleteMin();
                Node *temp = (Node *)malloc(sizeof(Node));

                temp->ch = 0;
                temp->left = left;
                temp->right = right;
                temp->freq = left->freq + right->freq;
                Insert(temp);
        }
        Node *tree = DeleteMin();
        char code[10];
        code[0] = '\0';
        print(tree, code);
        int after_huffman_sum_of_bit = 0;

        for (i = 0; i < n; i++)
        {
                // cout << after_huffman_sum_of_bit_arr[i] << ' ';

                after_huffman_sum_of_bit += (bit_size_store[i] * frequ[i]);
        }
        // cout << endl;

        cout << "After huffman sum of bit :" << after_huffman_sum_of_bit << endl;
        cout << endl;
}