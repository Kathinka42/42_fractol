# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kczichowsky <kczichowsky@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 14:15:23 by kczichow          #+#    #+#              #
#    Updated: 2023/01/16 21:08:53 by kczichowsky      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fractol
#OS 			= $(shell uname)
 
# path to directories
SRCS_D		= srcs
OBJS_D		= obj
INC_D		= includes

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
CC			= gcc -Ofast
CFLAGS		= #-Wall -Wextra -Werror

#-fsanitize=address
ifdef DEBUGG
	CFLAGS +=  -g
else
	CFLAGS	+=  -D NDEBUG
endif

# Libft lib
LIBFT_D		= libft
LIBFT_LIB	= $(LIBFT_D)/libft.a
LIBFT_INC 	= -I $(LIBFT_D)
LIBFT_LNK	= -L $(LIBFT_D) -l ft


# GLFW lib
INST_GLFW	= /Users/$(USER)/.brew/opt/glfw/lib/
INST_BREW 	= /Users/$(USER)/.brewconfig.zsh
GLFW_LIB	= -lglfw

# -I option searches directories for #include directives
#INC_F		= -Iincludes

# -l specifies which lib to search
# -lglfw searches the library glfw
# -L specifies additional directories to be searched for libraries (where)

# MLX lib
MLX_D		= MLX42
MLX_LIB		= $(MLX_D)/libmlx42.a
MLX_INC 	= -I $(MLX_D)
MLX_LNK		= -l mlx42 -L $(MLX_D) $(GLFW_LIB) -L $(INST_GLFW)\
    -framework Cocoa -framework OpenGL -framework IOKit

all:		$(NAME)

#dynamic rule to make sure Makefile does not relink

$(NAME):  $(INST_BREW) $(MLX_LIB) $(INST_GLFW) $(LIBFT_LIB) $(OBJS_D) $(SRCS_O)
	 	$(CC) -o $(NAME) $(SRCS_O) $(MLX_LNK) $(LIBFT_LNK)
		  	
#compiles c files to o files, is called by $(SRCS_O)
$(OBJS_D)/%.o: $(SRCS_D)/%.c
			@echo "$(CYAN)compiling: $(RESET) $<"
			@$(CC) $(CFLAGS) $(MLX_INC) $(LIBFT_INC) -I $(INC_D) -c $< -o $@

$(MLX_D):
	@echo "$(RED) CLONING MLX 42 $(RESET)"
	git clone https://github.com/codam-coding-college/MLX42.git
	
$(INST_GLFW):
	@echo "$(MAGENTA) INSTALLING GLFW $(RESET)"
	brew update
	brew install glfw
#	git submodule update --init --recursive --remote && \
	curl -LO https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.MACOS.zip && \
	unzip glfw-3.3.8.bin.MACOS.zip && \
    rm glfw-3.3.8.bin.MACOS.zip && \
	mv glfw-3.3.8.bin.MACOS/lib-universal glfw-3.3.8.bin.MACOS/glfw_lib && \
	mv glfw-3.3.8.bin.MACOS/glfw_lib ./MLX42/ && \
	mv glfw-3.3.8.bin.MACOS/include/GLFW ./MLX42/include && \
	rm -rf glfw-3.3.8.bin.MACOS && \
	echo "$(GREEN)./MLX42/glfw_lib is installed.$(DEF_COLOR)"; \
	fi

$(INST_BREW):
	@echo "$(MAGENTA) INSTALLING BREW $(RESET)"
	@curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	@source ~/.zshrc
		brew analytics off

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