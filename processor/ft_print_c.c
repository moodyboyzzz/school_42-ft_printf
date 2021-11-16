/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:56 by ctommy            #+#    #+#             */
/*   Updated: 2021/11/14 14:16:57 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_c(t_params	*params, char c)
{
	int	len;

	len = 0;
	if (params->minus)
		ft_putchar_fd(c, 1);
	if (params->zero)
		len += ft_print_width(params->width - 1, 1);
	else
		len += ft_print_width(params->width - 1, 0);
	if (!params->minus)
		ft_putchar_fd(c, 1);
	return (len + 1);
}
