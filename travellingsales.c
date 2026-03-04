#include <stdio.h>

int min(int a, int b)
{
    if(a < b)
        return a;
    return b;
}

int tsp(int n, int graph[n][n], int visited[], int city, int count, int cost, int ans)
{
    if(count == n && graph[city][0] > 0)
    {
        ans = min(ans, cost + graph[city][0]);
        return ans;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0 && graph[city][i] > 0)
        {
            visited[i] = 1;
            ans = tsp(n, graph, visited, i, count + 1, cost + graph[city][i], ans);
            visited[i] = 0;
        }
    }

    return ans;
}

int main()
{
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    int graph[n][n];
    int visited[n];
    int ans = 999;

    printf("Enter distance matrix:\n");
    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    visited[0] = 1;

    ans = tsp(n, graph, visited, 0, 1, 0, ans);

    printf("Minimum travelling cost = %d\n", ans);

    return 0;
}
