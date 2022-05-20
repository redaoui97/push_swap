/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:20:57 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 18:21:43 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void	clear_elements(t_node **stack_a)
{
	t_node	*perm;

	while (*stack_a)
	{
		perm = (*stack_a)->next;
		free (*stack_a);
		*stack_a = perm;
	}
}
