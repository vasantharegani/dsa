#include <stdio.h>
#include <stdbool.h>

#define INF 99999
#define MAX 100

int minDistance(int dist[], bool visited[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[MAX];     // dist[i] will hold the shortest distance from src to i
    bool visited[MAX]; // visited[i] will be true if vertex i is included in shortest path tree

       for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    
    dist[src] = 0;

        for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, visited, V);

                visited[u] = true;

                for (int v = 0; v < V; v++) {
                        if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nDestination \t Shortest Distance from Source (%d)\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("%d \t\t Unreachable\n", i);
        } else {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
}

int main() {
    int V, src;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the weighted adjacency matrix (enter 0 if there is no direct road):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &src);

    dijkstra(graph, V, src);

    return 0;
}