#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sender.h"
#include "receiver.h"
#include "network.h"

float THRESHOLD = 0.9; // 90% chance packets get thru

Packet *make_packet(int src_id, int tar_id, char **msg)
{
    Packet *p = (Packet*) malloc(sizeof(Packet));
    p->src_id = src_id;
    p->tar_id = tar_id;
    p->window = 0;
    p->seqn = 0;
    p->ack = 0;
    p->msg = msg;
    
    return p;
}

Network *make_network(Sender *s, Receiver *r)
{
    Network *n = (Network *) malloc(sizeof(Network));
    n->s = s;
    n->r = r;
}

void tear_down(Network *n)
{
    free(n->s);
    free(n->r);
    free(n);
}

Packet *maybe_drop(Packet *p)
{
    float rand_num = (double) rand() / (double) RAND_MAX;
    if (rand_num < THRESHOLD) {
        return p;
    } else {
        free(p);
        return NULL;
    }
}

void send_msg(Network *n, char **msg)
{
    printf("send: %s\n", *msg);
    Packet *p = make_packet(n->s->id, n->r->id, msg);
    p = maybe_drop(p);
    if (p) {
        process_packet(n->
        free(p);
    }
}

void receive_msg_packet(Network *n, char **msg)
{
    printf("receive: %s\n", *msg);


int send_packets(Network *n, int num)
{
    for (int i=0; i<num; i++) {
        int num_len = snprintf(NULL, 0, "%d", i);
        char *msg = (char *) malloc((num_len + 10) * sizeof(char));
        sprintf(msg, "message #%d", i);
        send_msg(n, &msg);
        free(msg);
    }
    return 0;
    //char *msg = strcat(
    //char *msg = "[message #%i\n";
    //send_msg(n, &msg);    
}
