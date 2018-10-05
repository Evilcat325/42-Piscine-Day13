/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:14:08 by seli              #+#    #+#             */
/*   Updated: 2018/10/05 02:31:01 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root,
							void *data_ref, int (*cmpf)(void *, void *))
{
	t_btree	*left;
	t_btree	*right;

	if (!root)
		return (0);
	left = btree_search_item(root->left, data_ref, cmpf);
	if (left)
		return (left);
	if (cmpf(root->item, data_ref) == 0)
		return (root);
	right = btree_search_item(root->right, data_ref, cmpf);
	if (right)
		return (right);
	return (0);
}
