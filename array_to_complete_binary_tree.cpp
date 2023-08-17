#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *left, *right;
} node;
int main()
{
    node *root = NULL;
    vector<int> q;
    int n;
    cout << "Enter n : ";
    cin >> n;
    cout << "Level " << n << " Elements : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push_back(x);
    }
    vector<node *> qp;
    qp.push_back((node *)malloc(sizeof(node)));
    node *h = qp[0];
    h->data = q[0];
    h->left = NULL;
    h->right = NULL;
    for (int i = 1; i < n; i++)
    {
        if (qp[0]->left != NULL and qp[0]->right != NULL)
            qp.erase(qp.begin());
        if (qp[0]->left == NULL)
        {
            qp[0]->left = (node *)malloc(sizeof(node));
            qp.push_back(qp[0]->left);
            qp[0]->left->data = q[i];
            qp[0]->left->left = NULL;
            qp[0]->left->right = NULL;
        }
        else
        {
            qp[0]->right = (node *)malloc(sizeof(node));
            qp.push_back(qp[0]->right);
            qp[0]->right->data = q[i];
            qp[0]->right->left = NULL;
            qp[0]->right->right = NULL;
        }
    }
    vector<node *> que;
    que.push_back(h);
    while (que.size() != 0)
    {
        int m = que.size();
        while (m)
        {
            node *head = que[0];
            cout << head->data << " ";
            if (head->left != NULL)
                que.push_back(head->left);
            if (head->right != NULL)
                que.push_back(head->right);
            m -= 1;
            que.erase(que.begin());
        }
        cout << endl;
    }
    return 0;
}