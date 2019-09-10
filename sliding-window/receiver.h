#ifndef RECEIVER_H
#define RECEIVER_H

typedef struct Receiver {
    int id;
    int last_seqn;
    int next_ack;
    int window[2];
} Receiver;

#include "network.h"
#include "sender.h"

Receiver *make_receiver(int id);

#endif
