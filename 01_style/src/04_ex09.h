/* Identify the problems with this macro.
 * #define ISDIGIT(c)  ((c >= '0') && (c <= '9')) ? 1 : 0
 */

#define IS_DIGIT(c) (((c >= '0') && (c <= '9')) ? 1 : 0)

