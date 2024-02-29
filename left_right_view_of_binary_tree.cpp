#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int n;
    struct Node *l, *r;
} *node;
node insert()
{
    int n;
    cout << "Enter element [ if not -1 ] : ";
    cin >> n;
    if (n == -1)
        return NULL;
    node temp = (node)malloc(sizeof(struct Node));
    temp->n = n;
    cout << "Enter left chilf of " << n << endl;
    temp->l = insert();
    cout << "Enter right child of " << n << endl;
    temp->r = insert();
    return temp;
}
void left_view(node head, int l, int *max_l)
{
    if (head == NULL)
        return;
    if (l > *max_l)
    {
        cout << head->n << " ";
        *max_l = l;
    }
    left_view(head->l, l + 1, max_l);
    left_view(head->r, l + 1, max_l);
}
void right_view(node head, int l, int *max_l)
{
    if (head == NULL)
        return;
    if (l > *max_l)
    {
        cout << head->n << " ";
        *max_l = l;
    }
    right_view(head->r, l + 1, max_l);
    right_view(head->l, l + 1, max_l);
}
int main()
{
    node head = insert();
    int *max_l = (int *)malloc(sizeof(int));
    *max_l = -1;
    cout << "Left view : ";
    left_view(head, 0, max_l);
    cout << endl;
    *max_l = -1;
    cout << "Right view : ";
    right_view(head, 0, max_l);
    return 0;
}