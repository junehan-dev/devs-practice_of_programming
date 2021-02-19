#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct	Nameval	Nameval;
struct Nameval	{
	char		*name;
	int			value;
	Nameval		*next;
};
