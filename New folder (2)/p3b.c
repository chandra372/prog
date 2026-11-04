#include <stdio.h>
int main() {
    int n, w, i=1, j, ack, end;
    printf("Enter number of frames: ");
    scanf("%d", &n);
    printf("Enter window size: ");
    scanf("%d", &w);
    while(i<=n) {
        end = i+w-1;
        if(end>n) end=n;
        printf("\nSending frames: ");
        for(j=i; j<=end; j++)
            printf("%d ", j);
        printf("\nEnter last acknowledged frame: ");
        scanf("%d", &ack);
        if(ack<i-1 || ack>end) {
            printf("Invalid acknowledgement!\n");
            continue;
        }
        if(ack<i) {
            printf("Acknowledgement lost! Retransmitting...\n");
        }

        i=ack+1;
    }
    printf("\nAll frames transmitted successfully!\n");
    return 0;
}