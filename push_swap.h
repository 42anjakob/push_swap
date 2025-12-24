/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:37:49 by anjakob           #+#    #+#             */
/*   Updated: 2025/12/24 16:27:46 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct a_stack
{
	size_t	*stack;
	size_t	len;
}	a_stack;

typedef struct b_stack
{
	size_t	*stack;
	size_t	len;
}	b_stack;

long	ft_atol(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

#endif