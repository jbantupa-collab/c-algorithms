#include <stdio.h>

int main()
{
    int a[100], n, i, t, l, h, m, c = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &t);

    l = 0;
    h = n;

    while (l < h)
    {
        m = (l + h) / 2;

        if (a[m] == t)
        {
            printf("Found at index %d\n", m);
            c++;
            break;
        }
        else if (t < a[m])
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }

    if (c == 0)
    {
        printf("Not Present\n");
    }

    return 0;
}