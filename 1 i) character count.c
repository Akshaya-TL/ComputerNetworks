// Framing Techniques
// i) character count 

#include<stdio.h>

int main(){
	int data[100];
	int size, totalSize = 0, frames = 0;
	static int i;
	
	printf("Enter size of data to be transferred(0 to end): \n");
	scanf("%d", &size);
	totalSize += size+1;   // +1 for char count bit
	i=0;
	
	// taking input frames of data
	while(size != 0){
		data[i] = size+1;
		i+=1;
		
		for(i=i; i < totalSize; i++){
			printf("Enter data: ");
			scanf("%d", &data[i]);
		}
		
		printf("Enter size of data to be transferred(0 to end): \n");
		scanf("%d", &size);
		totalSize += size+1;
    }
    data[i] = 0;  // last frame was empty, so insert 0
    printf("\n");
    
    // displaying stuffed data
    i=0;
    int n = data[0];
    printf("Stuffed data:\n");
    while(n != 0){
    	int j;
    	for(j=0; j<n; j++, i++)
			printf("%d", data[i]);
		n = data[i];
	}
	printf("\n\n");
    
    printf("Destuffed data: \n");
    // displaying transferred data
	size = data[0];
	static int j = 0;
	frames = 1;
    while(size != 0){
    	printf("Frame %d:\n", frames);
    	j += 1;
    	int start = j;
    	for(j=j; j<start+size-1; j++){
    		printf("%d ", data[j]);
		}
		printf("\n");
		size = data[j];
		frames += 1;
	}
	return 0;
}



