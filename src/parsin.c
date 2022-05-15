/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:19:19 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/13 18:20:47 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void error(node **stack)
{
    ft_printf("Error\n");
    if (*stack != NULL)
        clear_elements(&*stack);
    exit(EXIT_FAILURE);
}

int is_num(char arg)
{
    if (arg < '0' || arg > '9')
        return (0);
    return (1);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int i;
    int size;

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

static int  non_int(char *arg)
{

    if ((ft_atoi(arg)) > 2147483647 || (ft_atoi(arg)) < -2147483648)
        return (1);
    return (0);
}

static int  has_non_num(char *arg)
{
    int i;

    i = 1;
    if (arg[0] != '-' && arg[0] != '+' && !is_num(arg[0]))
        return (1);
    while (arg[i])
    {
        if (arg[i] < '0' || arg[i] > '9')
            return (1);
        i++;
    }
    return (0);
}

void	parsin(char *arg, node **stack_a)
{
    if (has_non_num(arg))
            error(&*stack_a);
    if (non_int(arg))
           error(&*stack_a);
}
