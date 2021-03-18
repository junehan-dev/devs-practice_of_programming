/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_inorder_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:51:44 by junehan           #+#    #+#             */
/*   Updated: 2021/03/18 17:30:15 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_inorder_map(Node *node, void (*fn)(Node *, void *), void *arg)
{
	if (!node)
		return;

	ft_btree_inorder_map(node->left, fn, arg);
	(*fn)(node, arg);
	ft_btree_inorder_map(node->right, fn, arg);
}

