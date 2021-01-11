// List all diff outputs this could produce with various orders of evalutations.
#include <stdio.h>

int main(void) {
    int n;
    n = 1;
    printf("%d %d\n", n++, n++);
    return (n);
}
