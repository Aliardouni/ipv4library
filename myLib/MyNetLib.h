#ifndef MYNETLIB_H_INCLUDED
#define MYNETLIB_H_INCLUDED

void ipToBinary(char* ip);
int isValidIPv4(char* ip);
void calculateNetworkAddress(char* ip, int cidr);

#endif // MYNETLIB_H_INCLUDED
