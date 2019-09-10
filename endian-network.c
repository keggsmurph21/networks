#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

// deal with difference between host & network endianness

uint16_t http_port = 80; // host
uint16_t packet_port = ntohs(packet->port); // network

if (packet_port == http_port) {
    // ok
}

/*
 * htons() : host to network short
 * htonl() :                 long
 * ntohs() : network to host short
 * ntohl() :                 long
 */

