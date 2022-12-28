# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 07:30:46 by edvicair          #+#    #+#              #
#    Updated: 2022/11/30 04:53:48 by motaouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CFLAGS = -Wall -Wextra -Werror -g
RL = -lreadline
INC = minishell.h
SRC = Libft/ft_lstclear.c Libft/ft_lstdelone.c Libft/ft_atoi.c minishell.c lib.c split_space.c split.c INIT/init_env.c INIT/init_tok.c Built/cd.c Built/pwd.c Built/export.c Built/export_sort.c Built/env.c Built/unset.c Built/echo.c Built/exit.c ft_free.c parsing/parsing.c parsing/tokenizator.c parsing/utils_parsing.c parsing/utils_parsing2.c parsing/syntax.c
OBJ=$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(RL) #-fsanitize=address
	
%.o: %.c
	gcc -g -o $@ -c $< 

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all
