#include "libftprintf.h"

t_params	ft_init(void)
{
	t_params	params;

	params.minus = 0;
	params.plus = 0;
	params.zero = 0;
	params.space = 0;
	params.sharp = 0;
	params.width = 0;
	params.precision = -1;
	params.type = 0;
	params.pos_or_neg = 1;
	return (params);
}

int	ft_parse_flags(int	*i, t_params *params, const char *format)
{
	while (format[*i] == '-' || format[*i] == '+' || format[*i] == '0'
		|| format[*i] == ' ' || format[*i] == '#')
	{
		if (format[*i] == '-')
			params->minus = 1;
		else if (format[*i] == '+')
			params->plus = 1;
		else if (format[*i] == '0')
			params->zero = 1;
		else if (format[*i] == ' ')
			params->space = 1;
		else if (format[*i] == '#')
			params->sharp = 1;
		(*i)++;
	}
	if (flags->minus == 1)
		flags->zero = 0;
	if (flags->plus == 1)
		flags->space = 0;
	return (*i);
}

int	ft_parse_width(va_list ap, int	*i, t_params *params, const char *format)
{
	if (format[*i] == '*')
	{
		params->width = va_arg(ap, int);
		if (params->width < 0)
		{
			params->minus = 1;
			params->width *= -1;
		}
	}
	while (ft_isdigit(params->width))
	{
		params->width = (params->width * 10) + (format [*i] - '0');
		(*i)++;
	}
	return (*i);
}

int	ft_parse_precision(va_list ap, int	*i, t_params *params,
const char *format)
{
	if (format [*i] == '.')
	{
		(*i)++;
		if (format[*i] == '*')
			params->precision = va_arg(ap, int);
		(*i)++;
		while (ft_isdigit(format[*i]))
		{
			params->precision = (params->precision * 10) + (format [*i] - '0');
			(*i)++;
		}
		if (params->precision < 0)
			params->precision = -1;
	}
	return (*i);
}
