/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 04:52:53 by anjakob           #+#    #+#             */
/*   Updated: 2026/01/13 05:11:41 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p(size_t *src, size_t *dst, size_t *src_len, size_t *dst_len)
{
	size_t	tmp;
	size_t	i;

	i = 0;
	tmp = src[0];
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
	dst[0] = tmp;
	*src_len -= 1;
	*dst_len += 1;
	return (1);
}

int	s(size_t *src)
{
	size_t	tmp;

	tmp = src[0];
	src[0] = src[1];
	src[1] = tmp;
	return (1);
}

int	r(size_t *src, size_t *src_len)
{
	size_t	tmp;
	size_t	i;

	tmp = src[0];
	i = 0;
	while (i < *src_len)
	{
		src[i] = src[i + 1];
		i++;
	}
	src[*src_len - 1] = tmp;
	return (1);
}

int	rr(size_t *src, size_t *src_len)
{
	size_t	tmp;
	size_t	i;

	tmp = src[*src_len - 1];
	i = *src_len;
	while (i > 0)
	{
		src[i] = src[i - 1];
		i--;
	}
	src[0] = tmp;
	return (1);
}
