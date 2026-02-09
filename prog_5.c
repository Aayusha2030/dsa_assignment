/* Undirected graph using adjacency matrix with BFS and DFS */
#include <stdio.h>
#define SIZE 10
int adjMat[SIZE][SIZE];   // adjacency matrix
int seen[SIZE];           // visited nodes
int nodes;
/*  BFS Traversal */
void doBFS(int startNode)
{
    int line[SIZE];
    int head = 0, tail = 0;

    // visited array clear garnu
    for(int i = 0; i < nodes; i++)
        seen[i] = 0;
    line[tail++] = startNode;
    seen[startNode] = 1;
    printf("BFS Order: ");
    while(head < tail)
    {
        int temp = line[head++];
        printf("%d ", temp);
        for(int j = 0; j < nodes; j++)
        {
            // edge xa ra visit bhayeko chaina
            if(adjMat[temp][j] == 1 && seen[j] == 0)
            {
                line[tail++] = j;
                seen[j] = 1;
            }
        }
    }
    printf("\n");
}
/* DFS Traversal */
void doDFS(int now)
{
    printf("%d ", now);
    seen[now] = 1;
    for(int k = 0; k < nodes; k++)
    {
        // connected xa ra already visit bhayeko chaina
        if(adjMat[now][k] == 1 && seen[k] == 0)
        {
            doDFS(k);   // recursive call
        }
    }
}

/* Main Function */
int main()
{
    int links;
    int a, b;
    int start;
    printf("Enter total vertices: ");
    scanf("%d", &nodes);
    // matrix zero initialize 
    for(int i = 0; i < nodes; i++)
        for(int j = 0; j < nodes; j++)
            adjMat[i][j] = 0;
    printf("Enter total edges: ");
    scanf("%d", &links);
    printf("Enter edges (u v):\n");
    for(int i = 0; i < links; i++)
    {
        scanf("%d %d", &a, &b);
        // undirected graph, so both side 1
        adjMat[a][b] = 1;
        adjMat[b][a] = 1;
    }
    printf("Enter starting node: ");
    scanf("%d", &start);
    doBFS(start);
    // DFS ko lagi visited reset
    for(int i = 0; i < nodes; i++)
        seen[i] = 0;
    printf("DFS Order: ");
    doDFS(start);
    printf("\n");
    return 0;
}

