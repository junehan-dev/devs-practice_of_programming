/* Rewrite these C/C++ excerpts more clearly:
 * if (istty(stdin))    ;
 * else if (istty(stdout))  ;
 *      else if (istty(stderr)) ;
 *          else return(0);
 *
 * if (retval != SUCCESS)
 *
 *     return (retval);
 * }
 * return SUCCESS;
 *
 * for (k = 0; k++ < 5; x += dx)
 *     scanf("%ls", &dx);
 */

int ex07(void) {
    if (istty(stdin)) {
        ;
    } else if (istty(stdout)) {
        ;
    } else if (istty(stderr)) {
        ;
    } else {
        return (0);
    }

    if (retval != SUCCESS)
        return (retval);
    return (SUCCESS);

    for (k = 0; k < 5; k++) {
        scanf("%lf", &dx);
        x += dx;
    }
}
