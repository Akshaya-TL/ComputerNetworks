#include<stdio.h>
#include<string.h>

void xor(char* msg, char* genFunc, int start, int len){
     if(msg[start]=='0')
         return;
     else{
         int i=0;
         while(i < len){
             if(msg[start] == genFunc[i])
                 msg[start] = '0';
             else
                 msg[start] = '1';
             i++;
             start++;
         }
     }
     return;
 }

void mod2div(char* message, char* generator, int mLen, int gLen){
     int i=0;
     while(i <= mLen-gLen){
         xor(message, generator, i, gLen);
         i++;
     }
     return;
 }

int main(){
  char message[100];
  char modifiedMsg[100];
  char generator[50];
  char polynomial[100];
  int msgLen, genLen, i, j, newMsgLen;


  printf("Enter data: ");
  fgets( message, sizeof(message), stdin);
  printf("message entered: " );
  puts(message);

  printf("Enter polynomial: ");
  fgets(polynomial, sizeof(polynomial), stdin);
  i=0, j=0;
  int prev=-1, current=0;
  while(i < strlen(polynomial)-1){
     if(polynomial[i] != 'x' && polynomial[i] != '+'){
       current=polynomial[i]-'0';
       printf("%d ", current);
       if(prev==-1)
         generator[j++] = '1';
       else{
         int n = prev - current - 1;
         while(n--){
             generator[j++] = '0';
         }
         generator[j++] = '1';
       }
       prev = current;
     }
     i++;
 }

 if(current > 0){
    while(current--){
        generator[j++] = '0';
    }
 }
 generator[j]='\0';

  //printf("Enter generator function: ");
  //fgets(generator, sizeof(generator), stdin);
  //printf("generator function entered: ");
  printf("generator : ");
  puts(generator);

  strcpy(modifiedMsg, message);
  printf("modified msg: ");
  puts(modifiedMsg);

  msgLen = strlen(message)-1;
  genLen = strlen(generator);
  newMsgLen=msgLen;

  for(i=0; i<genLen-1; i++){
    modifiedMsg[newMsgLen++] = '0';
  }
  modifiedMsg[newMsgLen] = '\0';
  printf("msgLen = %d, genLen = %d, newMsgLen = %d, modifiedMsg = %s\n", msgLen, genLen, newMsgLen, modifiedMsg);

  mod2div(modifiedMsg, generator, newMsgLen, genLen);
  printf("msg = %s\n", modifiedMsg);

  for(i=msgLen, j=msgLen; j < newMsgLen; i++, j++){
     message[i] = modifiedMsg[j];
  }
  message[i]='\0';
  printf("Modified data:  %s\n", message);
  mod2div(message, generator, newMsgLen, genLen);
  printf("Receiver side remainder: %s\n", message);
  return 0;
 }
