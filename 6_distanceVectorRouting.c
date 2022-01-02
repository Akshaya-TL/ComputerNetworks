// distance vector routing 

#include<stdio.h>

struct node{
	int dist[10];
	int line[10];
}rt[10];

int main(){

	int routers;
	printf("Enter number of routers (< 10): ");
	scanf("%d", &routers);

	int distMatrix[routers][routers];
	printf("Enter distance of each router to other roters: \n");
	for(int i = 0; i < routers; i++){
	    printf("Router %d: \n", i+1);
            for(int j = 0; j < routers; j++){
	    	scanf("%d", &distMatrix[i][j]);
		rt[i].dist[j] = distMatrix[i][j];
		rt[i].line[j] = j;
	    }	
		distMatrix[i][i] = 0;
	}

	// routing table calculation
	int count= 0;
	do{
	    count = 0;
	    for(int i=0; i<routers; i++){
		    for(int j=0; j<routers; j++){
			    for(int k=0; k<routers; k++){
				    if(rt[i].dist[j] > rt[i].dist[k] + rt[k].dist[j]){
					    rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
					    rt[i].line[j] = k;
					    count++;
				    }
			    }
		    }
	    }
	}while(count != 0);

	for(int i=0; i<routers; i++){
		printf("Router %d: \n", i+1);
		for(int j=0; j<routers; j++){
			printf("router %d via %d Distance = %d\n", j+1, rt[i].line[j], rt[i].dist[j]);
		}
	}
	return 0;
}


