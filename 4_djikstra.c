#include <stdio.h>
#include <math.h>
#include <limits.h>
/*
requirements
int graph[v][v]
int dist[v]
bool visited[v]
 Algo
----
 1> find node with shortest path whichever is not visited to detect source node
 2> functon to update distances for every unvisited source node to remaining
    destns and mark the current src as visited
 3> print all nodes with distances
 */

void printDistances(int v, int dist[v], int src)
{
    printf("source  destination  time-taken\n");
    for (int i = 0; i < v; i++)
    {
        printf(" %d         %d          %d      \n", src, i, dist[i]);
    }
    return;
}

void djikstra(int v, int graph[v][v], int src1)
{
    int dist[v], count = 0;
    int visited[v];

    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src1] = 0;
    int src = src1;
    while (count < v)
    {   
        visited[src] = 1;
        count++;
        int newSrc = 0;
        for (int i = 0; i < v; i++)
        {
            if (graph[src][i] && visited[i] == 0 && dist[src] != INT_MAX && graph[src][i] + dist[src] < dist[i])
            {
                dist[i] = graph[src][i] + dist[src];
                newSrc = i;
            }
        }
        src = newSrc;
    }

    printDistances(v, dist, src1);
}

int main()
{
    int v, src = 0;
    printf("Enter the number of nodes in network: ");
    scanf("%d", &v);

    int graph[v][v];
    printf("Enter the time taken to transfer data packets from src to destn:  \n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source node: ");
    scanf("%d", &src);
    djikstra(v, graph, src);

    return 0;
}

