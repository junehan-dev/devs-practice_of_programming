int	old(void)
{
	if ( !(c == 'y' || c == 'Y') )
		return;

	length = (length < BUFSIZE) ? length : BUFSIZE;
	flag = flag ? 0 : 1;
	quote = (*line == '"') ? 1 : 0;

	if (val & 1)
		bit = 1;
	else
		bit = 0;
}

int	improved(void)
{
	if (c != 'y' && c != 'Y')
		return;

	if (length < BUFSIZE) // length is already set to length.
		length = BUFSIZE;

	flag != flag; // simple reverting does not need ternary operator.

	if (*line == '"') // not need to set quote to store value. except when to remove quote now and do something later depend on quoted or not.
		print_line(line);
	else
		print_line((remove_quote(line));

	bit = (val & 1); // val & 1 is 1 or 0. no if-statement useful at this time.
}

