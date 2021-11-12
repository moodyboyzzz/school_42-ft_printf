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

int	ft_pos_or_neg(int num, t_params *params, char *str, int len_di)
{
	char	c;

	if ((params->pos_or_neg == 1 && !params->space) || (params->pos_or_neg == 1
			&& !params->plus))
	{
		if (params->precision < 0)
			len = ft_pos_none_precision(params, len_di, str);
		else
			len = ft_pos_have_precision(params, len_di, str);
	}
	else
	{
		if (params->pos_or_neg == -1)
			c = '-';
		else if (params->plus)
			c = '+';
		else
			c = ' ';
		if (params->precision < 0)
			len = ft_mps_none_precision(params, len_di, str, c);
		else
			len = ft_mps_have_precision(params, len_di, str, c);
	}
	return (len);
}

int	ft_print_di(t_params *params, int num)
{
	char			*str;
	int				len;
	int				len_di;

	len = 0;
	len_di = 0;
	num_u = 0;
	if (params->precision == 0 && num == 0)
	{
		len = ft_print_width(params->width, 0);
		return (len);
	}
	if (num < 0)
	{
		num *= -1;
		params->pos_or_neg = -1;
	}
	str = ft_itoa(num);
	len_di = ft_strlen(str);
	len = ft_pos_or_neg(num, params, str, len_di);
	free(str);
	return (len + len_di);
}
