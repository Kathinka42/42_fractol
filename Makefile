# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 14:15:23 by kczichow          #+#    #+#              #
#    Updated: 2023/01/16 11:40:05 by kczichow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fractol
#OS 			= $(shell uname)
 
# path to directories
SRCS_D		= ./srcs
OBJS_D		= ./obj
INC_D		= ./includes

# color codes for command line messages

BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

# source and objects files

SRCS_F		= main.c \
			  check_input.c \
			  param_is_valid.c \
			  allocate_memory.c \
			  init_set.c \
			  print_instructions.c \
			  draw_fractal.c \
			  select_color.c \
			  get_rgba.c \
			  mandelbrot.c \
			  fractol.c \
			  temp_drawing_experiments.c \
			  zoom.c \
			  keyhook.c \
			  clean_up.c \
			  julia.c \
			  ft_atof.c
			  
SRCS_O		= $(addprefix $(OBJS_D)/, $(SRCS_F:%.c=%.o))

# compilation rules and flags
CC			= gcc
CFLAGS		= #-Wall -Wextra -Werror
ifdef DEBUG
	CFLAGS += -fsanitize=address -g
else
	CFLAGS	+= -Ofast -D NDEBUG
endif

# Libft lib
LIBFT_D		= ./libft
LIBFT_LIB	= $(LIBFT_D)/libft.a
LIBFT_INC 	= -I $(LIBFT_D)
LIBFT_LNK	= -L $(LIBFT_D) -l ft


# GLFW lib
GLFW_D	= /Users/$(USER)/.brew/opt/glfw/lib/
BREW_FILE 	= /Users/$(USER)/.brewconfig.zsh
GLFW_LIB	= -lglfw

# -I option searches directories for #include directives
#INC_F		= -Iincludes

# -l specifies which lib to search
# -lglfw searches the library glfw
# -L specifies additional directories to be searched for libraries (where)

# MLX lib
MLX_D		= ./MLX42
#MLX_D		= git clone https://github.com/codam-coding-college/MLX42.git ./MLX42
MLX_LIB		= $(MLX_D)/libmlx42.a
MLX_INC 	= -I $(MLX_D)
#MLX_LNK		= -L $(MLX_D) -l mlx42 -lglfw -L ~/.brew/opt/glfw/lib\
    -framework Cocoa -framework OpenGL -framework IOKit
MLX_LNK		= -l mlx42 -L $(MLX_D) $(GLFW_LIB) -L $(GLFW_D)\
    -framework Cocoa -framework OpenGL -framework IOKit

all:		$(NAME)

#dynamic rule to make sure Makefile does not relink

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS_D) $(SRCS_O) $(GLFW_D)
	 	$(CC) -o $(NAME) $(SRCS_O) $(MLX_LNK) $(LIBFT_LNK)
		  	
#compiles c files to o files, is called by $(SRCS_O)
$(OBJS_D)/%.o: $(SRCS_D)/%.c
			@echo "$(CYAN)compiling: $(RESET) $<"
			@$(CC) $(CFLAGS) $(MLX_INC) $(LIBFT_INC) -I $(INC_D) -c $< -o $@

#-----------------------------
#$(MLX42):
#	@echo "$(MAGENTA) ----- CLONING MLX42 ----- $(RESET)"
#	git clone https://github.com/codam-coding-college/MLX42.git

$(GLFW_D):
	@if [ -d ./MLX42/glfw_lib ]; \
	then echo "$(GREEN)./MLX42/glfw_lib Exists, no further action required.$(DEF_COLOR)"; \
	else \
	echo "$(RED)./MLX42/glfw_lib Doesn't exists.$(DEF_COLOR)"; \
	@echo "$(MAGENTA) ----- INSTALLING GLFW ----- $(RESET)"
	brew install glfw

$(BREW_FILE):
	@echo "$(MAGENTA) ----- INSTALLING BREW ----- $(RESET)"
	@curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	@source ~/.zshrc
#-------------------------------
	

# -j option for multithreading
$(LIBFT_LIB):
	make -j -C $(LIBFT_D)

# -j option for multithreading
$(MLX_LIB):
	make -j -C $(MLX_D)

$(OBJS_D):
	mkdir $@

clean:
	rm -rf $(OBJS_D)
	make clean -C $(LIBFT_D)
	make clean -C $(MLX_D)

fclean: clean
	rm -f $(NAME) 
	make fclean -C $(LIBFT_D)
	make fclean -C $(MLX_D)
	
re: fclean all

.PHONY: all clean fclean re