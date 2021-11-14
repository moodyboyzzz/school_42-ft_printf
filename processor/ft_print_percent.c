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

#include "../includes/libftprintf.h"

int	ft_print_percent(t_params *params)
{
	int	len;

	len = 0;
	if (params->minus)
	{
		write(1, "%", 1);
		len++;
	}
	while (params->width--)
	{
		if (params->zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		len++;
	}
	if (!params->minus)
		write(1, "%", 1);
	return (len);
}