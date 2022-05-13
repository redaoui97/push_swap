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

static void error()
{
    ft_printf("Error\n");
    exit(0);
}

static int  has_non_num(char *arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (arg[i] <= '0' || arg[i] >= '9')
            return (1);
        i++;
    }
    return (0);
}

static int  non_int(char *arg)
{
    if (ft_atoi(arg) > 2147483647 || ft_atoi(arg) < -2147483648)
        return (1);
    return (0);
}

void	parsin(char *arg, char *argv[])
{
    int i;

    i = 0;
    if (has_non_num(arg))
        error();
    if (non_int(arg))
        error();
    while (arg[i])
    {
        if (ft_atoi(arg[i]) == ft_atoi(arg))
            error();
        i++;
    }
}
