#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int n;
    struct node *left, *right;
} node;
int x;
node *tree()
{
    printf("Enter data ( if not enter -1 ) : ");
    scanf("%d", &x);
    if (x == -1)
        return NULL;
    node *temp = (node *)malloc(sizeof(node));
    temp->n = x;
    temp->left == NULL;
    temp->right == NULL;
    printf("Enter left of %d\n", temp->n);
    temp->left = tree();
    printf("Enter right of %d\n", temp->n);
    temp->right = tree();
    return temp;
}
int maxleft(node *head)
{
    if (head == NULL)
        return -1000000;
    int l = maxleft(head->left);
    int r = maxleft(head->right);
    l = l > r ? l : r;
    return l > head->n ? l : head->n;
}
int minright(node *head)
{
    if (head == NULL)
        return -1000000;
    int l = minright(head->left);
    int r = minright(head->right);
    l = l < r ? l : r;
    return l < head->n ? l : head->n;
}
int isBST(node *head)
{
    if (!head)
        return 1;
    if (head->left != NULL && head->n <= maxleft(head->left))
        return 0;
    if (head->right != NULL && head->n >= minright(head->right))
        return 0;
    return isBST(head->left) * isBST(head->right);
}
int main()
{
    node *head = tree();
    if (isBST(head) == 1)
        printf("it is BST\n");
    else
        printf("not a BST\n");
    return 0;
}