# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 10:38:03 by tle-meur          #+#    #+#              #
#    Updated: 2017/01/09 11:00:57 by tle-meur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone

CC		=	clang++

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	megaphone.cpp

OBJS	=	$(SRCS:.cpp=.o)

all		:	$(NAME)

%.o		:	%.c
			@$(CC) $(FLAGS) -o $@ -c $<

$(NAME)	:	$(OBJS)
			@$(CC) $(FLAGS) -o $@ $^
			@echo "$(NAME) created"

clean	:
			@rm -f $(OBJS)
			@echo "objects deleted"

fclean	:	clean
			@rm -f $(NAME)
			@echo "$(NAME) deleted"

re		:	fclean $(NAME)

simple	:	re
			@rm -f $(OBJS)
			@echo "objects deleted"

.PHONY	:	all clean fclean re simple
