NAME	= libftprintf.a

SDIR	= src
ODIR	= obj
DIR_L	= libft

SRCS	= ft_printf.c ft_printf_utils.c

SRCS_L	= ft_strlen.c ft_strchr.c ft_atoi.c ft_isdigit.c ft_tolower.c \
		  ft_strdup.c ft_itoa.c ft_putnbr_base.c ft_uitoa.c ft_atoui.c \
		  ft_hexlen.c ft_chartostr.c ft_putnbr_hex.c

OBJS	= ${addprefix ${ODIR}/, ${SRCS:.c=.o}}

OBJS_L	= ${addprefix ${DIR_L}/, ${SRCS_L:.c=.o}}

GCC		= gcc
RM		= rm -f
MAKELIB	= ar rc

LIBFT	= libft.a

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

${ODIR}/%.o:	${SDIR}/%.c
	${GCC} ${CFLAGS} -c $< -o $@


${LIBFT}:
	make re -C ${DIR_L}

${NAME}:	${LIBFT} ${OBJS} ${OBJS_L}
	${MAKELIB} ${NAME} ${OBJS} ${OBJS_L}

bonus:	${NAME}

clean:
	${RM} ${OBJS}
	make clean -C ${DIR_L}

fclean:
	${RM} ${NAME}
	${RM} ${OBJS}
	make fclean -C ${DIR_L}

re:	fclean all

.PHONY: bonus all clean fclean re
