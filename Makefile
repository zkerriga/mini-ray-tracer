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
HEAD = minirt.h

OBJ_DIR = bin/
HDR_DIR = ./

CC = gcc
FLAGS = -I$(HDR_DIR) -Wall -Wextra -Werror -D BUFFER_SIZE=20
LIBS_FLAGS = -L. -lmlx -lft

.PHONY: all
all: $(OBJ_DIR) $(NAME)
	@echo "\n\e[32m[+] $(NAME) is assembled!\e[0m"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

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
