# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 05:59:46 by mi                #+#    #+#              #
#    Updated: 2023/02/01 06:28:24 by mi               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = #-Wall -Wextra -Werror

LIBFT_DIR = ./libft/

SRCS = main.c

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

# $(NAME) : $(OBJS)
# 	@make -C $(LIBFT_DIR)
# 	@cp $(LIBFT_DIR)libft.a $(NAME)
# 	@ar rcus $(NAME) $^

$(NAME) : $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)libft.a ./libft.a
	@$(CC) $(CFLAGS) -llibft -L./mlx_arm -lmlx -framework OpenGL -framework AppKit -lz -o $(NAME) $^
	
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