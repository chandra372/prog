
#include <stdio.h>

int main() {
    int bucket, rate, n, size, stored = 0;

    printf("Enter bucket size: ");
    scanf("%d", &bucket);

    printf("Enter output rate: ");
    scanf("%d", &rate);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter packet size %d: ", i);
        scanf("%d", &size);

        if (stored + size > bucket)
            printf("Packet %d discarded\n", i);
        else {
            stored += size;
            printf("Packet %d added\n", i);
        }

        int sent = (stored < rate) ? stored : rate;
        printf("Transmitted: %d bytes\n", sent);

        stored -= sent;
        printf("Remaining: %d bytes\n", stored);
    }

    while (stored > 0) {
        int sent = (stored < rate) ? stored : rate;
        printf("Transmitted: %d bytes\n", sent);
        stored -= sent;
    }

    printf("All packets processed successfully!\n");
    return 0;
}