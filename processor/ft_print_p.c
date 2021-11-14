/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:48 by ctommy            #+#    #+#             */
/*   Updated: 2021/11/14 14:16:49 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	ft_width_p(t_params *params, char *str, int len)
{
	int	len_p;

	len_p = 0;
	if ((params->width > len + 2) && !(params->minus))
		len_p = ft_print_width(params->width - len - 2, 0);
	write (1, "0x", 2);
	write (1, str, len);
	if (params->width > len + 2 && params->minus)
		len_p = ft_print_width(params->width - len - 2, 0);
	return (len + len_p + 2);
}

static char	*ft_itoa_p(unsigned long num, int len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len > -1)
	{
		if (num % 16 > 9)
			str[len--] = (num % 16) + 87;
		else
			str[len--] = (num % 16) + 48;
		num /= 16;
	}
	return (str);
}

int	ft_print_p(t_params *params, unsigned long point)
{
	char	*str;
	int		len;
	int		len_p;

	len = 0;
	len_p = 0;
	if ((params->precision <= 0) && (point == 0))
	{
		str = ft_strdup("0");
		len = 1;
	}
	else
	{
		if (point != 0)
			len_p = ft_len_x(point);
		len += len_p;
		str = ft_itoa_p(point, len_p);
	}
	len = ft_width_p(params, str, len);
	free(str);
	return (len);
}
