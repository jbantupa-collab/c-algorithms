#include <stdio.h>

int main()
{
    int arr[100], n, i, target, c = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &target);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            printf("Found at index %d\n", i);
            c++;
        }
    }

    if (c == 0)
    {
        printf("Not Present\n");
    }

    return 0;
}