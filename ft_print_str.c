#include "libftprintf.h"

int	ft_print_str(t_params *params, char *str)
{
	int	len;
	int	len_str;

	len = 0;
	len_str = 0;
	if (!str)
		str = "(null)";
	len_str = ft_strlen(str);
	if ((params->precision >= 0) && (len_str > params->precision))
		len_str = params->precision;
	if (params->minus)
		write(1, str, len_str);
	if (params->width > len_str)
	{
		params->width = params->width - len_str;
		while (params->width--)
		{
			ft_putchar_fd(' ', 1);
			len++;
		}
	}
	if (!params->minus)
		write(1, str, len_str);
	return (len + len_str);
}
