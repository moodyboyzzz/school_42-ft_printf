#include "libftprintf.h"

int	ft_print_width(int width, int zero)
{
	int	len;

	len = 0;
	while (width--)
	{
		if (zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		len++;
	}
	return (len);
}

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

int	ft_positive(int num, t_params *params)
{
	char	*str;
	int		len;
	int		len_di;

	len = 0;
	len_di = 0;
	if (params->precision == 0 && num == 0)
	{
		while (params->width--)
		{
			ft_putchar_fd(' ', 1);
			len++;
		}
		return (len);
	}
	if (num < 0)
		num *= -1;
	str = ft_itoa(num);
	len_di = ft_strlen(str);
	if (num > 0)
	{
		if (params->precision < 0)
			len = ft_pos_none_precision(params, len_di, str);
		else
			len = ft_pos_have_precision(params, len_di, str);
	}
	else
	{
		if (params->precision < 0)
			len = ft_neg_none_precision(params, len_di, str);
		else
			len = ft_neg_have_precision(params, len_di, str);
	}
	free(str);
	return (len + len_di);
}

int	ft_print_di(t_params *params, int num)
{
	int	len;

	len = 0;
	if (num >= 0)
		len = ft_positive(num, params);
	else
		len = ft_negative(num, params);
	return (len);
}