
#include <stdio.h>
#include <string.h>

int main() {
    char data[100], stuffed[300];
    int i, j, count;

    // Character Count
    printf("\nCharacter Count Method\n");
    printf("Enter data: ");
    scanf("%99s", data);
    printf("Frame: %d%s\n", (int)strlen(data)+1, data);

    // Character Stuffing
    printf("\nCharacter Stuffing\n");
    printf("Enter data: ");
    scanf("%99s", data);

    strcpy(stuffed, "DLESTX");
    j = strlen(stuffed);

    for(i=0; data[i]; i++) {
        if(strncmp(data+i, "DLE", 3)==0)
            strcpy(stuffed+j, "DLE");
        else
            stuffed[j] = data[i], stuffed[j+1] = '\0';
        if(strncmp(data+i, "DLE", 3)==0)
            j += 3;
        else
            j++;
    }

    strcpy(stuffed+j, "DLEETX");
    printf("Frame: %s\n", stuffed);

    // Bit Stuffing
    printf("\nBit Stuffing\n");
    printf("Enter binary data: ");
    scanf("%99s", data);

    j = 0;
    count = 0;

    for(i=0; data[i]; i++) {
        stuffed[j++] = data[i];

        if(data[i]=='1')
            count++;
        else
            count = 0;

        if(count==5) {
            stuffed[j++] = '0';
            count = 0;
        }
    }

    stuffed[j] = '\0';
    printf("Stuffed data: 01111110%s01111110\n", stuffed);

    return 0;
}