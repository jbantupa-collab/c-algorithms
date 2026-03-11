#include <stdio.h>
int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}
int main()
{
    int n, W;
    int wt[20], val[20];
    int K[20][20];

    printf("Enter number of items: ");
    scanf("%d", &n);
  
    printf("Enter weights:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d", &wt[i]);

    printf("Enter values:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d", &val[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(wt[i] <= w)
                K[i][w] = max(val[i] + K[i-1][w-wt[i]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    printf("Maximum profit = %d", K[n][W]);

    return 0;
}
