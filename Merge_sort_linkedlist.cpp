#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int n;
    struct node *next;
} node;
// ! On 32-bit systems, the size of a generic pointer is typically 4 bytes
node *insert_last(int n, node *head)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->n = n;
    temp->next = NULL;
    if (head == NULL)
        return temp;
    head->next = temp;
    return temp;
}
node *insert_front(int n, node *head)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->n = n;
    temp->next = head;
    return temp;
}
void printList(node *head)
{
    cout << "List is : ";
    while (head)
    {
        cout << head->n << " ";
        head = head->next;
    }
    cout << endl;
}
node *merge(node *l1, node *l2)
{
    node *n1 = l1, *n2 = l2, *prev, *temp;
    prev = n1;
    while (n1 && n2)
    {
        if (n1->n >= n2->n)
        {
            if (l1 == n1)
            {
                temp = n2->next;
                n2->next = n1;
                l1 = n1 = n2;
                n2 = temp;
            }
            else
            {
                temp = n2;
                prev->next = n2;
                n2 = n2->next;
                prev->next->next = n1;
                prev = temp;
            }
        }
        else
        {
            prev = n1;
            n1 = n1->next;
        }
    }
    if (n2 != NULL)
        prev->next = n2;

    return l1;
}
node *sort(node *head)
{
    node *temp;
    if (head->next == NULL)
        return head;
    if (head->next->next == NULL)
    {
        if (head->n > head->next->n)
        {
            head->next->next = head;
            node *temp = head->next;
            head->next = NULL;
            return temp;
        }
        return head;
    }
    node *right;
    node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    temp = slow->next;
    slow->next = NULL;
    return merge(sort(head), sort(temp));
}
int main()
{
    int n, x;
    node *head = NULL, *last = NULL, *right;
    cout << "Enter n : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter elemenet " << (i + 1) << " : ";
        cin >> x;
        if (head == NULL)
            last = head = insert_last(x, head);
        else
            last = insert_last(x, last);
    }
    printList(head);
    head = sort(head);
    printList(head);
    return 0;
}