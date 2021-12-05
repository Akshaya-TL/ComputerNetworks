// byte stuffing

#include<stdio.h>
#include<string.h>

int main(){
	char flag, esc;
	char data[100], stuffedData[200];
	printf("Enter flag character: ");
	scanf("%c", &flag);
	getchar();
	printf("Enter escape character: ");
	scanf("%c", &esc);
	getchar();

	printf("Enter data: ");
	scanf("%s", data);

	int i, j;
	stuffedData[0] = flag;
	for(i=0, j=1; i < strlen(data); i++, j++){
		if(data[i] == flag || data[i] == esc){
			stuffedData[j] = esc;
			j++;
		}
		stuffedData[j] = data[i];
	}
	stuffedData[j]=flag;

	printf("Byte Stuffed data: %s", stuffedData);

	return 0;

}
