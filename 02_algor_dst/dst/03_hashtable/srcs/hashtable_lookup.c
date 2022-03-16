struct List_node {
	char		*key;	// KeyName
	int			val;	// Payload
	List_node	*next;	// LIST TO NEXT
};

int	hash(char *hashkey)
{
	int	hashvalue;

	hashvalue = 3124135;
	return (hash_value);
}


List_node *lookup(char *key, int create, int value)
{
	int	h;			
	List_node *sym_node;	// symbol table

	h = hash(key);
	sym_node = symbol_table[h];	// O(1);
	while (sym_node != NULL) {	// find SAME name
		if (strcmp(key, sym_node->key) == 0) {	// O(n of listlink)
			// perfect matched list Node
			return (sym_node);
		}
		sym_node = sym_node->next;
	}

	if (create) { // no samename and create operation
		sym_node = (List_node *)malloc(sizeof(ListNode));
		sym_node->key = key;
		sym_node->value = value;
		sym_node->next = symbol_table[h];	
		symbol_table[h] = sym_node; // Linked list head change
		return (sym_node);
	}

	return (NULL);
}

if (lookup("username") == NULL) // {"0": ? value to find};
	additem(newitem("username", value));

