/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_nrlookup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:53:16 by junehan           #+#    #+#             */
/*   Updated: 2021/03/18 16:19:50 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_btree.h"

Node	*ft_btree_nrlookup(Node *node, char *name)
{
	int	cmp;

	while (node) {
		cmp = strcmp(name, node->name);
		if (cmp == 0)
			return (node);
		else if (cmp < 0)
			node = node->left;
		else
			node = node->right;
	}

	return (NULL);
}
