enum {
	MINROW		= 1,					/* top edge */
	MINCOL		= 1,					/* left edge */
	MAXROW		= 24,					/* bottom edge */
	MAXCOL		= 80,					/* right edge */
	LABELROW	= 1,					/* position of labels */
	NLET		= 26,					/* size of alphabet */
	HEIGHT		= MAXROW - 4,			/* height of bars */
	WIDTH		= (MAXCOL - 1) / NLET	/* width of bars */
};

void	print_histogram(int lim, int letters[])
{
	int	fac;
	int *let;

	let = letters;

	fac = (lim + HEGHT - 1) / HEIGHT;	// set scale factor
	if (fac < 1)
		fac = 1;

	int i;

	i = 0;
	while (i < NLET) {		// generate histogram
		if (let[i] == 0)
			continue;

		int scaled_H;

		scaled_H = HEIGHT - let[i]/fac;
		while (scaled_H < HEIGHT) {
			draw(scaled_H + 1 + LABELROW, (i + 1) * WIDTH, '*');
			scaled_H++;
		}
	}

	draw(MAXROW - 1, MINCOL + 1, ' ');		// label x axis at the bottom
	i = 'A';
	while (i <= 'Z')
		printf("%c ", i++);
}
