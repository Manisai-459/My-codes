#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char data;
    int freq;
    struct node *left;
    struct node *right;
} * node;
node h[10000];
int fr[100];
char ch[100];
int hs = 0;
void huff()
{
    if (hs == 1)
        return;
    else
    {
        int i = 0, j = 1;
        while (j < hs)
        {
            node temp = (node)malloc(sizeof(struct node)), ptr;
            temp->freq = h[i]->freq + h[j]->freq;
            temp->left = h[i];
            temp->right = h[j];
            h[i] = NULL;
            h[j] = temp;
            for (int k = j; k < hs - 1; k++)
            {
                if (h[k]->freq > h[k + 1]->freq)
                {
                    ptr = h[k];
                    h[k] = h[k + 1];
                    h[k + 1] = ptr;
                }
            }
            j++;
            i++;
        }
    }
}
void insert(char x, int freq)
{
    node temp = (node)malloc(sizeof(struct node));
    temp->data = x;
    temp->freq = freq;
    temp->left = NULL;
    temp->right = NULL;
    if (h[0] == NULL)
    {
        h[0] = temp;
        hs = 1;
    }
    else
    {
        int i = hs - 1;
        while (i >= 0)
        {
            if (h[i]->freq >= temp->freq)
                h[i + 1] = h[i];
            else
                break;
            i--;
        }
        h[i + 1] = temp;
        hs++;
    }
}
void display(node head)
{
    if (!head)
        return;
    printf("%d\n", head->freq);
    display(head->left);
    display(head->right);
}
void print_code(node root, char *code)
{
    if (root->left == NULL && root->right == NULL)
    {
        printf("char %c code is %s\n", root->data, code);
        return;
    }
    int l = strlen(code);
    char lcode[10], rcode[10];
    strcpy(lcode, code);
    strcpy(rcode, code);
    lcode[l] = '0';
    lcode[l + 1] = '\0';
    rcode[l] = '1';
    rcode[l + 1] = '\0';
    print_code(root->left, lcode);
    print_code(root->right, rcode);
}
int get_string()
{
    char *str = (char *)malloc(100);
    printf("Enter string : ");
    scanf("%[^\n]s", str);
    int count = 0, n = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != '-')
        {
            count = 1;
            for (int j = i + 1; j < strlen(str); j++)
            {
                if (str[i] == str[j])
                {
                    count += 1;
                    str[j] = '-';
                }
            }
            ch[n] = str[i];
            fr[n] = count;
            n++;
        }
    }
    free(str);
    return n;
}
int main()
{
    int n;
    n = get_string();
    for (int i = 0; i < n; i++)
        h[i] = NULL;
    for (int i = 0; i < n; i++)
        insert(ch[i], fr[i]);
    huff();
    char code[10];
    code[0] = '\0';
    print_code(h[n - 1], code);
    return 0;
}