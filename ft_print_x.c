#include "libftprintf.h"

int	ft_len_x(unsigned long num)
{
	int	len;

	len = 0;
	if (!num)
		return (1);
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*ft_itoa_x(unsigned long num, int len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);

}

int	ft_print_x(t_params *params, unsigned int x)
{
	int				len;
	int				len_x;
	char			*str_x;
	unsigned long	num;

	len = 0;
	len_x = 0;
	if (params->precision == 0 && x == 0)
	{
		len += ft_print_width(params->width, 0);
		return (len);
	}
	num = (unsigned long) x;
	len_x = ft_len_x(num);
	str_x = ft_itoa_x(num, len_x);
}
