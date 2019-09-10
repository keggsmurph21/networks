#include <stdint.h>
#include <stdio.h>

void main(int argc, char** argv) {

    uint16_t val = 0x400;
    uint8_t* ptr = (uint8_t*)&val;

    /*
    printf("%x,%x\n", ptr[0], ptr[1]);
    printf("%s %s %s\n",
            ptr[0] == 0x40 ? "y" : "n",
            ptr[1] == 0x40 ? "y" : "n",
            ptr[1] == 0x04 ? "y" : "n");
    */

    if (ptr[0] == 0x40) {
        printf("big endian\n");
    } else if (ptr[1] == 0x04) {
        printf("little endian\n");
    } else {
        printf("unknown endianness!\n");
    }

}
