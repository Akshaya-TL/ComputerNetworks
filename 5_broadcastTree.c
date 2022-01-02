// minimum spanning tree using prims algorithm
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

int V = 5;

int minKey(int* key, bool included[V]){
	int node, minWeight = INT_MAX;
	for(int i = 0; i<V; i++){
		if(included[i] == false && key[i] < minWeight){
			node = i;
			minWeight = key[i];
		}
	}
	return node;
}

void minSpanningTree(int *parent, int graph[V][V]){
	bool included[V];
	int key[V];
	for(int i=0; i<V; i++){
		key[i] = INT_MAX;
	}
	key[0] = 0;

	for(int count = 0; count < V-2; count++){
		int u = minKey(key, included);

		for(int i=0; i<V; i++){
			if(graph[u][i] && included[i]==false && key[i] > graph[u][i]){
				parent[i] = u;
				key[i] = graph[u][i];
			}
		}
		included[u] = true;
	}
	return;
}

void printMST(int parent[V], int graph[V][V]){
	printf("src - destn  cost\n");
	for(int i=1; i<V; i++){
		printf("%d  -  %d   %d\n", parent[i], i, graph[i][parent[i]]);
	}
}	

int main(){
	printf("Enter number of vertices : ");
	scanf("%d", &V);

	int graph[V][V];
	int parent[V];
	parent[0] = -1;
        printf("Enter cost between src and destn nodes: \n");

	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			scanf("%d", &graph[i][j]);
		}
	}

	minSpanningTree(parent, graph);
	printMST(parent, graph);

	return 0;
}
