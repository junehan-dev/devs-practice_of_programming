/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_lookup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:12:58 by junehan           #+#    #+#             */
/*   Updated: 2021/03/18 14:44:59 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_btree.h"

Node *ft_btree_lookup(Node *node, char *name)
{
	int cmp;
	Node *found;

	if (!node)
		return (NULL);
	cmp = strcmp(name, node->name);
	if (!cmp)
		found = node;
	else if (cmp < 0)
		found = ft_btree_lookup(node->left, name);
	else
		found = ft_btree_lookup(node->right, name);

	return (found);
}
