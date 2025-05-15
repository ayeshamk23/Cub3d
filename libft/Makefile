# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsalah <hsalah@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 08:11:23 by hsalah            #+#    #+#              #
#    Updated: 2024/10/13 11:45:43 by hsalah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	$(wildcard ./ascii/*.c)				\
			$(wildcard ./mem/*.c)				\
			$(wildcard ./put/*.c)				\
			$(wildcard ./str/*.c)				\
			$(wildcard ./lst/*.c)				\
			$(wildcard ./debug/*.c)				\
			$(wildcard ./read/*.c)

OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)
LIBC	=	ar -rcs
RM		=	rm -f
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
			${LIBC} $(NAME) $(OBJS)

%.o:		%.c libft.h
			$(CC) -c $(FLAGS) $< -o $@

clean:
			${RM} $(OBJS) $(OBJS_B)

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
