# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 13:00:58 by nmtimkul          #+#    #+#              #
#    Updated: 2019/02/02 11:48:00 by nmtimkul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
IDIR = ./include/
INCS = libft.h	\
	   ft_ls.h
INCC = $(addprefix $(IDIR), $(INCS))

LDIR = ./libft
LIBS = -lft

SDIR = ./sources/
SRCS = create_lst.c \
	   ft_ls.c \
	   ft_handlelst.c \
	   ft_print.c \
	   ft_printy.c \
	   ft_slist.c \
	   ft_srev.c \
	   main.c \
	   reset_list.c \

SRCC = $(addprefix $(SDIR),$(SRCS))

ODIR = ./objects/
OBJS = $(SRCS:.c=.o)
OBCC = $(addprefix $(ODIR),$(OBJS))

FLAG = -g -Wall -Werror -Wextra

$(NAME): $(OBCC)
	make -C ./libft/
	gcc $(FLAG) $(OBCC) -L$(LDIR) $(LIBS) -o $(NAME)

$(ODIR)%.o: $(SDIR)%.c
	@mkdir -p $(ODIR)
	gcc $^ $(FLAG) -c -o $@ -I$(IDIR)

all: $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	@make -C ./libft/ clean
	/bin/rm -f $(NAME)

re: fclean all
.PHONY: clean fclean all
