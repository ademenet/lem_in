# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/30 16:59:27 by ademenet          #+#    #+#              #
#    Updated: 2016/05/30 17:28:02 by ademenet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -Iinclude

NAME = push_swap

SRC_PATH = ./src
INC_PATH = ./inc
OBJ_PATH = ./obj

SRC_NAME =	main.c\

INC_NAME = lem_in.h

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	@make -C libft
	@$(CC) -o $@ $^ ft_printf/libftprintf.a
	@echo "\033[1;34mLem_in\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -c -o $@ $<

clean:
	@make clean -C libft
	@rm -rf ./obj correctme.sh
	@echo "\033[1;34mLem_in\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@echo "\033[1;34mLem_in\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

norme:
	@norminette */*[hc]
	@echo "\033[1;34mLem_in\t\033[1;33mNorme\t\033[0;32m[OK]\033[0m"
