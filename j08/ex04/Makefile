# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 10:38:03 by tle-meur          #+#    #+#              #
#    Updated: 2017/01/20 12:04:39 by tle-meur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex04

CC		=	clang++

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.cpp AToken.cpp Num.cpp Div.cpp Mul.cpp Add.cpp Sub.cpp OpenPar.cpp ClosePar.cpp

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
