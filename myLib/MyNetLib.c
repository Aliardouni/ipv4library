#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int ottetti[4];

void ipToBinary(char* ip){
    char* token;
    int i = 0;
    int bit = 0;
    int num = 0;

    token = strtok(ip, ".");

    while(token != NULL && i < 4){
        ottetti[i] = atoi(token);
        token = strtok(NULL, ".");
        i++;
    }

    for(i = 0; i < 4; i++){
        num = ottetti[i];
        for(int k = 7 ; k >= 0; k--){
            bit = (num >> k) & 1;
            printf("%d", bit);
        }
        printf(" ");
    }
}

int isValidIPv4(char* ip){
    int numero = 0;
    int contatore = 0;
    int i = 0;
    char* token;

    token = strtok(ip, ".");
    while(token != NULL && i < 4){
        ottetti[i] = atoi(token);
        token = strtok(NULL, ".");
        i++;
    }

    for(int i = 0; i <4; i++){
        if(ottetti[i] <= 255 && ottetti[i] >= 0){
            contatore++;
        }
    }
    return contatore;
}

void calculateNetworkAddress(char* ip, int cidr){

    unsigned int a, b, c, d;
    sscanf(ip, "%u.%u.%u.%u", &a, &b, &c, &d);

    uint32_t binario = (a << 24) | (b << 16) | (c << 8) | d;

    uint32_t network = binario & (0xFFFFFFFF << (32 - cidr));

    printf("Network address: %u.%u.%u.%u\n",
           (network >> 24) & 0xFF,
           (network >> 16) & 0xFF,
           (network >> 8) & 0xFF,
           network & 0xFF);
}
