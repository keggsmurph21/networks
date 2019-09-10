#ifndef SENDER_H
#define SENDER_H

#include <stdbool.h>

int SENDER_TIMEOUT;

typedef struct Sender {
    int id;
    int next_seqn;
    int last_ack;
    bool window[3];
} Sender;

#include "network.h"
#include "receiver.h"

Sender *make_sender(int id);

#endif
