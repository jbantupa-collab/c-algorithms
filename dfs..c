#include <stdio.h>

int graph[10][10], visited[10], n;

void dfs(int node) {
    int i;

    printf("%d ", node);   
    visited[node] = 1;     

    for(i = 0; i < n; i++) {
        if(graph[node][i] == 1 && visited[i] == 0) {
            dfs(i);        
        }
    }
}

int main() {
    int i, j, start;

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

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}
