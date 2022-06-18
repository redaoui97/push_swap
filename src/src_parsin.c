/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_parsin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:49:26 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 20:07:35 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	error(t_node **stack)
{
	ft_printf("Error\n");
	if (*stack != NULL)
		clear_elements(&*stack);
	exit(EXIT_FAILURE);
}

int	is_num(char arg)
{
	if (arg < '0' || arg > '9')
		return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	size;

	size = ft_strlen(s1);
	if (ft_strlen(s2) != size)
		return (0);
	i = 0;
	while (i < size)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	non_int(char *arg, t_node **stack)
{
	if ((ft_atoi(arg, &*stack)) > 2147483647
		|| (ft_atoi(arg, &*stack)) < -2147483648)
		return (1);
	return (0);
}
