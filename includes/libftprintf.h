/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:27 by ctommy            #+#    #+#             */
/*   Updated: 2021/11/14 14:16:28 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_params
{
	int			minus;
	int			plus;
	int			zero;
	int			space;
	int			sharp;
	int			width;
	int			precision;
	int			type;
	int			pos_or_neg;
	int			flag;
}				t_params;

int			ft_print(t_params *params, va_list ap);
int			ft_parse(va_list ap, int *i, t_params *params, const char *format);
int			ft_reading(va_list ap, const char *format);
int			ft_printf(char *format, ...);

t_params	ft_init(void);
int			ft_parse_flags(int	*i, t_params *params, const char *format);
int			ft_parse_width(va_list ap, int	*i,
				t_params *params, const char *format);
int			ft_parse_precision(va_list ap, int	*i,
				t_params *params, const char *format);

int			ft_print_c(t_params	*params, char c);

int			ft_print_width(int width, int zero);
int			ft_pos_or_neg(int len, t_params *params, char *str, int len_di);
int			ft_print_di(t_params *params, int num);

int			ft_pos_none_precision(t_params *params, int len_di, char *str);
int			ft_pos_have_precision(t_params *params, int len_di, char *str);

int			ft_print_p(t_params *params, unsigned long point);

int			ft_print_percent(t_params *params);

int			ft_print_str(t_params *params, char *str);

int			ft_print_u(t_params *params, unsigned int num);

int			ft_len_x(unsigned long num);
int			ft_sharp_or_no(t_params *params, int len_x, char *str_x, int len);
int			ft_print_x(t_params *params, unsigned int x);

int			ft_mps_none_precision(t_params *params, int len_di,
				char *str, char *c);
int			ft_mps_have_precision(t_params *params, int len_di,
				char *str, char *c);

#endif