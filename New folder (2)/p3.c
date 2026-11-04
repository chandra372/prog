
#include <stdio.h>

int main() {
    int n, w, i, j;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter window size: ");
    scanf("%d", &w);

    for(i=1; i<=n; i+=w) {
        printf("\nSending frames: ");
        for(j=i; j<i+w && j<=n; j++)
            printf("%d ", j);

        printf("\nAcknowledgement received\n");
    }

    printf("\nAll frames transmitted successfully!\n");
    return 0;
}