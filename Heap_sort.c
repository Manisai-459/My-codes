#include <stdio.h>
#include <stdlib.h>
void heapify(int *a, int n, int i)
{
    int l = 2 * i + 1, r = 2 * i + 2, max = i;
    if (l < n && a[max] < a[l])
        max = l;
    if (r < n && a[max] < a[r])
        max = r;
    if (max != i)
    {
        a[i] = a[i] + a[max] - (a[max] = a[i]);
        heapify(a, n, max); // ! after swapping then child node may violate max heap rule so we call heapify function again to make perfect max heap tree
    }
}
void display(int *a, int n)
{
    printf("Sorted array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void heap_sort(int *a, int n)
{
    // ! runs O(nlogn)
    for (int i = n / 2; i >= 0; i--) // ! runs  n/2 times
        heapify(a, n, i);            // ! O(logn) - because it starts at ith element in the tree and goes to next level until the height of tree to satisfy mean heap condition
    // ! runs O(nlogn)
    for (int i = n - 1; i >= 0; i--)
    {
        a[i] = a[i] + a[0] - (a[0] = a[i]);
        n--;
        heapify(a, n, 0); // ! O(logn)
    }
    // ! totally : nlogn + nlogn = 2nlogn = O(2nlogn) ~ O(nlogn)
}
int main()
{
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d Elements : ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    heap_sort(a, n);
    display(a, n);
    return 0;
}