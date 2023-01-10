# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 14:15:23 by kczichow          #+#    #+#              #
#    Updated: 2023/01/10 15:36:36 by kczichow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fractol
#OS 			= $(shell uname)
 
# path to directories
SRCS_D		= ./srcs
OBJS_D		= ./obj
INC_D		= ./includes

# source and objects files

SRCS_F		= main.c \
			  ft_strncmp.c \
			  check_input.c \
			  param_is_valid.c \
			  allocate_memory.c \
			  init_set.c \
			  count_iterations.c \
			  draw_fractal.c \
			  select_color.c \
			  get_rgba.c \
			  mandelbrot.c \
			  fractol.c \
			  temp_drawing_experiments.c \
			  zoom.c

SRCS_O		= $(addprefix $(OBJS_D)/, $(SRCS_F:%.c=%.o))

# compilation rules and flags
CC			= gcc
#CFLAGS		= -Wall -Wextra -Werror
#CFLAGS		= -fsanitize=address -g

# Libft
LIBFT_D		= ./libft
LIBFT_LIB	= $(LIBFT_D)/libft.a
LIBFT_INC 	= -I $(LIBFT_D)
LIBFT_LNK	= -L $(LIBFT_D) -l ft


# -I option searches directories for #include directives
#INC_F		= -Iincludes

# -lglfw searches the library glfw
# -L specifies additional directories to be searched for libraries (where)
# -l specifies which lib to search

# MLX lib
MLX_D		= ./MLX42
MLX_LIB		= $(MLX_D)/libmlx42.a
MLX_INC 	= -I $(MLX_D)
MLX_LNK		= -L $(MLX_D) -l mlx42 -lglfw -L ~/.brew/opt/glfw/lib\
    -framework Cocoa -framework OpenGL -framework IOKit

RM			= rm -rf

all:		$(NAME)

#dynamic rule to make sure Makefile does not relink

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS_D) $(SRCS_O)
	 	$(CC) -o $(NAME) $(SRCS_O) $(MLX_LNK) $(LIBFT_LNK)
		  	
#compiles c files to o files, is called by $(SRCS_O)
$(OBJS_D)/%.o: $(SRCS_D)/%.c
			$(CC) $(CFLAGS) $(MLX_INC) $(LIBFT_INC) -I $(INC_D) -c $< -o $@

# -j option for multithreading
$(LIBFT_LIB):
	make -j -C $(LIBFT_D)

# -j option for multithreading
$(MLX_LIB):
	make -j -C $(MLX_D)

$(OBJS_D):
	mkdir $@

clean:
	@$(RM) -rf $(OBJS_D)
	make clean -C $(LIBFT_D)
	make clean -C $(MLX_D)

fclean: clean
	$(RM) -f $(NAME) 
	make fclean -C $(LIBFT_D)
	make fclean -C $(MLX_D)
	
re: fclean all

.PHONY: all clean fclean re