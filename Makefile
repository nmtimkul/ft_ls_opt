# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakefilE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/07 09:02:22 by nmtimkul          #+#    #+#              #
#    Updated: 2017/07/07 09:12:07 by nmtimkul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FILES = ft_ls.c lists.c utils.c options.c

HEADER = ft_ls.h

OBJECTS = $(FILES:.c=.o)

FLAG = -Wall -Wextra -Werror

LIB = libft/libft.a

all: fclean lib
	@gcc -c -g $(FILES)
	@gcc $(FLAG) -g -o ls $(OBJECTS) $(LIB)

test:
	@gcc -c $(FILES)

lib:
	@make -C libft/ re

clean:
	@/bin/rm -f $(OBJECTS)
	@make -C libft/ clean

fclean: clean
	@rm -f ls
	@make -C libft/ fclean

re: fclean all
