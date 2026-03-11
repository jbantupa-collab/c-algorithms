#include <stdio.h>

int w[20], x[20];
int n, target;

void subset(int s, int k)
{
    if (s == target)
    {
        printf("Subset: ");
        for (int i = 0; i < k; i++)
        {
            if (x[i] == 1)
                printf("%d ", w[i]);
        }
        printf("\n");
        return;
    }

    if (k >= n || s > target)
        return;

    x[k] = 1;
    subset(s + w[k], k + 1);

    x[k] = 0;
    subset(s, k + 1);
}

int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    subset(0, 0);

    return 0;
}
