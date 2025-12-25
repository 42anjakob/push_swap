/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:37:49 by anjakob           #+#    #+#             */
/*   Updated: 2025/12/25 18:26:25 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

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
void	fill(size_t *a, char **arg);

#endif