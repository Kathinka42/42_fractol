# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 14:15:23 by kczichow          #+#    #+#              #
#    Updated: 2022/11/18 16:50:15 by kczichow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fractol

SRCS_F		= main.c
 
# path to directories
SRCS_D		= ./srcs
OBJS_D		= ./obj
SRCS_O		= $(addprefix $(OBJS_D)/, $(SRCS_F:%.c=%.o))

# -I option searches directories for #include directives
INC_F		= -Iincludes

# compilation rules and flags
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
#CFLAGS		= -fsanitize=address -g

# Libft
LIBFT		= ./libft/libft.a
LIBFT_D		= libft

# -lglfw searches the library glfw
# -L specifies additional directories to be searched
# MLX lib
MLX			= ./MLX42/libmlx42.a -lglfw -L ~/.brew/opt/glfw/lib\
    -framework Cocoa -framework OpenGL -framework IOKit
MLX_D		= ./MLX42

RM			= rm -rf

all:		$(NAME)

$(NAME): $(LIBFT)
	 	gcc $(CFLAGS) -o $(NAME) $(MLX) -I includes -L$(LIBFT_D) -l ft main.c
		  
			

$(OBJS_D)/%.o: $(SRCS_D)/%.c 
			$(CC) $(CFLAGS) $(INC_F) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_D)

# $(MLX):
# 	make -C $(MLX_D)

$(OBJS_D):
	mkdir $@

clean:
	@$(RM) -rf $(OBJS_D)
	make clean -C $(LIBFT_D)
#	make clean -C $(MLX42_D)

fclean:
	clean
	$(RM) -f $(NAME) 
	make fclean -C $(LIBFT_D)
#	make fclean -C $(MLX42_D)
	
re:
	fclean all

.PHONY: all clean fclean re