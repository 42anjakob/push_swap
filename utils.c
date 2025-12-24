/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjakob <anjakob@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:10:13 by anjakob           #+#    #+#             */
/*   Updated: 2025/12/24 16:41:19 by anjakob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *s)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	while (*s == '\t' || *s == '\n' || *s == '\v'
		|| *s == '\f' || *s == '\r' || *s == ' ')
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (s && *s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;
	int					i;

	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (!s1) ? -1 : 1;
	while (cast_s1[i] && cast_s2[i] && cast_s1[i] == cast_s2[i])
		i++;
	return (cast_s1[i] - cast_s2[i]);
}
