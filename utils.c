/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:10:13 by anjakob           #+#    #+#             */
/*   Updated: 2026/01/13 05:01:56 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(int argc, char **arg, size_t *a, size_t *b)
{
	if (argc == 2 && arg)
		ft_freeptr((void **)arg);
	if (a)
		free(a);
	if (b)
		free(b);
	write(1, "Error\n", 6);
}

int	is_int(char **arg)
{
	long	num;
	int		i;
	int		j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		if (arg[i][j] == '-' || arg[i][j] == '+')
		{
			if (arg[i][++j] == '\0')
				return (0);
		}
		while (arg[i][j++])
		{
			if (arg[i][j - 1] < '0' || arg[i][j - 1] > '9')
				return (0);
		}
		num = ft_atol(arg[i]);
		if (arg[i++][0] == '\0' || j > 12
			|| (num < -2147483648 || num > 2147483647))
			return (0);
	}
	return (1);
}

int	is_dup(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = 1;
		while (arg[i + j])
		{
			if (!ft_strcmp(arg[i], arg[i + j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	fill_index(t_a_stack *a, char **arg)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = -1;
	while (arg[++i])
		a->stack[i] = ft_atol(arg[i]);
	i = -1;
	while (++i < a->len)
	{
		j = -1;
		while (++j < a->len)
			if (a->stack[j] > i)
				break ;
		k = j;
		j = -1;
		while (++j < a->len)
			if (a->stack[k] > a->stack[j] && a->stack[j] > i)
				k = j;
		a->stack[k] = i;
	}
}

int	is_sorted(t_a_stack *a)
{
	size_t	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
