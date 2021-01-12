#include <string.h>
#include <stdio.h>

typedef struct Nameval {
    char    *name;
    int     val;
} Nameval;

/* lookup: binary search for name in tabs: return index */
int lookup(char *name, Nameval tab[], int ntab)
{
    int low, high, mid, cmp;

    low = 0;
    high = ntab - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        cmp = strcmp(name, tab[mid].name);

        if (cmp < 0)
            high = mid - 1; 
        else if (cmp > 0)
            low = mid + 1;
        else
            return (mid);
    }

    return (-1);
}

int main()
{
    char        *name;
    int         ntab;
    int         ret;

    Nameval     htmlchars[] = {
        {"AElig",    0x00c6},
        {"Aacute",   0x00c1},
        {"Acirc",    0x00c2},
        {"zeta",     0x03b6},
    };
    name = "zeta";
    ntab = (sizeof(htmlchars) / sizeof(Nameval));
    ret = lookup(name, htmlchars, ntab);

    printf("sizeof tabarr:%ld, sizeof tab:%ld\nntab: %d\n",\
        sizeof(htmlchars), sizeof(Nameval), ntab);
    printf("found at: %d!\n", ret);
    return (0);
}

