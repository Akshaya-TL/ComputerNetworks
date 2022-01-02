// leaky bucket

#include<stdio.h>
#include<math.h>

int main(){
    int pkts = 0, bucketCapacity = 0, outputRate = 0, bucketSize = 0, pktSize = 0;
    
    printf("Enter bucket size: ");
    scanf("%d", &bucketCapacity);

    printf("Enter number of packets: ");
    scanf("%d", &pkts);

    printf("Enter output rate: ");
    scanf("%d", &outputRate);
	
    printf("Enter packet size: \n");
    for(int i=0; i < pkts; i++){
	printf("packet %d: ", i+1);
	scanf("%d", &pktSize);
    	if(pktSize + bucketSize <= outputRate){
		printf("sent packet with data of size = %d mbps\n", pktSize + bucketSize);
		bucketSize = 0;
	}
	else{
		bucketSize += pktSize;
		printf("sent packet with data of size = %d mbps\n", outputRate); 
		bucketSize -= outputRate;
	}
    }
    while(bucketSize >= outputRate){

	    printf("sent packet with data of size = %d mbps\n", outputRate);
	    bucketSize -= outputRate;
    }

    if(bucketSize > 0){
	    printf("sent packet with data of size = %d mbps\n", bucketSize);
	    bucketSize = 0;
    }

    return 0;
}
