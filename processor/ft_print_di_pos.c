/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:53 by ctommy            #+#    #+#             */
/*   Updated: 2021/11/14 14:16:54 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_pos_none_precision(t_params *params, int len_di, char *str)
{
	int	len;

	len = 0;
	if ((params->width > len_di) && !(params->minus))
	{
		if (!(params->zero))
			len = ft_print_width(params->width - len_di, 0);
		else
			len = ft_print_width(params->width - len_di, 1);
	}
	write (1, str, len_di);
	if (params->width > len_di && params->minus)
		len += ft_print_width(params->width - len_di, 0);
	return (len);
}

int	ft_pos_have_precision(t_params *params, int len_di, char *str)
{
	int	len;

	len = 0;
	if ((params->width > params->precision) && !(params->minus))
	{
		if (params->precision > len_di)
			len += ft_print_width(params->width - params->precision, 0);
		else if (params->width > len_di)
			len += ft_print_width(params->width - len_di, 0);
	}
	if (params->precision > len_di)
		len += ft_print_width(params->precision - len_di, 1);
	write(1, str, len_di);
	if ((params->width > params->precision) && params->minus)
	{
		if (params->precision > len_di)
			len += ft_print_width(params->width - params->precision, 0);
		else if (params->width > len_di)
			len += ft_print_width(params->width - len_di, 0);
	}
	return (len);
}
