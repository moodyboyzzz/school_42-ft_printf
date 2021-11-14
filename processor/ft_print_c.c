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

#include "../includes/libftprintf.h"

int	ft_print_c(t_params	*params, char c)
{
	int	len;

	len = 0;
	if (params->minus)
		ft_putchar_fd(c, 1);
	while (--params->width)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	if (!params->minus)
		ft_putchar_fd(c, 1);
	return (len + 1);
}