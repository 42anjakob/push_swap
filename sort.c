/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 04:52:53 by anjakob           #+#    #+#             */
/*   Updated: 2026/01/12 06:37:12 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p(size_t *src, size_t *dst, size_t *src_len, size_t *dst_len)
{
	size_t	swap;
	size_t	i;

	i = 0;
	if (*src_len == 0)
		return ;
	swap = src[0];
	while (i < *src_len)
	{
		src[i] = src[i + 1];
		i++;
	}
	i = *dst_len;
	while (i > 0)
	{
		dst[i] = dst[i - 1];
		i--;
	}
	dst[0] = swap;
	*src_len -= 1;
	*dst_len += 1;
}

void	r(size_t *src, size_t *src_len)
{
	size_t	swap;
	size_t	i;

	swap = src[0];
	i = 0;
	if (*src_len < 2)
		return ;
	while (i < *src_len)
	{
		src[i] = src[i + 1];
		i++;
	}
	src[*src_len - 1] = swap;
}
