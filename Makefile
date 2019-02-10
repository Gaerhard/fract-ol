# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 15:24:01 by gaerhard          #+#    #+#              #
#    Updated: 2019/02/10 13:07:38 by gaerhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC_DIR = srcs/
RAW = main.c events.c init_fracts.c zoom.c mandelbrot.c julia.c utils.c \
	  burning_ship.c events2.c mandel2.c
SRC = $(addprefix $(SRC_DIR), $(RAW))
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a
INCLUDES = includes
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES) -O3 -flto
DEBUG = -g3 -fsanitize=address
MLXFLAGS = -lmlx -framework OPENgL -framework AppKit
RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
RESET :="\033[0m"

all: lib $(NAME)

$(NAME): $(OBJ) $(LIB)
	@gcc $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo ${GREEN}"[INFO] Compiled [$(NAME)] executable successfully!"${RESET}

clean: 
	@make clean -C libft
	@rm -Rf $(OBJ)
	@echo ${CYAN}"[INFO] Removed [$(OBJ)] successfully!"${RESET}

fclean: clean fclean_lib
	@rm -Rf $(NAME)
	@echo ${CYAN}"[INFO] Removed everything"${RESET}

re: fclean all

lib:
	@make -C libft

relib:
	@make re -C libft

fclean_lib:
	@make fclean -C libft

debug: lib $(OBJ) $(LIB)
	@gcc $(CFLAGS) $(DEBUG) $(MLXFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo ${GREEN}"[INFO] Compiled [$(NAME)] executable successfully!"${RESET}

.SILENT: $(OBJ) $(LIB)
.PHONY: fclean all clean lib relib fclean_lib debug
