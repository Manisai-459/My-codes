#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} * node;
node insert(node head, int data)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}
void display(node head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
node reverse_k_nodes(node head, int k)
{
    if (!head)
        return NULL;
    node temp = head;
    for (int i = 1; i < k; i++)
    {
        temp = temp->next;
        if (!temp) // if number of nodes are not a multiple of k
            return head;
    }
    temp->next = reverse_k_nodes(temp->next, k); // breaking into parts
    node pre = temp->next, br = temp->next, new;
    while (head != br)
    {
        new = head->next;
        head->next = pre;
        pre = head;
        head = new;
    }
    return pre;
}
int main()
{
    node head = NULL;
    for (int i = 15; i >= 1; i--)
        head = insert(head, i);
    printf("Before : ");
    display(head);
    int k;
    printf("Enter k : ");
    scanf("%d", &k);
    head = reverse_k_nodes(head, k);
    printf("After : ");
    display(head);
    return 0;
}