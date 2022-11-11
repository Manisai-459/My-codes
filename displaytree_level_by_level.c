#include <stdio.h>
#include <stdlib.h>
#define max 1000
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} * node;
struct q
{
    node root;
    int level;
};

node btree(node root)
{
    int n;
    printf("Enter data [-1 if not] : ");
    scanf("%d", &n);
    if (n == -1)
        return root;
    node temp = (node)malloc(sizeof(struct node));
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    printf("Enter left of %d\n", n);
    temp->left = btree(temp->left);
    printf("Enter right of %d\n", n);
    temp->right = btree(temp->right);
    return temp;
}
void bfs(node root)
{
    struct q queue[1000];
    int R = 0, F = 0, l = 0, pre = 0;
    node temp;
    queue[R].root = root;
    queue[R].level = l;
    while (F <= R)
    {
        temp = queue[F].root;
        l = queue[F].level;
        if (pre != l)
        {
            printf("\n");
            pre = l;
        }
        printf("%d ", temp->data);
        F++;
        if (temp != NULL)
        {
            if (temp->left != NULL)
            {
                R++;
                queue[R].root = temp->left;
                queue[R].level = l + 1;
            }
            if (temp->right != NULL)
            {
                R++;
                queue[R].root = temp->right;
                queue[R].level = l + 1;
            }
        }
    }
}
int main()
{
    node root = NULL;
    root = btree(root);
    bfs(root);
    printf("\n");
    return 0;
}