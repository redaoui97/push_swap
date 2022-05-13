/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:12 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/29 21:04:27 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

node	*new_node(int value)
{
	node	*n;

	n = (node *)malloc(sizeof(node));
	if (!n)
		return (NULL);
	n->bool_lis = 0;
	n->value = value;
	n->next = NULL;
	n->previous = NULL;
	n->position = 0;
	n->first = NULL;
	n->last = NULL;
	n->lis = -1;
	n->bool_lis = 0;
	n->moves_count = -1;
	return (n);
}
