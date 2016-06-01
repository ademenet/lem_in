#!/bin/sh

gcc -Wall -Wextra -Werror	u-test.c\
							../src/li_parsing.c\
							../libft/libft.a\
							../libft/ft_printf/libftprintf.a\
