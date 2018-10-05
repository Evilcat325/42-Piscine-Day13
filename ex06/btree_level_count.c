/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:32:55 by seli              #+#    #+#             */
/*   Updated: 2018/10/05 02:34:27 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#define MAX(X, Y) X > Y ? X : Y

int btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + MAX(btree_level_count(root->left),
					btree_level_count(root->right)));
}
