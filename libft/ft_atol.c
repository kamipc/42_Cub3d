/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:37:07 by cpinho-c          #+#    #+#             */
/*   Updated: 2026/03/05 15:37:33 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	int				i;
	long long int	n;
	int				sign;

	i = 0;
	sign = 1;
	n = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}