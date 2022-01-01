#include <stdio.h>

int	main(void)
{
	int n = 1;
	printf("%d %d\n", n++, n++);
	/*
	 * print 1, 1 and n is 3.
	 * print 1, 2 and n is 3. (printf동작상 이게 맞지 않을까.?)
	 * print 2, 3 and n is 3.
	 *
	 * Answer
	 * print 2, 1 and n is 3.
	 */
}
