#include <stdio.h>
#include <string.h>

struct Frame {
    int seq;
    char data[20];
};

int main() {
    struct Frame f[100], temp;
    int n, i, j;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter sequence number and data: ");
        scanf("%d %19s", &f[i].seq, f[i].data);
    }

    // Sort frames using Bubble Sort
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(f[j].seq > f[j+1].seq) {
                temp = f[j];
                f[j] = f[j+1];
                f[j+1] = temp;
            }

    printf("\nSorted Frames:\n");
    for(i = 0; i < n; i++)
        printf("%d\t%s\n", f[i].seq, f[i].data);

    printf("\nReconstructed Message: ");
    for(i = 0; i < n; i++)
        printf("%s", f[i].data);

    printf("\n");
    return 0;
}