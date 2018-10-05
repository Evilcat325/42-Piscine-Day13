/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:14:08 by seli              #+#    #+#             */
/*   Updated: 2018/10/05 02:19:20 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root,
							void *data_ref, int (*cmpf)(void *, void *))
{
	if (!root)
		return (0);
	if (btree_search_item(root->left, data_ref, cmpf) != 0)
		return (root->left);
	else if (cmpf(root->item, data_ref))
		return (root);
	else if (btree_search_item(root->right, data_ref, cmpf) != 0)
		return (root->right);
	return (0);
}
