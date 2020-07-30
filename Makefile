# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/17 11:20:16 by zkerriga          #+#    #+#              #
#    Updated: 2020/07/30 13:29:06 by zkerriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

OBJ_DIR = bin/
HDR_DIR = includes/
SRC_DIR = src/
LIB_DIR = libs/

CC = gcc

INCLUDES =	-I$(HDR_DIR) -I$(SRC_DIR)$(CLASS_DIR)$(HDR_DIR) -I./$(LIB_DIR)libft/ \
			-I./$(LIB_DIR)minilibx -I./$(LIB_DIR)libgraphic_math
FLAGS = $(INCLUDES) -Wall -Wextra -Werror -O2 -MMD

CLASS_DIR = classes/
CLASS_DMLX =		$(addprefix dmlx/,				create_window del_dmlx new_dmlx put_image_to_bmp put_image_to_win )
CLASS_BASIC_FOO =	$(addprefix basic_functions/,	ft_next check_color check_coordinates check_float check_int check_vector ft_float_between)
CLASS_AMBIENT =		$(addprefix ambient/,			del_ambient new_ambient ambient_is_valid)
CLASS_CAMERA =		$(addprefix camera/,			del_camera new_camera camera_is_valid)
CLASS_CYLINDER =	$(addprefix cylinder/,			del_cylinder new_cylinder cylinder_is_valid cy_get_n cy_solve )
CLASS_LIGHT =		$(addprefix light/,				del_light new_light light_is_valid)
CLASS_PLANE =		$(addprefix plane/,				del_plane new_plane plane_is_valid pl_get_n pl_solve )
CLASS_RESOLUTION =	$(addprefix resolution/,		del_resolution new_resolution resolution_is_valid)
CLASS_SCENE =		$(addprefix scene/,				del_scene new_scene get_d get_active_camera )
CLASS_SPHERE =		$(addprefix sphere/,			del_sphere new_sphere sphere_is_valid sp_get_n sp_solve )
CLASS_SQUARE =		$(addprefix square/,			del_square new_square square_is_valid sq_get_n sq_solve )
CLASS_TRIANGLE =	$(addprefix triangle/,			del_triangle new_triangle triangle_is_valid tr_get_n tr_solve )
CLASS_FILES = $(addprefix $(CLASS_DIR), $(CLASS_BASIC_FOO)	$(CLASS_AMBIENT)	$(CLASS_CAMERA) \
										$(CLASS_CYLINDER)	$(CLASS_LIGHT)		$(CLASS_PLANE) \
										$(CLASS_RESOLUTION)	$(CLASS_SCENE)		$(CLASS_SPHERE) \
										$(CLASS_SQUARE)		$(CLASS_TRIANGLE)	$(CLASS_DMLX) )
CLASS_FILES.O = $(addprefix $(OBJ_DIR), $(CLASS_FILES:=.o))

EVENTS_DIR = events/
EVENTS_FILES = $(addprefix $(EVENTS_DIR), close_handler key_handler )
EVENTS_FILES.O = $(addprefix $(OBJ_DIR), $(EVENTS_FILES:=.o))

EXIT_DIR = exit/
EXIT_FILES = $(addprefix $(EXIT_DIR)ft_, exit exit_invalid_descriptor exit_invalid_input exit_memerror exit_window_error )
EXIT_FILES.O = $(addprefix $(OBJ_DIR), $(EXIT_FILES:=.o))

PARSER_DIR = parser/
PARSER_FILES = $(addprefix $(PARSER_DIR), parser match parser_error ft_lstnew_gc ft_dlstnew_gc )
PARSER_FILES.O = $(addprefix $(OBJ_DIR), $(PARSER_FILES:=.o))

RENDER_DIR = render/
RENDER_FILES = $(addprefix $(RENDER_DIR), render color_definition get_diffuse is_shadow_point ray_lim trace_ray )
RENDER_FILES.O = $(addprefix $(OBJ_DIR), $(RENDER_FILES:=.o))

HELP_FILES = show_help
HELP_FILES.O = $(addprefix $(OBJ_DIR), $(HELP_FILES:=.o))

MAIN_FILES = minirt
MAIN_FILES.O = $(addprefix $(OBJ_DIR), $(MAIN_FILES:=.o))

.PHONY: all
all: $(OBJ_DIR) lft lgraphic_math lx $(NAME)
	@echo -e "\n\e[32m[+] $(NAME) is assembled!\e[0m"

