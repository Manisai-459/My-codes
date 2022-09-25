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
void middle_node(node head)
{
    if (head == NULL)
        printf("List is empty");
    else if (head->next == NULL)
        printf("Middle Node is %d", head->data);
    else
    {
        node slow = head, fast = head->next->next;
        while (fast)
        {
            slow = slow->next;
            if (fast->next == NULL)
            {
                printf("Middle node is %d", slow->data);
                return;
            }
            fast = fast->next->next;
        }
        printf("Middle node is %d", slow->next->data);
    }
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
int main()
{
    node head = NULL;
    for (int i = 6; i >= 1; i--)
        head = insert(head, i);
    display(head);
    middle_node(head);
    return 0;
}