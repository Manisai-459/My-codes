#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *l;
    struct Node *r;
} * node;
node insert()
{
    int n;
    cout << "Enter element [ -1 if not ] : ";
    cin >> n;
    if (n == -1)
        return NULL;
    node temp = (node)malloc(sizeof(struct Node));
    temp->data = n;
    cout << "Enter left child of " << n << endl;
    temp->l = insert();
    cout << "Enter right child of " << n << endl;
    temp->r = insert();
    return temp;
}
void zig_zag(node root)
{
    if (root == NULL)
        return;
    vector<node> s1, s2;
    s1.push_back(root);
    while (s1.size() != 0 || s2.size() != 0)
    {
        while (s1.size())
        {
            node temp = s1[s1.size() - 1];
            cout << temp->data << " ";
            if (temp->l != NULL)
                s2.push_back(temp->l);
            if (temp->r != NULL)
                s2.push_back(temp->r);
            s1.erase(s1.end() - 1);
        }
        cout << endl;
        while (s2.size())
        {

            node temp = s2[s2.size() - 1];
            cout << temp->data << " ";
            if (temp->r != NULL)
                s1.push_back(temp->r);
            if (temp->l != NULL)
                s1.push_back(temp->l);
            s2.erase(s2.end() - 1);
        }
        cout << endl;
    }
}
int main()
{
    node root = NULL;
    root = insert();
    zig_zag(root);
    return 0;
}