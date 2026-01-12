/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:37:47 by anjakob           #+#    #+#             */
/*   Updated: 2026/01/12 07:18:09 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	size_t	i;

	i = 0;
	while (i < a->len)
	{
		if ((a->stack[0] & 1) == 0)
		{
			p(a->stack, b->stack, &a->len, &b->len);
			write(1, "pb\n", 3);
		}
		else if ((a->stack[0] & 1) == 1)
		{
			r(a->stack, &a->len);
			write(1, "ra\n", 3);
			i++;
		}
	}
	while (b->len > 0)
	{
		p(b->stack, a->stack, &b->len, &a->len);
		write(1, "pa\n", 3);
	}
}

void	bits_loop(t_a_stack *a, t_b_stack *b)
{
	size_t	bits;
	size_t	i;

	bits = 32;
	while (bits--)
	{
		if (is_sorted(a))
			break ;
		radix_sort(a, b);
		i = 0;
		while (i < a->len)
		{
			a->stack[i] = a->stack[i] >> 1;
			i++;
		}
	}
}

int	main(const int argc, char **argv)
{
	t_a_stack	a;
	t_b_stack	b;
	char		**arg_s;
	int			arg_c;

	arg_s = &argv[1];
	arg_c = argc - 1;

	// error handling
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		arg_s = ft_split(argv[1], ' ');
		if (!arg_s)
			return (err(arg_c, arg_s, a.stack, b.stack), 1);
		arg_c = 0;
		while (arg_s[arg_c])
			arg_c++;
	}
	if (!is_int(arg_s) || is_dup(arg_s))
		return (err(arg_c, arg_s, a.stack, b.stack), 2);

	// alloc stacks
	a.stack = malloc(sizeof(size_t) * arg_c);
	if (!a.stack)
		return (err(arg_c, arg_s, a.stack, b.stack), 3);
	b.stack = malloc(sizeof(size_t) * arg_c);
	if (!b.stack)
		return (err(arg_c, arg_s, a.stack, b.stack), 4);
	a.len = arg_c;
	b.len = 0;

	// sort
	fill_index(&a, arg_s);
	if (a.len <= 6)
		simple_sort(&a, &b);
	else
		bits_loop(&a, &b);
		
	// free
	if (argc == 2)
		ft_freeptr((void **)arg_s);
	free(a.stack);
	free(b.stack);
	return (0);
}
