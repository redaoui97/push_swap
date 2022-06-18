/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:19:19 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 18:48:31 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

static int	has_non_num(char *arg)
{
	int	i;

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

void	parsin(char *arg, t_node **stack_a)
{
	char	**words;
	char	*word;
	int		size;
	int		i;

	words = ft_split(arg, ' ', &size);
	if (!words)
		error(&*stack_a);
	i = 0;
	while (words[i])
	{
		if (has_non_num(words[i]))
			error(&*stack_a);
		if (non_int(words[i], &*stack_a))
			error(&*stack_a);
		add_element(&*stack_a, ft_atoi(words[i], &*stack_a));
		i++;
	}
	i = 0;
	while (words[i])
		free(words[i++]);
	free (words);
}
