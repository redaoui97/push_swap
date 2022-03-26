/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:21:02 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/26 18:28:46 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

node	*duplicate_node(node *old)
{
	node	*new;

	new = new_node(0);
	new->position = old->position;
	new->value = old->value;
	new->next = old->next;
	new->previous = old->previous;
	new->first = old->first;
	new->last = old->last;
	return (new);
}
