/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:37:49 by anjakob           #+#    #+#             */
/*   Updated: 2026/01/13 05:54:07 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct a_stack
{
	size_t	*stack;
	size_t	len;
}	t_a_stack;

typedef struct b_stack
{
	size_t	*stack;
	size_t	len;
}	t_b_stack;

// utils.c
void	err(int argc, char **arg, size_t *a, size_t *b);
int		is_int(char **arg);
int		is_dup(char **arg);
void	fill_index(t_a_stack *a, char **arg);
int		is_sorted(t_a_stack *a);

// sort.c
int		p(size_t *src, size_t *dst, size_t *src_len, size_t *dst_len);
int		s(size_t *src);
int		r(size_t *src, size_t src_len);
int		rr(size_t *src, size_t src_len);

// less_then_six.c
void	if_three(t_a_stack *a, size_t plus);
void	if_four(t_a_stack *a, t_b_stack *b);
void	if_five(t_a_stack *a, t_b_stack *b);

// init.c
int		init(t_a_stack *a, t_b_stack *b, int arg_c);

#endif