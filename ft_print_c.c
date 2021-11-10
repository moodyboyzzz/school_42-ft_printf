#include "libftprintf.h"

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