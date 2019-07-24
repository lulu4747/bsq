# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: esouchau <esouchau@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/07/20 16:45:18 by esouchau     #+#   ##    ##    #+#        #
#    Updated: 2019/07/24 14:25:05 by abentoun    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRCS 		= ft_fill_map.c ft_find_square.c ft_get_params.c ft_print_sqr.c

INCLUDE		= libft.h

OBJS 		= ${SRCS:.c=.o}

NAME 		= bsq

CFLAGS 		= -Wall -Werror -Wextra

CC 			= cc

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDE}

all: 		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
