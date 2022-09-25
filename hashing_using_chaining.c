#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} * node;
void insert(node *a, int data, int k)
{
    int i = data % k;
    node temp = (node)malloc(sizeof(struct node));
    temp->data = data;
    if (a[i] == NULL)
        temp->next = NULL;
    else
        temp->next = a[i];
    a[i] = temp;
}
void display(node *a, int k)
{
    for (int i = 0; i < k; i++)
    {
        node temp = a[i];
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void delete (node *a, int k, int n)
{
    int i = n % k;
    node temp = a[i], pre = a[i];
    while (temp)
    {
        if (temp->data == n)
            break;
        pre = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        printf("data node found");
    else
    {
        if (a[i] == temp)
            a[i] = a[i]->next;
        else
            pre->next = temp->next;
        free(temp);
    }
}
void search(node *a, int k, int n)
{
    int i = n % k;
    node temp = a[i];
    while (temp)
    {
        if (temp->data == n)
            break;
        temp = temp->next;
    }
    if (temp == NULL)
        printf("data node found");
    else
        printf("%d element is in the table", n);
}
int main()
{
    int k, n;
    printf("Enter k in hash function : ");
    scanf("%d", &k);
    node a[k];
    for (int i = 0; i < k; i++)
        a[i] = NULL;
    do
    {
        printf("\n1.insert\n");
        printf("2.delete\n");
        printf("3.search\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("Enter choise : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter n :");
            scanf("%d", &n);
            insert(a, n, k);
            break;
        case 2:
            printf("Enter element to be deleted : ");
            scanf("%d", &n);
            delete (a, k, n);
            break;
        case 3:
            printf("Enter element to be searched : ");
            scanf("%d", &n);
            search(a, k, n);
            break;
        case 4:
            display(a, k);
            break;
        case 5:
            return 0;
        default:
            printf("Enter displayed choises\n");
            break;
        }
    } while (1);
    return 0;
}