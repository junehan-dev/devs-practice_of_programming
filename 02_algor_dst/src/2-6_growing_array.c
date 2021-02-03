#include <stdlib.h>
#include <unistd.h>

typedef struct Nameval {
    char    *name;
    int     value;
} Nameval;

struct NVtab {
    int     nval;
    int     max;
    Nameval nameval;
} nvtab;

enum { NVINIT = 1, NVGROW = 2 };

int     addname(Nameval newname)
{
    Nameval     nvp;
    size_t      grow_siz;
if (nvtab.nameval == NULL) { /* first time generated! */
        nvtab.nameval = (Nameval *)(malloc(NVINIT * sizeof(Nameval)));

        if (nvtab.nameval == NULL)
            return (-1);

        nvtab.max = NVINIT;
        nvtab.nval = 0;
    } else if (nvtab.nval >= nvtab.max){ /* Grow!~ */
        grow_siz = (size_t)(NVGROW * nvtab.max);
        nvp = (Nameval *)(realloc(nvtab.nameval, grow_siz * sizeof(Nameval)));

        if (!nvp)
            return (-1);

        nvtab.max *= NVGROW;
        nvtab.nameval = nvp;
    }

    nvtab.nameval[nvtab.nval] = newname;
    nvtab.nval += 1;

    return (nvtab.nval);
}
