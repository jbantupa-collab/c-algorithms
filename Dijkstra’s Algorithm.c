#include <stdio.h>

int main()
{
    int n, source;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n], dist[n], visited[n];

    printf("Enter cost matrix (use 9999 for infinity):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

  
    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    
    for (int i = 1; i < n; i++)
    {
        int min = 9999, u = -1;

        // Find minimum distance vertex
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        
        for (int v = 0; v < n; v++)
        {
            if (visited[v] == 0 &&
                dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("\nShortest distances from source %d:\n", source);

    for (int i = 0; i < n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}
