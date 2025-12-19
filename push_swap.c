/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-18 13:37:47 by anjakob           #+#    #+#             */
/*   Updated: 2025-12-18 13:37:47 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_user_input(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '-' && (argv[i][j] < '0' || argv[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	fill(int *a, char **argv)
{
	int	n;
	int	i;

	i = 1;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		if (n < 0)
			n = -n;
		else
			n += 2147483649; // maybe some quirks with max negative num. Yes quirks -1 being the lowest negative number you can have
		a[i - 1] = n;
		i++;
	}
	a[i - 1] = 0;
}

// void	index(int *a)
// {
// 	// loop to find the smallest number. Second... so on...
// }

// void	sort(int *a, int *b)
// {
// 	// algorithm
// }

int	main(int argc, char **argv)
{
	size_t		*a;
	size_t		*b;

	if (argc <= 1 || !check_user_input(argv))
		return (0);	
	a = malloc(sizeof(size_t) * argc);
	if (!a)
		return (0);
	b = malloc(sizeof(size_t) * argc);
	if (!b)
		return (free(a), 0);
	// fill(a, argc, argv);
	// index(a);
	// sort(a, b);
	free(a);
	free(b);
	return (1);
}