/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:51 by ctommy            #+#    #+#             */
/*   Updated: 2021/11/14 14:16:52 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_null(t_params *params, int len)
{
	if (params->plus && params->minus)
		ft_putchar_fd('+', 1);
	else if (params->space && params->minus)
		ft_putchar_fd(' ', 1);
	len = ft_print_width(params->width - params->plus - params->space,
			0);
	if (params->plus && !params->minus)
		ft_putchar_fd('+', 1);
	else if (params->space && !params->minus)
		ft_putchar_fd(' ', 1);
	return (len + 1);
}

int	ft_print_width(int width, int zero)
{
	int	len;

	len = 0;
	while (width-- > 0)
	{
		if (zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		len++;
	}
	return (len);
}

int	ft_pos_or_neg(int len, t_params *params, char *str, int len_di)
{
	char	*c;

	if (params->pos_or_neg == 1 && !params->space && !params->plus)
	{
		if (params->precision < 0)
			len = ft_pos_none_precision(params, len_di, str);
		else
			len = ft_pos_have_precision(params, len_di, str);
	}
	else
	{
		if (params->pos_or_neg == -1)
			c = "-";
		else if (params->plus)
			c = "+";
		else
			c = " ";
		if (params->precision < 0)
			len = ft_mps_none_precision(params, len_di, str, c);
		else
			len = ft_mps_have_precision(params, len_di, str, c);
	}
	return (len);
}

int	ft_print_di(t_params *params, int num)
{
	char			*str;
	int				len;
	int				len_di;

	len = 0;
	if (params->precision == 0 && num == 0)
		return (ft_print_null(params, len));
	if (num < 0)
	{
		num *= -1;
		params->pos_or_neg = -1;
	}
	str = ft_itoa(num);
	len_di = (int)ft_strlen(str);
	len = ft_pos_or_neg(len, params, str, len_di);
	free(str);
	return (len + len_di);
}
