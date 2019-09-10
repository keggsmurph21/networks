#include <stdbool.h>
#include <stdlib.h>
#include "sender.h"

const int SENDER_WINDOW_SIZE = 3;

Sender *make_sender(int id)
{
    Sender *s = (Sender*) malloc(sizeof(Sender));
    s->id = id;
    s->next_seqn = 0;
    s->last_ack = 0;
    for (int i=0; i<3; i++)
        s->window[i] = false;
    
    return s;
}

