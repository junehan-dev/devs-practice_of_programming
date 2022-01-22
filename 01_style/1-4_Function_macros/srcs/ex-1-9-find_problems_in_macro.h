#define ISDIGIT(c) ((c >= '0') && (c <= '9')) ? 1 : 0

/*
 * expect there is only one as a problem in the book.
 * c is value, (means expression in big meaning)
 * if c is an expression and would like ISDIGIT((a = a + b)) or ISDIGIT(a++), there occurs multiple evaluation.
 * so c evaluated on later(c <= '9') can be a subtle bug, and also performace decreases because of multiple evaluation, though if evaluated value are still but the expression will processed 2 times uselessly.
 */
