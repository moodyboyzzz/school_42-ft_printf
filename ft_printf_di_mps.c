#include "libftprintf.h"

int	ft_mps_none_precision(t_params *params, int len_di, char *str, char c)
{
	int	len;

	len = 0;
	if ((params->width > len_di + 1) && !(params->minus))
	{
		if (!(params->zero))
		{
			len += ft_print_width(params->width - len_di - 1, 0);
			ft_putchar_fd(c, 1);
		}
		else
		{
			ft_putchar_fd(c, 1);
			len += ft_print_width(params->width - len_di - 1, 1);
		}
		write (1, str, len_di);
	}
	else
	{
		ft_putchar_fd(c, 1);
		write (1, str, len_di);
		if ((params->width > len_di + 1) && params->minus)
			len += ft_print_width(params->width - len_di - 1, 0);
	}
	return (len + 1);
}

int	ft_mps_have_precision(t_params *params, int len_di, char *str, char c)
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
	ft_putchar_fd(c, 1);
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
