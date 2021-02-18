CC		= gcc
CFLAGS	= -Werror -Wall -Wextra -g

.DEFAULT_GOAL := all

.PHONY: all
all: src/bin_search.run src/quick_sort.run

src/bin_search.run:
	$(CC) $(CFLAGS) src/2-1_binsearch.c -o $@

src/quick_sort.run:
	$(CC) $(CFLAGS) src/2-2_quick_sort.c -o $@

.PHONY: clean
clean:
	/bin/rm src/*.run src/*.o

