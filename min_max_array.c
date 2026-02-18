#include <stdio.h>

int min, max;

void minmax(int a[], int low, int high)
{
    int mid;

    if (low == high)
    {
        min = max = a[low];
        return;
    }

    if (high == low + 1)
    {
        if (a[low] < a[high])
        {
            min = a[low];
            max = a[high];
        }
        else
        {
            min = a[high];
            max = a[low];
        }
        return;
    }

    mid = (low + high) / 2;

    minmax(a, low, mid);
    int left_min = min;
    int left_max = max;

    minmax(a, mid + 1, high);

    if (left_min < min)
        min = left_min;

    if (left_max > max)
        max = left_max;
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    minmax(a, 0, n - 1);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    return 0;
}