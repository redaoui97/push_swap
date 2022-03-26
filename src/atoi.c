/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:33:50 by rnabil            #+#    #+#             */
/*   Updated: 2022/03/26 18:36:25 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int	neg;

	res = 0;
	if (!*str)
		return (0);
	if (str[0] != '-' && str[0] != '+' && !ft_isdigit(str[0]))
		return (0);
	if (str[0] == '-')
		neg = 1;
	else
		neg = 0;
	if (!ft_isdigit(str[0]))
		i = 1;
	else
		i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - 48);
	if (neg)
		return (res * -1);
	else
		return (res);
}