$(OBJ_DIR):
	@mkdir -p	$(OBJ_DIR)/$(EXIT_DIR) $(OBJ_DIR)/$(EVENTS_DIR) \
				$(OBJ_DIR)/$(PARSER_DIR) $(OBJ_DIR)/$(RENDER_DIR)
	@mkdir -p $(OBJ_DIR)/$(CLASS_DIR)/dmlx/
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
	@$(MAKE) -C ./$(LIB_DIR)libft gnl_buff_size=100 --no-print-directory --silent
	@echo -e "\e[32m[+] Libft is assembled!\e[0m"

.PHONY: lgraphic_math
lgraphic_math:
	@$(MAKE) -C ./$(LIB_DIR)libgraphic_math --no-print-directory --silent
	@echo -e "\e[32m[+] Libgraphic_math is assembled!\e[0m\n"

.PHONY: lx
lx:
	@$(MAKE) -C ./$(LIB_DIR)minilibx --no-print-directory --silent
	@echo -e "\e[32m[+] Minilibx is assembled!\e[0m"

$(NAME): $(CLASS_FILES.O) $(EVENTS_FILES.O) $(EXIT_FILES.O) $(PARSER_FILES.O) $(RENDER_FILES.O) $(HELP_FILES.O) $(MAIN_FILES.O)
	@echo -e "\e[34m[+] END\e[0m"
	@$(CC) $(FLAGS)	$(CLASS_FILES.O) $(EVENTS_FILES.O) $(EXIT_FILES.O) \
					$(PARSER_FILES.O) $(RENDER_FILES.O) $(HELP_FILES.O) $(MAIN_FILES.O) \
					-L./$(LIB_DIR)libft -lft -L./$(LIB_DIR)libgraphic_math -lgraphic_math \
					-L./$(LIB_DIR)minilibx -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd \
					-o $(NAME)

ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
	-nrRf $(firstword $(MAKEFILE_LIST)) \
	ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)
ifneq ($(T), 0)
	ECHO = echo -ne "\e[36m\r[`expr $C '*' 100 / $T`%]"
endif # ifneq #
ifeq ($(T), 0)
	ECHO = echo -ne "\e[36m\r[`expr $C '*' 100 / 73`%]"
endif # ifeq #
endif # ECHO #

$(CLASS_FILES.O): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(ECHO) "CLASSES"
	@echo
	@$(CC) $(FLAGS) -c $< -o $@
include $(wildcard $(OBJ_DIR)$(CLASS_DIR)*/*.d)

$(EVENTS_FILES.O): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(ECHO) "EVENTS"
	@echo
	@$(CC) $(FLAGS) -c $< -o $@
include $(wildcard $(OBJ_DIR)$(EVENTS_DIR)*.d)

$(EXIT_FILES.O): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(ECHO) "EXIT"
	@echo
	@$(CC) $(FLAGS) -c $< -o $@
include $(wildcard $(OBJ_DIR)$(EXIT_DIR)*.d)

$(PARSER_FILES.O): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(ECHO) "PARSER"
	@echo
	@$(CC) $(FLAGS) -c $< -o $@
include $(wildcard $(OBJ_DIR)$(PARSER_DIR)*.d)

$(RENDER_FILES.O): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(ECHO) "RENDER"
	@echo
	@$(CC) $(FLAGS) -c $< -o $@
include $(wildcard $(OBJ_DIR)$(RENDER_DIR)*.d)

$(HELP_FILES.O): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(ECHO) "HELP"
	@echo
	@$(CC) $(FLAGS) -c $< -o $@
include $(wildcard $(OBJ_DIR)*.d)

$(MAIN_FILES.O): $(OBJ_DIR)%.o: %.c
	@$(ECHO) "MAIN"
	@echo
	@$(CC) $(FLAGS) -c $< -o $@
include $(wildcard $(OBJ_DIR)*.d)

.PHONY: clean
clean:
	$(RM) -r $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean libfclean all

.PHONY: libfclean
libfclean:
	@$(MAKE) -C ./$(LIB_DIR)libft --no-print-directory fclean
	@$(MAKE) -C ./$(LIB_DIR)libgraphic_math --no-print-directory fclean
	@$(MAKE) -C ./$(LIB_DIR)minilibx --no-print-directory clean

.PHONY: valg
valg: $(NAME)
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes --vgdb=no ./$(NAME) scene_tests/valgrind.rt

.PHONY: valg_zero
valg_zero:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) # Написать адрес файла, в котором есть ошибка описания

.PHONY: bonus
bonus: all
	@echo -e "\e[35m\n  Knowing the mouse might one day leave its hole and get the cheese...\n  It fills you with determination.\n\e[0m"

#norminette *.c includes libs/libft libs/libgraphic_math src | grep -B1 Error
