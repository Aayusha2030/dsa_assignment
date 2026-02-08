#include <stdio.h>
#include <limits.h>

#define NODES 6 // Graph ma total nodes / Total nodes in graph

// Function to find minimum distance node yet to be visited
// Sabai nodes ko distance herera nearest node khojne
int findNearestNode(int dist[], int visited[]) {
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < NODES; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to calculate shortest paths from source
// Source bata sabai node samma shortest distance calculate garne
void shortestPathCalculator(int graph[NODES][NODES], int start) {
    int dist[NODES];     // Source bata node samma ko distance
    int visited[NODES] = {0}; // Visited nodes track garne

    // Sabai distances initialize garne infinite ma
    for (int i = 0; i < NODES; i++) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0; // Source node ko distance 0

    // Process garne sabai nodes
    for (int count = 0; count < NODES - 1; count++) {
        int u = findNearestNode(dist, visited); // Minimum distance node select
        visited[u] = 1; // Node mark garne as visited

        // Neighbor nodes ko distance update garne
        for (int v = 0; v < NODES; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    // Shortest distances print garne
    printf("\nNode\tShortest Distance from Source %d\n", start);
    for (int i = 0; i < NODES; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}
int main() {
    // Weighted graph adjacency matrix
    // 0 bhaye direct connection chaina
    int graph[NODES][NODES] = {
        {0, 10, 0, 30, 100, 0},
        {10, 0, 50, 0, 0, 0},
        {0, 50, 0, 20, 10, 0},
        {30, 0, 20, 0, 60, 0},
        {100, 0, 10, 60, 0, 0},
        {0, 0, 0, 0, 0, 0} // isolated node for testing
    };
    int sourceNode = 0; // Start node / suru node
    printf("Calculating shortest paths from node %d...\n", sourceNode);
    shortestPathCalculator(graph, sourceNode);
    return 0;
}
