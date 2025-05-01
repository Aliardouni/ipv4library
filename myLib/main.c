#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "MyNetLib.h"

int main() {
    char* ip = malloc(16);
    int valido = 0;
    int CIDR = 0;

    if (ip == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return 1;
    }

    printf("Inserisci un IP: ");
    scanf("%15s", ip);

    ipToBinary(ip);
    valido = isValidIPv4(ip);

    printf("\n");

    if(valido == 4){
        printf("l'ip inserito e valido");
    }else{
        printf("l'ip inserito non e valido");
    }

    printf("inserisci un CIDR");
    scanf("%d", &CIDR);

    calculateNetworkAddress(ip, CIDR);

    free(ip);

    return 0;
}

