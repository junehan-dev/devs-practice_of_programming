int	origin(void)
{
	if (istty(stdin))	;
	else if (istty(stdout))	;
		else if (istty(stderr))	;
			else return(0);

	if (retval != SUCCESS) {
		return (retval);
	}
	/* All went well! */
	return SUCCESS;

	for (k = 0; k++ < 5; x += dx)
		scanf("%lf", &dx);
}

// Fixed by me

int stat_tty(void)
{
	int errno;

	if (istty(stdin) && istty(stdout) && istty(stderr)) {
		errno = do_next_check(stdin, stdout, stderr);
		return ((errno == SUCCESS) ? SUCCESS : errno);
	}

	return (0);
}

float floatnsum(int n)
{
	float	ret, add;

	if (n <= 0)
		return (0);

	ret = 0;
	while (n--) {
		scanf("%lf", &add);
		ret += add;
	}

	return (ret);
}

