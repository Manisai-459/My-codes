#include <stdio.h>
void insert(int *a, int n, int k, int data)
{
    int j = data % k;
    if (a[j] == 0)
        a[j] = data;
    else
    {
        int d;
        for (int i = 1; i < n; i++)
        {
            d = (j + i) % n;
            if (a[d] == 0)
            {
                a[d] = data;
                printf("probe = %d\n", i);
                return;
            }
        }
        printf("Hash table over flow");
    }
}
void delete (int *a, int n, int k, int data)
{
    int j = data % k;
    if (a[j] == data)
        a[j] = 0;
    else
    {
        int d;
        for (int i = 1; i < n; i++)
        {
            d = (j + i) % n;
            if (a[d] == 0)
            {
                a[d] = 0;
                printf("successfully deleted\n");
                return;
            }
        }
        printf("element not found");
    }
}
void search(int *a, int n, int k, int data)
{
    int j = data % k;
    if (a[j] == data)
        printf("%d is in the hash table\n", a[j]);
    else
    {
        int d;
        for (int i = 1; i < n; i++)
        {
            d = (j + i) % n;
            if (a[d] == data)
            {
                printf("%d is in the hash table\n", a[d]);
                return;
            }
        }
        printf("element not found");
    }
}
int main()
{
    int k, n, d;
    printf("Enter k for hash function : ");
    scanf("%d", &k);
    printf("Enter no of elements do you want to insert : ");
    scanf("%d", &n);
    if (n < k)
        d = k;
    else
        d = n;
    int a[d];
    for (int i = 0; i < n; i++)
        a[i] = 0;
    do
    {
        printf("\n1.insert\n");
        printf("2.delete\n");
        printf("3.search\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("Enter choise : ");
        scanf("%d", &d);
        switch (d)
        {
        case 1:
            printf("Enter element : ");
            scanf("%d", &d);
            insert(a, n, k, d);
            break;
        case 2:
            printf("Enter element : ");
            scanf("%d", &d);
            delete (a, n, k, d);
            break;
        case 3:
            printf("Enter element : ");
            scanf("%d", &d);
            search(a, n, k, d);
            break;
        case 4:
            for (int i = 0; i < n; i++)
                printf("%d\n", a[i]);
            break;
        case 5:
            return 0;
        default:
            printf("enter displayed choises only\n");
        }
    } while (1);
    return 0;
}