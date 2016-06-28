# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/30 16:59:27 by ademenet          #+#    #+#              #
#    Updated: 2016/06/28 15:20:05 by ademenet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all test clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -Iinclude

NAME = lem-in

SRC_PATH = ./src
INC_PATH = ./inc
OBJ_PATH = ./obj

SRC_NAME =	lem_in.c\
			li_error.c\
			li_graph.c\
			li_parsing.c\
			li_paths.c\
			li_room.c\
			li_tube.c\
			li_weight.c

INC_NAME = lem_in.h

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(FLAGS) -o $@ $^ libft/libft.a libft/ft_printf/libftprintf.a
	@echo "\033[1;34mLem-in\t\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

test: $(OBJ)


$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -c -o $@ $<

clean:
	@make clean -C libft
	@rm -rf ./obj correctme.sh
	@echo "\033[1;34mLem-in\t\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@echo "\033[1;34mLem-in\t\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

norme:
	@norminette */*[hc]
	@echo "\033[1;34mLem-in\t\033[1;33mNorme\t\033[0;32m[OK]\033[0m"
