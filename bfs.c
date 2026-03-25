#include <stdio.h>
int main() {
    int graph[10][10], visited[10];
    int queue[10];
    int front = 0, rear = 0;
    int n, i, j, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter starting node: ");
    scanf("%d", &start);

    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }
    queue[rear++] = start;
    visited[start] = 1;
    
    printf("BFS Traversal: ");

    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for(i = 0; i < n; i++) {
            if(graph[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}
    
