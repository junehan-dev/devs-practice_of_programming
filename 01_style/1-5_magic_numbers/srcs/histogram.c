void	print_histogram(int limit)
{
	int fac;

	fac = limit / 20; // set scale factor

	int i;
	int col;
	int j;

	i = 0;
	col = 0;
	while (i < 27) { // generate histogram
		col += 3;
		int k = 21 - (let[i]/ fac);
		star = (let[i] == 0) ? ' ' : '*';
		j = k;
		while (j < 22) {
			draw(j, col, star);
			j++;
		}
		i++;
		j++;
	}
	draw(23, 2, ' '); // label x axis
	
	i = 'A';
	while (i < 'Z') {
		printf("%c ", i);
		i++;
	}
}
