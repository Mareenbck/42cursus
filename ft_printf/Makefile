
   
NAME	= libftprintf.a

SRCS	= ft_printf.c ft_utils.c

OBJS	= ${SRCS:.c=.o}

RM		= rm -f

FLAGS	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:		
				gcc ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				ar rc ${NAME} ${OBJS}

clean:		
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
