/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:46 by ctommy            #+#    #+#             */
/*   Updated: 2021/11/14 14:16:46 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_percent(t_params *params)
{
	int	len;

	len = 0;
	if (params->minus)
	{
		write(1, "%", 1);
		len++;
	}
	if (params->width > len)
	{
		if (params->zero)
			len += ft_print_width(params->width - 1, 1);
		else
			len += ft_print_width(params->width - 1, 0);
	}
	if (!params->minus)
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}
