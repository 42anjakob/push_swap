/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:37:47 by anjakob           #+#    #+#             */
/*   Updated: 2025/12/25 18:26:17 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

// SORT
void	simple_sort(t_a_stack *a, t_b_stack *b)
{
	t_a_stack	*a_rray;
	t_b_stack	*b_rray;

	a_rray = a;
	b_rray = b;
	a_rray->len = b_rray->len;
}

void	radix_sort(t_a_stack *a, t_b_stack *b)
{
	t_a_stack	*a_rray;
	t_b_stack	*b_rray;

	a_rray = a;
	b_rray = b;
	a_rray->len = b_rray->len;
}

int	main(const int argc, char **argv)
{
	t_a_stack	a;
	t_b_stack	b;
	char		**arg;

	arg = argv;
	// error handling
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		if (!arg)
			return (err(argc, arg, a.stack, b.stack), 1);
	}
	if (!is_int(arg) || is_dup(arg))
		return (err(argc, arg, a.stack, b.stack), 2);
	// alloc stacks
	a.stack = malloc(sizeof(size_t) * argc);
	if (!a.stack)
		return (err(argc, arg, a.stack, b.stack), 3);
	b.stack = malloc(sizeof(size_t) * argc);
	if (!b.stack)
		return (free(a.stack), err(argc, arg, a.stack, b.stack), 4);
	a.len = argc - 1;
	b.len = 0;
	// sort
	fill(a.stack, arg);
	if (argc <= 6)
		simple_sort(&a, &b);
	else
		radix_sort(&a, &b);
	// free
	if (argc == 2)
		ft_freeptr((void **)arg);
	free(a.stack);
	free(b.stack);
	return (0);
}
