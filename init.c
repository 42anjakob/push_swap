/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-14 20:01:38 by anjakob           #+#    #+#             */
/*   Updated: 2026-01-14 20:01:38 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init(t_a_stack *a, t_b_stack *b, int arg_c)
{
	a->stack = malloc(sizeof(size_t) * arg_c);
	b->stack = malloc(sizeof(size_t) * arg_c);
	if (!a->stack || !b->stack)
		return (0);
	a->len = arg_c;
	b->len = 0;
	return (1);
}
