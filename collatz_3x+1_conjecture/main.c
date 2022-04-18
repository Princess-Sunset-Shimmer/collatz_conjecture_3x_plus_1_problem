    #define SIZE 0x10
    #define OFFSET 0x8

    #include <stdio.h>
    #include <stdlib.h>
    #include "collatz.c"
    #include "printLinkedList.c"

    int main(
    void
) {
    printllhex(collatz(0x16));      // seed: 0x16
    return 0;
}
