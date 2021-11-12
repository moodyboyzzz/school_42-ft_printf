#include "libftprintf.h"

int	ft_print_percent(t_params *params)
{
	int	len;

	len = 0;
	if (params->minus)
	{
		write(1, "%", 1);
		len++;
	}
	while (params->width--)
	{
		if (params->zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		len++;
	}
	if (!params->minus)
		write(1, "%", 1);
	return (len);
}