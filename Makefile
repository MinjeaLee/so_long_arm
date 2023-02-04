# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 05:59:46 by mi                #+#    #+#              #
#    Updated: 2023/02/05 01:41:25 by mi               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = #-Wall -Wextra -Werror

LIBFT_DIR = ./libft/

SRCS = main.c map.c render.c

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

# $(NAME) : $(OBJS)
# 	@make -C $(LIBFT_DIR)
# 	@cp $(LIBFT_DIR)libft.a $(NAME)
# 	@ar rcus $(NAME) $^

$(NAME) : $(OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -L./libft -lft -L./mlx_arm -lmlx -framework OpenGL -framework AppKit -lz -o $(NAME) $^
	
%.o : %.c
	@$(CC) $(CFLAGS) -c -Imlx $< -o $@

clean :
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)
	
fclean : clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	
re : fclean all

.PHONY : all clean fclean re