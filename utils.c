/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:10:13 by anjakob           #+#    #+#             */
/*   Updated: 2025/12/25 18:59:14 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(int argc, char **arg, size_t *a, size_t *b)
{
	if (argc == 2)
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

	i = 1;
	while (arg[i++])
	{
		j = 0;
		if (arg[i][j] == '-' || arg[i][j] == '+')
		{
			if (arg[i][1] == '\0')
				return (0);
			j++;
		}
		while (arg[i][j++])
		{
			if (arg[i][j] < '0' || arg[i][j] > '9')
				return (0);
		}
		num = ft_atol(arg[i]);
		if (arg[i][0] == '\0' || j > 11
			|| (num < -2147483648 || num > 2147483647))
			return (0);
	}
	return (1);
}

int	is_dup(char **arg)
{
	int	i;
	int	j;

	i = 1;
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

void	fill(size_t *a, char **arg)
{
	long	n;
	int		i;

	i = 1;
	while (arg[i])
	{
		n = ft_atol(arg[i]);
		n += 2147483648;
		a[i - 1] = n;
		i++;
	}
	a[i - 1] = 0;
}
