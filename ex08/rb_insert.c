/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:22:00 by seli              #+#    #+#             */
/*   Updated: 2018/10/05 23:32:24 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_rb_node		*rb_create(void *item)
{
	t_rb_node	*node;

	node = malloc(sizeof(t_rb_node));
	node->left = 0;
	node->right = 0;
	node->data = item;
	node->color = RB_BLACK;
	return (node);
}

void			rb_insert(struct s_rb_node **root,
				void *data, int (*cmpf)(void *, void *))
{
	if (!*root)
		root = rb_create(data);
}
