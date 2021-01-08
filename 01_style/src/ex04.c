/* Improve each of these fragments:
 * if( !(c == 'y' || c == 'Y') )
 *     return;
 * 
 * length = (length < BUFSIZE) ? length : BUFSIZE;
 *
 * flag = flag ? 0 : 1;
 * quote = (*line == '"') ? 1 : 0;
 *
 * if (val & 1)
 *     bit = 1;
 * else
 *     bit = 0;
 */

int ex04(char c, char *line, int val) {
    int     length;
    int     quote;
    int     bit;

    length = 32;
    quote = 0;
    bit = 0;

    if (c != 'y' || c != 'Y')
        return;

    length = (length < BUFSIZE) ? length : BUFSIZE;
    flag = !flag;

    if (*line == '"')
        quote += 1;

    if (val & 1)
        bit += 1;

    return (0);
}
