
#include <stdio.h>
#include <string.h>

int main() {
    char data[100], gen[20], code[120], temp[120];
    int i, j, n, m;

    printf("Enter data: ");
    scanf("%99s", data);

    printf("Enter generator: ");
    scanf("%19s", gen);

    n = strlen(data);
    m = strlen(gen);

    strcpy(code, data);
    for(i=0; i<m-1; i++)
        code[n+i] = '0';
    code[n+m-1] = '\0';

    strcpy(temp, code);

    // CRC generation
    for(i=0; i<n; i++)
        if(temp[i]=='1')
            for(j=0; j<m; j++)
                temp[i+j] = (temp[i+j]==gen[j]) ? '0' : '1';

    for(i=0; i<m-1; i++)
        code[n+i] = temp[n+i];

    printf("\nTransmitted Codeword: %s\n", code);

    // CRC checking
    printf("\nEnter received codeword: ");
    scanf("%119s", temp);

    n = strlen(temp);

    for(i=0; i<=n-m; i++)
        if(temp[i]=='1')
            for(j=0; j<m; j++)
                temp[i+j] = (temp[i+j]==gen[j]) ? '0' : '1';

    printf("Remainder: ");
    for(i=n-m+1; i<n; i++)
        printf("%c", temp[i]);

    for(i=n-m+1; i<n; i++)
        if(temp[i]=='1')
            break;

    if(i==n)
        printf("\nCodeword Accepted (No errors)\n");
    else
        printf("\nCodeword Rejected (Error detected)\n");

    return 0;
}