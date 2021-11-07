#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "Libft/libft.h"
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
}				t_params;

#endif