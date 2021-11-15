/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:37 by ctommy            #+#    #+#             */
/*   Updated: 2021/11/14 14:16:38 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_zero(t_params *params, unsigned int x, char *c)
{
	if (x > 0)
	{
		c[0] = '0';
		c[1] = (char) params->type;
		params->flag = 2;
	}
	else
	{
		params->flag = 0;
		params->sharp = 0;
	}
}

int	ft_len_x(unsigned long num)
{
	int	len;

	len = 0;
	if (!num)
		return (1);
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static char	*ft_itoa_x(unsigned long num, int len, t_params *params)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len > -1)
	{
		if (num % 16 > 9)
			str[len--] = (char)((num % 16) + params->type - 33);
		else
			str[len--] = (char)((num % 16) + 48);
		num /= 16;
	}
	return (str);
}

int	ft_sharp_or_no(t_params *params, int len_x, char *str_x, char *c)
{
	int	len;

	len = 0;
	if (params->sharp)
	{
		if (params->precision < 0)
			len += ft_mps_none_precision(params, len_x, str_x, c);
		else
			len += ft_mps_have_precision(params, len_x, str_x, c);
	}
	else
	{
		if (params->precision < 0)
			len += ft_pos_none_precision(params, len_x, str_x);
		else
			len += ft_pos_have_precision(params, len_x, str_x);
	}
	return (len);
}

int	ft_print_x(t_params *params, unsigned int x)
{
	int				len;
	int				len_x;
	char			*str_x;
	char			c[2];
	unsigned long	num;

	len = 0;
	ft_zero(params, x, c);
	if (params->precision == 0 && x == 0)
	{
		len += ft_print_width(params->width, 0);
		return (len);
	}
	num = (unsigned long) x;
	len_x = ft_len_x(num);
	str_x = ft_itoa_x(num, len_x, params);
	len += ft_sharp_or_no(params, len_x, str_x, c);
	free(str_x);
	return (len + len_x);
}
