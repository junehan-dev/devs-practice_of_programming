/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:30:51 by junehan           #+#    #+#             */
/*   Updated: 2021/03/18 14:44:41 by junehan          ###   ########.fr       */
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

	cmp = strcmp(new->name, node->name);
	if (!cmp)
		write(STDOUT_FILENO, "Insert: duplicate entry ignored\n", 32);
	else if (cmp < 0)
		node->left = ft_insert(node->left, new);
	else
		node->right = ft_insert(node->right, new);

	return (node);
}



