// print every node before deallocate them

    void printllhex(                // print liked list in hex; if you are specie of using binary then choose this one
    register void* a1               // the first node of linked list
) {
    register void* t1;
    goto test;
loop:
    printf(" 0x%lx", *(long*)a1);
    t1 = a1;                        // backup node address for deallocating
    a1 = *(long*)(a1 + OFFSET);     // jump to next node
    free(t1);                       // deallocate previous node
test:
    if(a1 != 0)goto loop;
    printf(" 0x4 0x2 0x1... loop\n");
}

    void printll(                   // print liked list in decimal; if you are specie of using decimal then choose this one
    register void* a1               // the first node of linked list
) {
    register void* t1;
    goto test;
loop:
    printf(" %ld", *(long*)a1);
    t1 = a1;                        // backup node address for deallocating
    a1 = *(long*)(a1 + OFFSET);     // jump to next node
    free(t1);                       // deallocate previous node
test:
    if(a1 != 0)goto loop;
    printf(" 4 2 1... loop\n");
}
