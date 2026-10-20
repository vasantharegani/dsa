#include <stdio.h>

#define MAX 20

void BFS(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0}; // Tracking array to prevent repeating vertices
    int queue[MAX];
    int front = 0, rear = 0;

    printf("\nGraph Traversal Visit Order: ");

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            // If an edge exists and the vertex hasn't been visited yet
            if (adj[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1; // Mark as visited to prevent repeated processing
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;
    int adj[MAX][MAX];

    printf("Enter the number of locations (vertices): ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 for no edge, 1 for an edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting vertex!\n");
        return 1;
    }

    BFS(adj, n, start);

    return 0;
} 