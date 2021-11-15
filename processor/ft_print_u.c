/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:40 by ctommy            #+#    #+#             */
/*   Updated: 2021/11/14 14:16:41 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_plus_int(unsigned int n, int len)
{
	char	*number;

	number = (char *)malloc(sizeof(char) * (len + 1));
	if (number)
	{
		number[len] = '\0';
		len--;
		while (len >= 0)
		{
			number[len] = (char)((n % 10) + 48);
			n = n / 10;
			len--;
		}
		return (number);
	}
	return (NULL);
}

static char	*ft_unsigned_itoa(unsigned int n)
{
	int					len;
	unsigned int		num;

	len = 0;
	num = n;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (ft_plus_int(num, len));
}

int	ft_print_u(t_params *params, unsigned int num)
{
	int		len;
	int		len_ui;
	char	*ui;

	len = 0;
	if ((params->precision == 0) && (num == 0))
	{
		len = ft_print_width(params->width, 0);
		return (len);
	}
	ui = ft_unsigned_itoa(num);
	len_ui = (int)ft_strlen(ui);
	if (params->precision < 0)
		len += ft_pos_none_precision(params, len_ui, ui);
	else
		len += ft_pos_have_precision(params, len_ui, ui);
	free(ui);
	return (len + len_ui);
}
