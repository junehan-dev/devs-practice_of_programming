// Commnet on the choice of name and values in code.
#define TRUE    0
#define FALSE   1

int isEOF(char ch){
    int     not-eof; // - sign is no good to use

    if ((ch == getchar()) == EOF)
        not-eof == FALSE;
/* name not-eof isn't appropriate
 * because it's function name already points it.
 * if no function name. than is_eof kind of thing will be better.
 */

    return (not-eof);
}
