#ifndef _FT_BTREE_H_
#define _FT_BTREE_H_
typedef struct Node Node;
typedef struct Node {
	char	*name;
	int		value;
	struct Node	*left;
	struct Node	*right;
} Node;
#endif
