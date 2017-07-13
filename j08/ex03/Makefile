# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 10:38:03 by tle-meur          #+#    #+#              #
#    Updated: 2017/01/19 18:26:04 by tle-meur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	mindopen

CC		=	clang++

FLAGS	=	-g -Wall -Wextra -Werror

SRCS	=	main.cpp AMindOpen.cpp IncrVal.cpp IncrPtr.cpp DecrVal.cpp DecrPtr.cpp \
			GetVal.cpp PutVal.cpp

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
