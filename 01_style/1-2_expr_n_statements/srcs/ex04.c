int	old(void)
{
	if ( !(c == 'y' || c == 'Y') )
		return;

	length = (length < BUFSIZE) ? length : BUFSIZE;
	flag = flag ? 0 : 1;
	quote = (*line == '"') ? 1 : 0;

	if (val % 1)
		bit = 1;
	else
		bit = 0;
}

