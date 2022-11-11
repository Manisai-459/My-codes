#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} * node;
node insert(node head, int data)
{
    node temp = (node)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        return temp;
    head->next = temp;
    return temp;
}
int cycle_detect(node head)
{
    if (head == NULL)
        return 0;
    node slow = head, fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}
int main()
{
    node head = NULL, tail;
    for (int i = 1; i <= 10; i++)
    {
        if (head == NULL)
            tail = head = insert(head, i);
        else
            tail = insert(tail, i);
    }
    node ptr = head;
    for (int i = 1; i < 5; i++)
        ptr = ptr->next;
    tail->next = ptr;
    if (cycle_detect(head))
        printf("cycle is found");
    else
        printf("No cycle in the list");
    return 0;
}