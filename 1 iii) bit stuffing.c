// Framing techniques
// 3>Bit  stuffing

#include<stdio.h>
#include<string.h>

int main(){
	char data[100], stuffedData[200];
	int n, count = 0, i, j, firstZero=0;
	
	printf("Enter size of data in bits: ");
	scanf("%d", &n);
	
	// data to send
	printf("Enter binary data of size %d to send: \n", n);
	scanf("%s", data);
	
	i=0, j=0;
	// framing the data to send
	while(i<strlen(data)){
		stuffedData[j] = data[i];
		if(data[i] == '0')
			count = 0;
		
		if(data[i] == '1')
		    count++;
		
		if(count == 5){
		    stuffedData[j+=1] = '0';
		    count = 0;
		}
		i+=1;
		j+=1;
	}
	
	if(count == 5){
		    stuffedData[j+1] = '0';
		    count = 0;
		    j+=1;
	}
	
	
	printf("stuffed data = %s\n", stuffedData);
	
	
	// displaying destuffed data - decoding stuffed data
	printf("Destuffed data: ");
	count = 0;
	for(i=0; i < strlen(stuffedData); i++){
		if(stuffedData[i] == '0' && count == 5){
			//ignore
			count = 0;
		}
		else if(stuffedData[i] == '0'){
			printf("0");
			count = 0;
		}
		else{
			printf("%c", stuffedData[i]);
			count++;
		}
	}
	return 0;
}
