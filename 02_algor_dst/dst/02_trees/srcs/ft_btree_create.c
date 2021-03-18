/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:06:18 by junehan           #+#    #+#             */
/*   Updated: 2021/03/18 16:13:57 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ft_btree.h"

Node	*ft_btree_create(char *name, int value)
{
	Node	*new;

	new = malloc(sizeof(Node) * 1);
	if (!new)
		return (NULL);

	new->name = strdup(name);
	if (!(new->name)) {
		free(new);
		return (NULL);
	}

	new->value = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

