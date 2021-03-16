#include "./s_list.h"

/*
 * typedef struct	Nameval	Nameval;
 * struct Nameval	{
 * 	char		*name;
 * 	int			value;
 * 	Nameval		*next;
 * };
 */

Nameval	*newitem(char *name, int value);
Nameval	*addfront(Nameval *start, Nameval *new);
size_t	flush_list(Nameval	*start);

int		main(int argc, const char *argv[])
{
	Nameval *start;
	int 	i;
	size_t	ret;

	i = 1;
	start = newitem(strdup(argv[i]), i);

	if (argc == 1)
		return (EXIT_SUCCESS);
	while (++i < argc) 
		start  = addfront(start, newitem(strdup(argv[i]), i));

	ret = flush_list(start);

	if (start)
		return (EXIT_FAILURE);
	if (ret != (size_t)(argc - 1))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
/*
void	foreach(Nameval *listp)
{
	
}
*/
Nameval	*newitem(char *name, int value)
{
	Nameval		*nvpt;

	nvpt = (Nameval *)malloc(sizeof(Nameval));

	if (!nvpt)
		return (NULL);

	nvpt -> name = name;
	nvpt -> value = value;
	nvpt -> next = NULL;

	return (nvpt);
}

Nameval	*addfront(Nameval *start, Nameval *new)
{
	new -> next = start;
	return (new);
}

size_t	flush_list(Nameval	*start)
{
	size_t	len;
	Nameval	*next;
	Nameval	*buf;

	len = 1;

	next = start->next;

	while (next) {
		buf = next->next;
		write(STDIN_FILENO, next->name, strlen(next->name));
		free(next->name);
		free(next);
		len++;
		next = buf;	
	}
	write(STDIN_FILENO, start->name, strlen(start->name));
	free(start->name);
	free(start);
	return (len);
}


