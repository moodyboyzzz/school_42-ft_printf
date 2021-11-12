#include "libftprintf.h"

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
			number[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (number);
	}
	return (NULL);
}

char	*ft_unsigned_itoa(unsigned int n)
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
	len_ui = 0;
	if ((params->precision == 0) && (num == 0))
	{
		len = ft_print_width(params->width, 0);
		return (len);
	}
	ui = ft_unsigned_itoa(num);
	len_ui = ft_strlen(ui);
	if (params->precision < 0)
		ft_pos_none_precision(params, len_ui, ui);
	else
		ft_pos_have_precision(params, len_ui, ui);
	free (ui);
	return (len + len_ui);