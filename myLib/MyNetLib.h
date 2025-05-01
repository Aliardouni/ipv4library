#ifndef MYNETLIB_H_INCLUDED
#define MYNETLIB_H_INCLUDED

/*function that converts ip to binary using an array to hold the 4 octets*/
void ipToBinary(char* ip);

/*function that checks if all 4 octets of the IP are valid (higher or equal to 0 or lower or equal to 255)*/
int isValidIPv4(char* ip);

/*function that gets the network address by passing it the IP and CIDR*/
void calculateNetworkAddress(char* ip, int cidr);

#endif // MYNETLIB_H_INCLUDED
