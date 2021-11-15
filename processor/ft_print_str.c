/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:43 by ctommy            #+#    #+#             */
/*   Updated: 2021/11/14 14:16:44 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_str(t_params *params, char *str)
{
	int	len;
	int	len_str;

	len = 0;
	if (!str)
		str = "(null)";
	len_str = (int)ft_strlen(str);
	if ((params->precision >= 0) && (len_str > params->precision))
		len_str = params->precision;
	if (params->minus)
		write(1, str, len_str);
	if (params->width > len_str)
	{
		params->width = params->width - len_str;
		while (params->width--)
		{
			ft_putchar_fd(' ', 1);
			len++;
		}
	}
	if (!params->minus)
		write(1, str, len_str);
	return (len + len_str);
}
