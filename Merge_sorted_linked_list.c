#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
} * node;
node insert(node head, int data)
{
    node temp = (node)malloc(sizeof(struct node));
    temp->val = data;
    temp->next = head;
    return temp;
}
void display(node head)
{
    while (head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
}
node merge(node head1, node head2)
{
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
    else
    {
        node temp = head1, pre;
        while (head2)
        {
            temp = head1;
            pre = head1;
            while (temp)
            {
                if (temp->val > head2->val)
                    break;
                pre = temp;
                temp = temp->next;
            }
            if (temp == head1)
            {
                temp = head2;
                head2 = head2->next;
                temp->next = head1;
                head1 = temp;
            }
            else
            {
                pre->next = head2;
                head2 = head2->next;
                pre->next->next = temp;
            }
        }
    }
    return head1;
}
int main()
{
    node head1 = NULL, head2 = NULL;
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
            break;
        head1 = insert(head1, n);
    }
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
            break;
        head2 = insert(head2, n);
    }
    display(head1);
    printf("\n");
    display(head2);
    head1 = merge(head1, head2);
    printf("\n");
    display(head1);
    return 0;
}