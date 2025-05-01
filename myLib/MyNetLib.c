#include <stdio.h> /*printf, scanf, sscanf*/
#include <stdlib.h> /*atoi, malloc, free*/
#include <string.h> /*strtok*/
#include <stdint.h> /*uint32_t*/

int ottetti[4];    // Store 4 octets of the IP address

void ipToBinary(char* ip){
    char* token;
    int i = 0;
    int bit = 0;
    int num = 0;

    token = strtok(ip, ".");    // Split the IP by '.'

    while(token != NULL && i < 4){
        ottetti[i] = atoi(token);    // Convert string to int
        token = strtok(NULL, ".");
        i++;
    }

    for(i = 0; i < 4; i++){
        num = ottetti[i];
        for(int k = 7 ; k >= 0; k--){
            bit = (num >> k) & 1;         // Print each bit from MSB to LSB
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
    return contatore;    // Should return 4 for a valid IP
}

void calculateNetworkAddress(char* ip, int cidr){

    unsigned int a, b, c, d;
    sscanf(ip, "%u.%u.%u.%u", &a, &b, &c, &d);    // Parse IP into 4 integers

     // Convert IP to 32-bit integer
    uint32_t binario = (a << 24) | (b << 16) | (c << 8) | d;

    // Apply network mask
    uint32_t network = binario & (0xFFFFFFFF << (32 - cidr));

    // Convert back to dotted format and print
    printf("Network address: %u.%u.%u.%u\n",
           (network >> 24) & 0xFF,
           (network >> 16) & 0xFF,        
           (network >> 8) & 0xFF,
           network & 0xFF);
}
