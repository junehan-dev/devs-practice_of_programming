/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:30:51 by junehan           #+#    #+#             */
/*   Updated: 2021/03/18 16:44:19 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "ft_btree.h"

Node *ft_insert(Node *node, Node *new)
{
	int	cmp;

	if (!node) /* base condition */
		return (new);

	while (node) {
		cmp = strcmp(new->name, node->name);
		if (cmp)
			if (cmp > 0 && node->right)
				node = node->right;
			else if (cmp < 0 && node->left)
				node = node->left;
			else {
				if (!(node->right) && cmp > 0)
					node->right = new;
				else
					node->left = new;
				return (new);
			}
		else {
			write(STDOUT_FILENO, "Insert: duplicate entry ignored\n", 32);
			return (NULL);
		}
	}
}

