typedef struct Nameval Nameval;
struct Nameval {
    char    *name;
    int     val;
};

Nameval htmlchars[] = {
    "AElig",    0x00c6,
    "Aacute",   0x00c1,
    "Acirc",    0x00c2,
    /* ... */
    "zeta",     0x03b6,
};
