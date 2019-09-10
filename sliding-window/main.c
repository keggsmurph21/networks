#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sender.h"
#include "receiver.h"
#include "network.h"

int main(int argc, char **argv)
{
    srand(time(0));

    Sender *s = make_sender(69);
    Receiver *r = make_receiver(420);
    Network *n = make_network(s, r);

    send_packets(n, 1000);

    tear_down(n);
}
