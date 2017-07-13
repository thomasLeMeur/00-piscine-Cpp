# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 10:38:03 by tle-meur          #+#    #+#              #
#    Updated: 2017/01/09 14:54:26 by tle-meur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	crazy_phonebook

CC		=	clang++

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.cpp Contact.cpp Phonebook.cpp

INCS	=	.

LIBS	=	

OBJS	=	$(SRCS:.cpp=.o)

all		:	$(NAME)

%.o		:	%.c
			@$(CC) $(FLAGS) -o $@ -c $< -I $(INCS)

$(NAME)	:	$(OBJS)
			@$(CC) $(FLAGS) -o $@ $^ -L $(INCS) $(LIBS)
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
