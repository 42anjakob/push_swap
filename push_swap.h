/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:37:49 by anjakob           #+#    #+#             */
/*   Updated: 2026/01/12 07:12:51 by anjakob          ###   ########.fr       */
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
void	p(size_t *src, size_t *dst, size_t *src_len, size_t *dst_len);
void	r(size_t *src, size_t *src_len);

#endif