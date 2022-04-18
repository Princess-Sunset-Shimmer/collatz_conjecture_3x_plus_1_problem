// this function takes a seed and compute all 3x+1 output untill hit 1 2 4 4 2 1 loop;
// return a pointer to the first result of all results; all results are saved in a long linked list;
// all results are saved to dynamic memory area; so you need to deallocate every node of them;

    void* collatz(
    register long a1                        // a1 is initial seed
) {
    register long t1;
    register void* t2;
    register void* t3;

    if(a1 == 0)goto done_0;
    t2 = malloc(SIZE);
    *(long*)(t2 + OFFSET) = malloc(SIZE);   // create a new node
    t3 = t2;                                // backup the first node for returning
    *(long*)t2 = a1;
    t2 = *(long*)(t2 + OFFSET);
    goto test;
loop:
    t1 = a1 & 0x1;                          // judgement even exclusive or odd
    if(t1 == 0)goto otherwise;
    t1 = a1 << 0x1;
    a1 = a1 + t1;                           // multiply three
    a1 = a1 + 0x1;                          // and plus one if it is odd
    *(long*)(t2 + OFFSET) = malloc(SIZE);   // add a new node
    *(long*)t2 = a1;
    t2 = *(long*)(t2 + OFFSET);             // after saving data jump to next node

    a1 = a1 >> 0x1;                         // subsequently divide by two
    *(long*)(t2 + OFFSET) = malloc(SIZE);
    *(long*)t2 = a1;
    t2 = *(long*)(t2 + OFFSET);
    goto test;
otherwise:
    a1 = a1 >> 0x1;                         // if it is even divide by two
    *(long*)(t2 + OFFSET) = malloc(SIZE);
    *(long*)t2 = a1;
    t2 = *(long*)(t2 + OFFSET);
test:
    t1 = (long unsigned)a1 < 0x2;           // judgement seed to be one
    if(t1 == 0)goto loop;                   // seed one will lead it to be one two four tow one loop
    t1 = 0x2;
    *(long*)t2 = t1;
    *(long*)(t2 + OFFSET) = 0;
    return t3;
done_0:
    printf("error: seed cannot be zero\n");
    return 0;
}
