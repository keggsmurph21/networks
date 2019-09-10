#ifndef NETWORK_H
#define NETWORK_H

typedef struct Packet {
    int src_id; // kinda like IP address :)
    int tar_id;
    int window;
    int seqn;
    int ack;
    char **msg;
} Packet;

#include "sender.h"
#include "receiver.h"

typedef struct Network {
    Sender *s;
    Receiver *r;
} Network;

//float THRESHOLD;

//Packet *make_packet(int src_id, int tar_id, char **msg);

Network *make_network(Sender *s, Receiver *r);
void tear_down(Network *n);

//void send_msg(Network *n, char **msg);
//void send_ack(Network *n);

int send_packets(Network *n, int num);

#endif
