// frame sorting

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FRAME_TXT_SIZE 5
#define MAX_NOF_FRAMES 100

char str[MAX_NOF_FRAMES * FRAME_TXT_SIZE];

struct frame{
	char text[FRAME_TXT_SIZE];
	int seq;
}fr[MAX_NOF_FRAMES], shuffArray[MAX_NOF_FRAMES];

int assignSeqNumber(){
	int k=0;
	for(int i=0; i<strlen(str); i++){
		for(int j=0; j<FRAME_TXT_SIZE-1 && str[i] != '\0'; j++){
			fr[k].text[j] = str[i++];
		}
		fr[k].seq = k;
		k++;
		i--;
	}
	for(int s = 0; s < k; s++){
		printf("frame %d data: %s\n", s, fr[s].text);
	}
	return k;
}

void generateRandomSeq(int* shuffle, int limit){
	int i=0;
	while(i<limit){
		int r = rand()%limit, k;
		for(k = 0; k < i; k++){
			if(shuffle[k] == r)
				break;
		}
		if(k==i){
			shuffle[i] = r;
			i++;
		}
	}
	return;
}

void shuffleFrames(int noOfFrames){
	int shuffle[noOfFrames];
	generateRandomSeq(shuffle, noOfFrames);
	for(int i=0; i<noOfFrames; i++){
		shuffArray[i] = fr[shuffle[i]];
	}
	printf("After shuffling frames: \n");
	for(int i=0; i<noOfFrames; i++){
		printf("frame %d data = %s\n", shuffArray[i].seq, shuffArray[i].text);
	}
	return;
}

void sortFrames(int noOfFrames){
	//cycle sort
	struct frame temp;
	int i=0;
	while(i<noOfFrames){
		if(shuffArray[i].seq != i){
			temp = shuffArray[i];
			shuffArray[i] = shuffArray[shuffArray[i].seq];
			shuffArray[temp.seq] = temp;
		}
		else
		    	i++;
	}
	return;
}

int main(){
	printf("Enter the string to transfer: ");
	gets(str);
	int noOfFrames = assignSeqNumber();
	shuffleFrames(noOfFrames);
	sortFrames(noOfFrames);
	printf("After sorting: \n");
        for(int i=0; i<noOfFrames; i++){
		printf("frame %d data = %s\n", shuffArray[i].seq, shuffArray[i].text);
	}
	return 0;
}





