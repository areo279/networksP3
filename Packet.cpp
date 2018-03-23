/* Author: Are Oelsner
 * Networks Project 3
 * Packet class for constructing and parsing packets
 */

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
using namespace std;

struct Packet {
  // Packet Components
  unsigned char version;    // Version field (4 bits) set to 0110 or 0x6
  unsigned char type;       // Type field (3 bits) Query: 000, Resp: 100
  unsigned char X;          // X (1 bit) 0 for Q, 0 for neg response, 1 for good response
  unsigned char length;     // Length field (8 bit) unsigned char represents # data items
  unsigned short queryID;    // Query-ID randomly genned 16 bit num client
  unsigned short checksum;   // Checksum(16 bit) ones complement checksum of entire packet
  char data[2048];        // Query data stores null terminated hostname string
};

///Functions

//void
//Packet::
//genQueryID() {
//}
//
//int 
//Packet::
//computeChecksum() {
//}
//
//int
//Packet::
//checkChecksum() {
//}
//
//void
//Packet::
//setData(char* hostname) {
//  q_data = hostname;
//  length = (char*)"00000001";
//}

void
setData(struct Packet *p, char** data, int numEntries) {
  char* name;
  char* time;
  int size;
  for(int i = 0; i < numEntries; i++) {
    name = strtok(data[i], ":");
    time = strtok(NULL, ":");
    size = strlen(name);
    strcat(p->data, name);
    for(int j = size; j < 8; j++)
      strcat(p->data, (char*)' ');
    strcat(p->data, time);
  }
}

void
printPacket(const struct Packet *p) {
  printf("\nv\tt\tX\tlength\tqueryID\n");
  printf("%u\t%u\t%u\t%u\t%u\n", p->version, p->type, p->X, p->length, p->queryID);
  printf("checksum\tData \n");
  printf("%u\t%s\n", p->checksum, p->data);
}

