#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX], visited[MAX];
int queue[MAX], front = -1, rear = -1;

void bfs(int start, int n) {
    printf("BFS Traversal: ");
    front = rear = 0;
    queue[rear] = start;
    visited[start] = 1;

    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int start, int n) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, edges, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1; // For undirected graph
    }

    printf("Enter starting vertex for traversal: ");
    scanf("%d", &start);

    // BFS
    for (int i = 0; i < n; i++) visited[i] = 0;
    bfs(start, n);

    // DFS
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS Traversal: ");
    dfs(start, n);
    printf("\n");

    return 0;
}
