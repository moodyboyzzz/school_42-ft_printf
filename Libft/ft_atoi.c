/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:05:53 by ctommy            #+#    #+#             */
/*   Updated: 2021/10/13 17:06:33 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int		nbr;
	int				negative;

	nbr = 0;
	negative = 1;
	while ((*str == '\n') || (*str == '\t') || (*str == '\v') \
		|| (*str == ' ') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && (*str >= '0') && (*str <= '9'))
	{
		nbr = 10 * nbr + (*str - '0');
		if (nbr > 2147483647 && negative == 1)
			return (-1);
		if (nbr > 2147483648 && negative == -1)
			return (0);
		str++;
	}
	return (nbr * negative);
}
