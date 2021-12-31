/* Improve this function
 * int     smaller(char *s, char *t) {
 *    if (strcmp(s, t) < 1)
 *        return (1);
 *    else 
 *        return (0);
 *}
 */

int     is_smaller(char *dest, char *src) {
    return (strcmp((const char *)dest, (const char *)src) < 0)
}

