/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:37:47 by anjakob           #+#    #+#             */
/*   Updated: 2026/01/16 20:04:46 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pars(int argc, char **argv, int *arg_c, char ***arg_v)
{
	if (argc == 1)
		exit(0);
	else if (argc == 2)
	{
		*arg_v = ft_split(argv[1], ' ');
		if (!(*arg_v))
			return (0);
		*arg_c = 0;
		while ((*arg_v)[*arg_c])
			*arg_c += 1;
	}
	else
	{
		*arg_v = &argv[1];
		*arg_c = argc - 1;
	}
	return (1);
}

void	simple_sort(t_a_stack *a, t_b_stack *b)
{
	if (is_sorted(a))
		return ;
	else if (a->len == 2)
	{
		s(a, a->len);
		write(1, "sa\n", 3);
	}
	else if (a->len == 3)
		if_three(a, 0);
	else if (a->len == 4)
		while (!is_sorted(a) || a->len != 4)
			if_four(a, b);
	else if (a->len == 5)
		while (!(is_sorted(a)) || a->len != 5)
			if_five(a, b);
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
			r(a->stack, a->len);
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
	char		**arg_v;
	int			arg_c;

	arg_v = NULL;
	a.stack = NULL;
	b.stack = NULL;
	if (!pars(argc, argv, &arg_c, &arg_v))
		return (err(argc, arg_v, a.stack, b.stack), 1);
	if (!is_int(arg_v) || is_dup(arg_v))
		return (err(argc, arg_v, a.stack, b.stack), 2);
	if (!init(&a, &b, arg_c))
		return (err(argc, arg_v, a.stack, b.stack), 3);
	fill_index(&a, arg_v);
	if (a.len < 6)
		simple_sort(&a, &b);
	else
		bits_loop(&a, &b);
	if (argc == 2 && arg_v)
		ft_freeptr((void **)arg_v);
	return (free(a.stack), free(b.stack), 0);
}
