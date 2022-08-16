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

#include "../header/push_swap.h"

static size_t	ret_right_size(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	if (start + len < ft_strlen(s))
		size = len + 1;
	else
		size = ft_strlen(s) - start + 1;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		a = malloc(sizeof(char) * 1);
		a[0] = 0;
		return (a);
	}
	size = ret_right_size(s, start, len);
	a = (char *)malloc(sizeof(char) * (size));
	if (!a)
		return (NULL);
	i = 0;
	j = start;
	while (i < size - 1 && s[j])
		a[i++] = s[j++];
	a[i] = '\0';
	return (a);
}

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
	char	*word;
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
		if (has_non_num(words[i]) || non_int(words[i], &*stack_a) || words[i] == '\0')
			error(&*stack_a);
		add_element(&*stack_a, ft_atoi(words[i], &*stack_a));
		i--;
	}
	i = 0;
	while (words[i])
		free(words[i++]);
	free (words);
}
