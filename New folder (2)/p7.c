
#include <stdio.h>
#include <string.h>

int power(int b, int e, int n) {
    int r = 1;
    while (e--) r = (r * b) % n;
    return r;
}

int main() {
    char msg[100];
    int n = 253, e = 13, d = 17;
    int c[100], i, len;

    printf("Enter plain text: ");
    fgets(msg, sizeof(msg), stdin);
    len = strlen(msg);

    for (i = 0; i < len; i++) {
        c[i] = power((unsigned char)msg[i], e, n);
    }

    printf("Encrypted text: ");
    for (i = 0; i < len; i++)
        printf("%d ", c[i]);

    printf("\nDecrypted text: ");
    for (i = 0; i < len; i++)
        printf("%c", power(c[i], d, n));

    return 0;
}