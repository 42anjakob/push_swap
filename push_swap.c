/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:37:47 by anjakob           #+#    #+#             */
/*   Updated: 2025/12/24 17:07:54 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

// ERROR HANDELING
int	is_int(const char **argv)
{
	long long	num;
	int			i;
	int			j;

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
		num = ft_atol(argv[i]);
		if (num < -2147483648 || num > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	is_dup(const char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// SORT
void	fill(size_t *a, const char **argv) // or index
{
	long	n;
	int		i;

	i = 1;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		n += 2147483648;
		a[i - 1] = n;
		i++;
	}
	a[i - 1] = 0;
}

void	simple_sort(a_stack *a, b_stack *b)
{
	a_stack	*a_rray = a;
	b_stack	*b_rray = b;

	a_rray = b_rray;
	// algorithm
}

void	radix_sort(a_stack *a, b_stack *b)
{
	a_stack	*a_rray = a;
	b_stack	*b_rray = b;

	a_rray = b_rray;
	// algorithm
}

int	main(const int argc, const char **argv)
{
	a_stack	a;
	b_stack	b;

	// error handling
	if (argc < 2)
		return (0);
	if (!is_int(argv) || is_dup(argv))
		return (write(1, "Error\n", 6), 0);

	// alloc stacks
	a.stack = malloc(sizeof(size_t) * argc);
	if (!a.stack)
		return (write(1, "Error\n", 6), 0);
	b.stack = malloc(sizeof(size_t) * argc);
	if (!b.stack)
		return (free(a.stack), write(1, "Error\n", 6), 0);
	a.len = argc - 1;
	b.len = 0;

	// sort
	fill(a.stack, argv); // indexing
	if (argc <= 6)
		simple_sort(a, b);
	else
		radix_sort(a, b);
	
	// free
	free(a.stack);
	free(b.stack);
	return (1);
}