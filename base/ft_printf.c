/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:30 by ctommy            #+#    #+#             */
/*   Updated: 2021/11/14 14:16:31 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

int	ft_print(t_params *params, va_list ap)
{
	int	len;

	len = 0;
	if (params->type == 'c')
		len = ft_print_c(params, va_arg(ap, int));
	else if (params->type == 's')
		len = ft_print_str(params, va_arg(ap, char *));
	else if (params->type == 'p')
		len = ft_print_p(params, va_arg(ap, unsigned long));
	else if (params->type == 'd' || params->type == 'i')
		len = ft_print_di(params, va_arg(ap, int));
	else if (params->type == 'u')
		len = ft_print_u(params, va_arg(ap, unsigned int));
	else if (params->type == 'x')
		len = ft_print_x(params, va_arg(ap, unsigned int));
	else if (params->type == 'X')
		len = ft_print_x(params, va_arg(ap, unsigned int));
	else if (params->type == '%')
		len = ft_print_percent(params);
	return (len);
}

int	ft_parse(va_list ap, int *i, t_params *params, const char *format)
{
	*i = ft_parse_flags(i, params, format);
	*i = ft_parse_width(ap, i, params, format);
	*i = ft_parse_precision(ap, i, params, format);
	if (format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p'
		|| format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'u'
		|| format[*i] == 'x' || format[*i] == 'X' || format[*i] == '%')
		params->type = format[(*i)++];
	return (*i);
}

int	ft_reading(va_list ap, const char *format)
{
	t_params	params;
	int			length;
	int			i;

	length = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			params = ft_init();
			i = ft_parse(ap, &i, &params, format);
			length += ft_print(&params, ap);
		}
		else if (format[i])
		{
			ft_putchar_fd(format[i], 1);
			length += 1;
			i++;
		}
	}
	return (length);
}

int	ft_printf(char *format, ...)
{
	va_list	ap;
	int		length;

	length = 0;
	va_start(ap, format);
	length = ft_reading(ap, format);
	va_end(ap);
	return (length);
}
