NAME		=	libftprintf.a

INCLUDES	=	libftprintf.h

SRCS		=	base/ft_printf.c				\
				parser/parse.c					\
				processor/ft_print_c.c			\
				processor/ft_print_di.c			\
				processor/ft_print_di_pos.c		\
				processor/ft_print_p.c			\
				processor/ft_print_percent.c	\
				processor/ft_print_str.c		\
				processor/ft_print_u.c			\
				processor/ft_print_x.c			\
				processor/ft_print_di_mps.c		\
				libft/ft_putchar_fd.c			\
				libft/ft_isdigit.c				\
				libft/ft_strlen.c				\
				libft/ft_itoa.c					\
				libft/ft_strdup.c				\

OBJS		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I

all:  		${NAME}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

.c.o:
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

bonus:		${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:  	clean
			${RM} ${NAME}

re:   		fclean all

.PHONY:  	all clean fclean re bonus