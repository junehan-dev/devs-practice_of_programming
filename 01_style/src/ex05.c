// What is wrong with this excerpt?

int read(int *ip) {     // better to no-arg value return.
    scanf("%d", ip);
    return (*ip);       // returning value but change with pointer.
}

insert(&graph[vert], read(&val), read(&ch));

