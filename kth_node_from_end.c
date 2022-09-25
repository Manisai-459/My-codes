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
void kth_node_from_last(node front, int k)
{
    if (front == NULL)
        printf("List is empty");
    else
    {
        if (k < 1)
            printf("Invalid Input");
        else
        {
            node k_node = front;
            while (front)
            {
                front = k_node;
                for (int i = 1; i <= k; i++)
                { // my head must reach null only after succesful execution of for loop , if in middle my head is null then the input node number is greater than the no of nodes
                    if (front == NULL)
                    {
                        printf("excess value for k");
                        return;
                    }
                    front = front->next;
                }
                if (front != NULL)
                    k_node = k_node->next;
            }
            printf("%d node from end is %d", k, k_node->data);
        }
    }
}
int main()
{
    node head = NULL;
    for (int i = 2; i >= 1; i--)
        head = insert(head, i);
    int k;
    display(head);
    printf("Enter k : ");
    scanf("%d", &k);
    kth_node_from_last(head, k);
}