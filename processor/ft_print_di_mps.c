/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_mps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:33 by ctommy            #+#    #+#             */
/*   Updated: 2021/11/14 14:16:34 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_mps_none_precision(t_params *params, int len_di, char *str, char *c)
{
	int	len;

	len = 0;
	if ((params->width > len_di + params->flag) && !(params->minus))
	{
		if (!(params->zero))
		{
			len += ft_print_width(params->width - len_di - params->flag, 0);
			write(1, c, params->flag);
		}
		else
		{
			write(1, c, params->flag);
			len += ft_print_width(params->width - len_di - params->flag, 1);
		}
		write (1, str, len_di);
	}
	else
	{
		write(1, c, params->flag);
		write (1, str, len_di);
		if ((params->width > len_di + params->flag) && params->minus)
			len += ft_print_width(params->width - len_di - params->flag, 0);
	}
	return (len + params->flag);
}

int	ft_mps_have_precision(t_params *params, int len_di, char *str, char *c)
{
	int	len;

	len = 0;
	if ((params->width > params->precision + params->flag) && !(params->minus))
	{
		if (params->precision > len_di)
			len += ft_print_width(params->width - params->precision
					- params->flag, 0);
		else if (params->width > len_di + params->flag)
			len += ft_print_width(params->width - len_di - params->flag, 0);
	}
	write(1, c, params->flag);
	if (params->precision > len_di)
		len += ft_print_width(params->precision - len_di, 1);
	write (1, str, len_di);
	if ((params->width > params->precision + params->flag) && params->minus)
	{
		if (params->precision > len_di)
			len += ft_print_width(params->width - params->precision
					- params->flag, 0);
		else if (params->width > len_di + params->flag)
			len += ft_print_width(params->width - len_di - params->flag, 0);
	}
	return (len + 1);
}
