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

static int	words_size(char **words)
{
	int	i;

	i = 1;
	while (words[i])
		i++;
	return (i);
}

void	parsin(char *arg, t_node **stack_a)
{
	char	**words;
	int		size;
	int		i;

	if (ft_strcmp(arg, ""))
		error(&*stack_a);
	words = ft_split(arg, ' ', &size);
	if (!words)
		error(&*stack_a);
	i = words_size(words) - 1;
	while (i >= 0)
	{
		if (has_non_num(words[i]) || non_int(words[i], &*stack_a)
			|| words[i] == '\0')
			error(&*stack_a);
		add_element(&*stack_a, ft_atoi(words[i], &*stack_a));
		i--;
	}
	i = 0;
	while (words[i])
		free(words[i++]);
	free (words);
}
