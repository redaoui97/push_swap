/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:12 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/26 18:40:37 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// allocates a new node and returns a pointer to it

node	*new_node(int value)
{
	node	*n;

	n = (node *)malloc(sizeof(node));
	if (!n)
		return (NULL);
	n->value = value;
	n->next = NULL;
	n->previous = NULL;
	n->position = 0;
	n->first = NULL;
	n->last = NULL;
	n->lis = -1;
	n->bool_lis = -1;
	n->moves_count = -1;
	return (n);
}
