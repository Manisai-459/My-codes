#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *left, *right;
} *node;
node insert()
{
    node ptr = new struct Node;
    int n;
    cout << "Enter data ( -1 if not ) : ";
    cin >> n;
    if (n == -1)
        return NULL;
    ptr->data = n;
    cout << "Enter left of " << n << endl;
    ptr->left = insert();
    cout << "Enter right of " << n << endl;
    ptr->right = insert();
    return ptr;
}
bool check(node l, node r)
{
    if (l == NULL && r == NULL)
        return true;
    if (l == NULL || r == NULL)
        return false;
    if (l->data != r->data)
        return false;
    return check(l->left, r->right) && check(l->right, r->left);
}
bool symmetry(node root)
{
    if (root->left == NULL || root->right == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)
        return true;
    return check(root->left, root->right);
}
int main()
{
    node root = insert();
    cout << symmetry(root);
    return 0;
}