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

INCLUDES = -I$(HDR_DIR) -I$(CLASS_DIR)$(HDR_DIR) -I$(GNL_DIR) -I./libs/libft/ -I./libs/minilibx
FLAGS = $(INCLUDES) -D BUFFER_SIZE=50 -Wall -Wextra -Werror -Wfloat-equal -O2

GNL_DIR = libs/get_next_line/
GNL_FILES = $(addprefix $(GNL_DIR), get_next_line get_next_line_utils)
GNL_FILES.O = $(addprefix $(OBJ_DIR), $(GNL_FILES:=.o))

EXIT_DIR = exit/
EXIT_FILES = $(addprefix $(EXIT_DIR)ft_, exit exit_invalid_descriptor exit_invalid_input exit_memerror exit_window_error )
EXIT_FILES.O = $(addprefix $(OBJ_DIR), $(EXIT_FILES:=.o))

CLASS_DIR = classes/
CLASS_BASIC_FOO =	$(addprefix basic_functions/,	ft_next check_color check_coordinates check_float check_int check_vector ft_float_between)
CLASS_AMBIENT =		$(addprefix ambient/,			del_ambient new_ambient ambient_is_valid)
CLASS_CAMERA =		$(addprefix camera/,			del_camera new_camera camera_is_valid)
CLASS_CYLINDER =	$(addprefix cylinder/,			del_cylinder new_cylinder cylinder_is_valid)
CLASS_LIGHT =		$(addprefix light/,				del_light new_light light_is_valid)
CLASS_PLANE =		$(addprefix plane/,				del_plane new_plane plane_is_valid)
CLASS_RESOLUTION =	$(addprefix resolution/,		del_resolution new_resolution resolution_is_valid)
CLASS_SCENE =		$(addprefix scene/,				del_scene new_scene)
CLASS_SPHERE =		$(addprefix sphere/,			del_sphere new_sphere sphere_is_valid)
CLASS_SQUARE =		$(addprefix square/,			del_square new_square square_is_valid)
CLASS_TRIANGLE =	$(addprefix triangle/,			del_triangle new_triangle triangle_is_valid)
CLASS_FILES = $(addprefix $(CLASS_DIR), $(CLASS_BASIC_FOO)	$(CLASS_AMBIENT)	$(CLASS_CAMERA) \
										$(CLASS_CYLINDER)	$(CLASS_LIGHT)		$(CLASS_PLANE) \
										$(CLASS_RESOLUTION)	$(CLASS_SCENE)		$(CLASS_SPHERE) \
										$(CLASS_SQUARE)		$(CLASS_TRIANGLE) )
CLASS_FILES.O = $(addprefix $(OBJ_DIR), $(CLASS_FILES:=.o))

MAIN_FILES = minirt
MAIN_FILES.O = $(addprefix $(OBJ_DIR), $(MAIN_FILES:=.o))

PARSER_DIR = parser/
PARSER_FILES = $(addprefix $(PARSER_DIR), parser )
PARSER_FILES.O = $(addprefix $(OBJ_DIR), $(PARSER_FILES:=.o))


RENDER_DIR = render/
RENDER_FILES = $(addprefix $(RENDER_DIR), render )
RENDER_FILES.O = $(addprefix $(OBJ_DIR), $(RENDER_FILES:=.o))

#TODO: добавить флаг -MD для контроля хедеров
.PHONY: all
all: $(OBJ_DIR) lft lx $(NAME)
	@echo -e "\n\e[32m[+] $(NAME) is assembled!\e[0m"

$(OBJ_DIR):
	@mkdir -p	$(OBJ_DIR)/$(GNL_DIR) $(OBJ_DIR)/$(EXIT_DIR) \
				$(OBJ_DIR)/$(PARSER_DIR) $(OBJ_DIR)/$(RENDER_DIR)
	@mkdir -p $(OBJ_DIR)/$(CLASS_DIR)/basic_functions/
	@mkdir -p $(OBJ_DIR)/$(CLASS_DIR)/ambient/
	@mkdir -p $(OBJ_DIR)/$(CLASS_DIR)/camera/
	@mkdir -p $(OBJ_DIR)/$(CLASS_DIR)/cylinder/
	@mkdir -p $(OBJ_DIR)/$(CLASS_DIR)/light/
	@mkdir -p $(OBJ_DIR)/$(CLASS_DIR)/plane/
	@mkdir -p $(OBJ_DIR)/$(CLASS_DIR)/resolution/
	@mkdir -p $(OBJ_DIR)/$(CLASS_DIR)/scene/
	@mkdir -p $(OBJ_DIR)/$(CLASS_DIR)/sphere/
	@mkdir -p $(OBJ_DIR)/$(CLASS_DIR)/square/
	@mkdir -p $(OBJ_DIR)/$(CLASS_DIR)/triangle/

.PHONY: lft
lft:
	@$(MAKE) -s ./libs/libft
	@echo -e "\e[32m[+] Libft is assembled!\e[0m"

.PHONY: lx
lx:
	@$(MAKE) -s ./libs/minilibx

$(NAME): $(GNL_FILES.O) $(EXIT_FILES.O) $(CLASS_FILES.O) $(PARSER_FILES.O) $(RENDER_FILES.O) $(MAIN_FILES.O)
	@echo -e "\e[34m[ END ]\e[0m"
	$(CC) $(FLAGS)	$(GNL_FILES.O) $(EXIT_FILES.O) $(CLASS_FILES.O) \
					$(PARSER_FILES.O) $(RENDER_FILES.O) $(MAIN_FILES.O) \
					-L./libs/libft -lft -L./libs/minilibx -lmlx \
					-L/usr/include/../lib -lXext -lX11 -lm -lbsd -o $(NAME)

$(GNL_FILES.O): $(OBJ_DIR)%.o: %.c
	@echo -e "\e[32m[ GNL ]\e[0m"
	$(CC) $(FLAGS) -c $< -o $@

$(EXIT_FILES.O): $(OBJ_DIR)%.o: %.c
	@echo -e "\e[32m[ EXIT ]\e[0m"
	$(CC) $(FLAGS) -c $< -o $@

$(CLASS_FILES.O): $(OBJ_DIR)%.o: %.c
	@echo -e "\e[32m[ CLASSES ]\e[0m"
	$(CC) $(FLAGS) -c $< -o $@

$(PARSER_FILES.O): $(OBJ_DIR)%.o: %.c
	@echo -e "\e[32m[ PARSER ]\e[0m"
	$(CC) $(FLAGS) -c $< -o $@

$(RENDER_FILES.O): $(OBJ_DIR)%.o: %.c
	@echo -e "\e[32m[ RENDER ]\e[0m"
	$(CC) $(FLAGS) -c $< -o $@

$(MAIN_FILES.O): $(OBJ_DIR)%.o: %.c
	@echo -e "\e[32m[ MAIN ]\e[0m"
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: te
te: all
	./$(NAME) test.rt

.PHONY: va
va: all
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes --vgdb=no ./$(NAME) test_mini.rt
