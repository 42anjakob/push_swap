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
// #include <stdio.h>

int	check_user_input(const char **argv) // modified atoi() with error handling / exit()
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] != '-' || argv[i][j] != '+') && (argv[i][j] < '0' || argv[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	fill(size_t *a, const char **argv)
{
	long	n;
	int		i;

	i = 1;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		n += 2147483648;
		if (n < 0 || n > 4294967295)
			return (free(a), 0);
		a[i - 1] = n;
		i++;
	}
	a[i - 1] = 0;
	return (1);
}

int	dup(const size_t *a, const int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (a[j])
		{
			if (a[i] == a[j])
				return (free(a), 0);
			j++;
		}
		i++;
	}
	return (1);
}

void	simple_sort(size_t *a, size_t *b)
{
	size_t	*a_rray = a;
	size_t	*b_rray = b;

	a_rray = b_rray;
	// algorithm
}

void	radix_sort(size_t *a, size_t *b)
{
	size_t	*a_rray = a;
	size_t	*b_rray = b;

	a_rray = b_rray;
	// algorithm
}

int	main(const int argc, const char **argv)
{
	size_t		*a;
	size_t		*b;

	if (argc <= 1)
		return (0);
	if (!check_user_input(argv))
		return (write(1, "Error\n", 6), 0);
	a = malloc(sizeof(size_t) * argc);
	if (!a)
		return (write(1, "Error\n", 6), 0);
	b = malloc(sizeof(size_t) * argc);
	if (!b)
		return (free(a), write(1, "Error\n", 6), 0);
	if (!fill(a, argv) && !dup(a, argc))
		return (write(1, "Error\n", 6), 0);
	if (argc <= 6)
		simple_sort(a, b);
	else
		radix_sort(a, b);
	free(a);
	free(b);
	return (1);
}