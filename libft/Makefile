SRCS	= ft_strlen.c ft_strchr.c ft_atoi.c ft_isdigit.c ft_tolower.c \
		  ft_strdup.c ft_itoa.c ft_putnbr_base.c ft_uitoa.c ft_atoui.c \
		  ft_hexlen.c ft_chartostr.c ft_putnbr_hex.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

GCC		= gcc
RM		= rm -f
MAKELIB	= ar rc

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${MAKELIB} ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
