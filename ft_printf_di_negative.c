#include "libftprintf.h"

int	ft_neg_none_precision(t_params *params, int len_di, char *str)
{
	int	len;

	len = 0;
	if ((params->width > len_di + 1) && !(params->minus))
	{
		if (!(params->zero))
		{
			len += ft_print_width(params->width - len_di - 1, 0);
			ft_putchar_fd('-', 1);
		}
		else
		{
			ft_putchar_fd('-', 1);
			len += ft_print_width(params->width - len_di - 1, 1);
		}
		write (1, str, len_di);
	}
	else
	{
		ft_putchar_fd('-', 1);
		write (1, str, len_di);
		if ((params->width > len_di + 1) && params->minus)
			len += ft_print_width(params->width - len_di - 1, 0);
	}
	return (len + 1);
}

int	ft_neg_have_precision(t_params *params, int len_di, char *str)
{
	int	len;

	len = 0;
	if ((params->width > params->precision) && !(params->minus))
	{
		if (params->precision > len_di + 1)
			len += ft_print_width(params->width - params->precision - 1, 0);
		else if (params->width > len_di + 1)
			len += ft_print_width(params->width - len_di - 1, 0);
	}
	ft_putchar_fd('-', 1);
	if (params->precision > len_di)
		len += ft_print_width(params->precision - len_di, 1);
	write (1, str, len_di);
	if ((params->width > params->precision) && params->minus)
	{
		if (params->precision > len_di + 1)
			len += ft_print_width(params->width - params->precision, 0);
		else if (params->width > len_di + 1)
			len += ft_print_width(params->width - len_di - 1, 0);
	}
	return (len + 1);
}

int	ft_negative(int num, t_params *params)
{
	char			*str;
	int				len_di;
	int				len;
	unsigned int	m;

	len = 0;
	len_di = 0;
	m = (unsigned int) - n;
	str = ft_itoa(m);
	len_di = ft_strlen(str);
	if (params->precision < 0)
		len = ft_neg_none_precision(params, len_di, str);
	else
		len = ft_neg_have_precision(params, len_di, str);
	free(str);
	return (len + len_di);
}
123