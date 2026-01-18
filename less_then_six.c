/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_then_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 23:55:55 by anjakob           #+#    #+#             */
/*   Updated: 2026/01/18 18:22:46 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_three(t_a_stack *a, size_t ft_pos)
{
	if (a->stack[0] == 2 + ft_pos && a->stack[1] == 1 + ft_pos
		&& a->stack[2] == 0 + ft_pos
		&& s(a->stack) && rr(a->stack, a->len))
		write(1, "sa\nrra\n", 7);
	else if (a->stack[0] == 2 + ft_pos && a->stack[1] == 0 + ft_pos
		&& a->stack[2] == 1 + ft_pos
		&& r(a->stack, a->len))
		write(1, "ra\n", 3);
	else if (a->stack[0] == 1 + ft_pos && a->stack[1] == 0 + ft_pos
		&& a->stack[2] == 2 + ft_pos && s(a->stack))
		write(1, "sa\n", 3);
	else if (a->stack[0] == 1 + ft_pos && a->stack[1] == 2 + ft_pos
		&& a->stack[2] == 0 + ft_pos && rr(a->stack, a->len))
		write(1, "rra\n", 4);
	else if (a->stack[0] == 0 + ft_pos && a->stack[1] == 2 + ft_pos
		&& a->stack[2] == 1 + ft_pos
		&& s(a->stack) && r(a->stack, a->len))
		write(1, "sa\nra\n", 6);
}

void	if_four(t_a_stack *a, t_b_stack *b)
{
	if (a->stack[0] == 0)
	{
		p(a->stack, b->stack, &a->len, &b->len);
		write(1, "pb\n", 3);
		if_three(a, 1);
		p(b->stack, a->stack, &b->len, &a->len);
		write(1, "pa\n", 3);
	}
	else
	{
		r(a->stack, a->len);
		write(1, "ra\n", 3);
	}
}

void	if_five(t_a_stack *a, t_b_stack *b)
{
	if (b->len == 2 && a->stack[0] == 2 && a->stack[1] == 3
		&& a->stack[2] == 4 && b->stack[0] == 1 && b->stack[1] == 0)
	{
		p(b->stack, a->stack, &b->len, &a->len);
		p(b->stack, a->stack, &b->len, &a->len);
		write(1, "pa\npa\n", 6);
	}
	else if ((a->stack[0] == 0 || a->stack[0] == 1)
		&& p(a->stack, b->stack, &a->len, &b->len))
		write(1, "pb\n", 3);
	else if (a->len == 3)
	{
		if_three(a, 2);
		if (b->stack[0] == 0 && s(b->stack))
			write(1, "sb\n", 3);
	}
	else
	{
		r(a->stack, a->len);
		write(1, "ra\n", 3);
	}
}
