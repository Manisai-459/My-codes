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
void BFS(node root)
{
    vector<node> q;
    vector<vector<int>> a;
    vector<int> x, R, L;
    int n;
    q.push_back(root);
    cout << "Level order traversal" << endl;
    while (!q.empty())
    {
        n = q.size();
        L.push_back(q[0]->data);
        while (n > 0)
        {
            node temp = q[0];
            if (n == 1)
                R.push_back(temp->data);
            cout << temp->data << " ";
            x.push_back(temp->data);
            q.erase(q.begin());
            if (temp->l != NULL)
                q.push_back(temp->l);
            if (temp->r != NULL)
                q.push_back(temp->r);
            n--;
        }
        a.push_back(x);
        x.clear();
        cout << endl;
    }
    cout << "Left view : ";
    for (auto i : L)
        cout << i << " ";
    cout << endl;
    cout << "Right view : ";
    for (auto i : R)
        cout << i << " ";
}
int main()
{
    node root = NULL;
    root = insert();
    BFS(root);
    return 0;
}