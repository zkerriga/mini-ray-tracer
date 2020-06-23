# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/17 11:20:16 by zkerriga          #+#    #+#              #
#    Updated: 2020/06/17 11:24:47 by zkerriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

OBJ_DIR = bin/
HDR_DIR = includes/

CC = gcc
FLAGS = -I$(HDR_DIR) -Wall -Wextra -Werror -D BUFFER_SIZE=50
LIBS_FLAGS = -L. -lmlx -lft

EXIT_DIR = exit/
EXIT_FILES = $(addprefix $(EXIT_DIR)ft_, exit exit_invalid_descriptor exit_invalid_input exit_memerror)
EXIT_FILES.O = $(addprefix $(OBJ_DIR), $(EXIT_FILES:=.o))



FILES.O =

.PHONY: all
all: $(OBJ_DIR) lft lx $(NAME)
	@echo "\n\e[32m[+] $(NAME) is assembled!\e[0m"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

.PHONY: lft
lft:
	$(MAKE) -C ./libs/libft
	cp ./libs/libft/libft.a .

.PHONY: lx
lx:
	$(MAKE) -C ./libs/minilibx

$(NAME): $(FILES.O)
	$(CC) $(FLAGS) $? $(LIBS_FLAGS)

#
#TRE_DIR = tree/
#TRE_FILES = $(addprefix $(TRE_DIR)ft_, leafadd leaffind leafnew treeclear treeinorder treepostorder treepreorder)
#
#FILES = $(IS_FILES) $(MEM_FILES) $(NBR_FILES) $(PUT_FILES) $(STR_FILES) $(LST_FILES) $(TRE_FILES)
#FILES.O = $(addprefix $(OBJ_DIR), $(FILES:=.o))
#
#$(FILES.O): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEAD)
#	$(CC) $(FLAGS) -c $< -o $@
