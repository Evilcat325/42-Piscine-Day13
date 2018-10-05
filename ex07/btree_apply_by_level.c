/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:35:49 by seli              #+#    #+#             */
/*   Updated: 2018/10/05 02:50:14 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#define MAX(X, Y) X > Y ? X : Y
#define CURRENT 0
#define MAXLEVEL 1
#define FIRST 2

int btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + MAX(btree_level_count(root->left),
					btree_level_count(root->right)));
}

void	btree_bfs(t_btree *root, int trace[3],
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!root)
		trace[CURRENT] -= 1;
	else if (trace[CURRENT] == trace[MAXLEVEL])
	{
		applyf(root->item, trace[CURRENT], trace[FIRST]);
		trace[FIRST] = 0;
		trace[CURRENT] -= 1;
	}
	else
	{
		trace[CURRENT] += 1;
		btree_bfs(root->left, trace, applyf);
		trace[CURRENT] += 1;
		btree_bfs(root->right, trace, applyf);
	}
}

void	btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	i;
	int	level;
	int	trace[3];

	level = btree_level_count(root);
	i = 0;
	while (i < level)
	{
		trace[CURRENT] = 0;
		trace[MAXLEVEL] = i;
		trace[FIRST] = 1;
		btree_bfs(root, trace, applyf);
	}
}
