#include <stdlib.h>
#include "receiver.h"

int RECEIVE_WINDOW_SIZE = 2;

Receiver *make_receiver(int id)
{
    Receiver *r = (Receiver*) malloc(sizeof(Receiver));
    r->id = id;
    r->last_seqn = 0;
    r->next_ack = 0;
    for (int i=0; i<2; i++)
        r->window[i] = false;

    return r;
}
