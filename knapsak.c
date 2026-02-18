#include <stdio.h>

int main()
{
    int n, W;
    float wt[100], val[100], ratio[100];
    float total = 0.0,temp;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &wt[i]);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &val[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    for (int i = 0; i < n; i++)
        ratio[i] = val[i] / wt[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {

                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = wt[i];
                wt[i] = wt[j];
                wt[j] = temp;

                temp = val[i];
                val[i] = val[j];
                val[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (W >= wt[i])
        {
            W = W - wt[i];
            total = total + val[i];
        }
        else
        {
            total = total + (ratio[i] * W);
            break;
        }
    }

    printf("\nMaximum profit = %.2f\n", total);

    return 0;
}