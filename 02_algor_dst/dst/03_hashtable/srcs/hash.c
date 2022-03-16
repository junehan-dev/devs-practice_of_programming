#define MULTIPLIER	37
/* 31, 37 for ascii */
#define NHASH		497
/* arraySize for Hash values */

unsigned int	hash(char *str)
{
	unsigned int	h;
	unsigned char	*p;

	h = 0;
	p = (unsigned char *)str;
	while (*p) {
		h = MULTIPLIER * h + *p;
		p++;
	}
	return  h % NHASH
}
