#include<stdio.h>


void sendPackets(int start, int end, int flag){
    if(end ==start && flag==-1)
        return;
    for(int i=start; i<=end; i++){
        printf("Sent data packet %d\n", i);
    }
}

int main(){
    int frame_size, ack, start=1, end, times = 0, total_pkts=0, flag=0;
    printf("Enter total pkts to send: ");
	scanf("%d", &total_pkts);
	printf("Enter frame size: ");
    scanf("%d", &frame_size);
    end = frame_size;
    sendPackets(start, end, flag);
    printf("Enter last received acknowledgement - ");
    scanf("%d", &ack);
    while(ack < total_pkts){
        if(ack != start){
            sendPackets(start, end, flag);
        }
        else{
            start++;
            end++;
            if(end > total_pkts){
                end = 7;
                flag=-1;
            }
            sendPackets(end, end, flag);
        }
        times++;
        printf("Enter last received acknowledgement - ");
        scanf("%d", &ack);
    }
    return 0;
}
