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
int length(node s, node p)
{
    int len = 0;
    do
    {
        s = s->next;
        len++;
    } while (s != p);
    return len;
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
        {
            printf("Length of loop is : %d\n", length(slow, fast));
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            printf("Data at the starting of the loop : %d\n", slow->data);
            return 1;
        }
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
    for (int i = 1; i < 2; i++)
        ptr = ptr->next;
    printf("%d\n", ptr->data);
    tail->next = ptr;
    if (cycle_detect(head) == 0)
        printf("No cycle in the list");
    return 0;
}