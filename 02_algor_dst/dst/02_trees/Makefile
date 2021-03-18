CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Iincludes -c
OBJECTS	= ft_btree_insert.o ft_btree_create.o \
			 ft_btree_lookup.o ft_btree_inorder_map.o
NAME	= ft_btree.a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

ft_btree_lookup.o:
	$(CC) $(CFLAGS)	srcs/ft_btree_lookup.c -o $@

ft_btree_insert.o:
	$(CC) $(CFLAGS) srcs/ft_btree_insert.c -o $@

ft_btree_create.o:
	$(CC) $(CFLAGS) srcs/ft_btree_create.c -o $@

ft_btree_inorder_map.o:
	$(CC) $(CFLAGS) srcs/ft_btree_inorder_map.c -o $@

.PHONY: clean
clean:
	/bin/rm $(OBJECTS)

.PHONY: fclean
fclean:
	/bin/rm $(NAME)

