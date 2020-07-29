cmake_minimum_required(VERSION 3.16)
project(miniRT C)

set(CMAKE_C_STANDARD 11)

set(MYCOMPILE_FLAGS "-D BUFFER_SIZE=50 -L/usr/include/X11/ -lXext -lX11 -lx -lm -lbsd")
add_definitions(${MYCOMPILE_FLAGS})

include_directories(libs/get_next_line)
include_directories(libs/libft)
include_directories(src/classes/includes)
include_directories(includes)
include_directories(libs/minilibx)
include_directories(libs/libgraphic_math)

set(HEADER_FILES
        libs/get_next_line/get_next_line.h
        libs/libft/libft.h
        libs/minilibx/mlx.h
        libs/minilibx/mlx_int.h
        libs/libgraphic_math/libgraphic_math.h

        includes/parser.h
        includes/render.h
        includes/minirt.h
        includes/events.h
        includes/exit.h

        src/classes/includes/ambient.h
        src/classes/includes/camera.h
        src/classes/includes/cylinder.h
        src/classes/includes/light.h
        src/classes/includes/plane.h
        src/classes/includes/resolution.h
        src/classes/includes/scene.h
        src/classes/includes/sphere.h
        src/classes/includes/square.h
        src/classes/includes/triangle.h
        src/classes/includes/basic_structures.h
        src/classes/includes/dmlx.h

        )

set(LIBS_SRC
        libs/get_next_line/get_next_line.c
        libs/get_next_line/get_next_line_utils.c
        libs/libft/src/is/ft_isalnum.c
        libs/libft/src/is/ft_isalpha.c
        libs/libft/src/is/ft_isascii.c
        libs/libft/src/is/ft_isdigit.c
        libs/libft/src/is/ft_isprint.c
        libs/libft/src/is/ft_isspace.c
        libs/libft/src/is/ft_tolower.c
        libs/libft/src/is/ft_toupper.c
        libs/libft/src/lst/ft_lstadd_back.c
        libs/libft/src/lst/ft_lstadd_front.c
        libs/libft/src/lst/ft_lstclear.c
        libs/libft/src/lst/ft_lstdelone.c
        libs/libft/src/lst/ft_lstdelel.c
        libs/libft/src/lst/ft_lstiter.c
        libs/libft/src/lst/ft_lstlast.c
        libs/libft/src/lst/ft_lstmap.c
        libs/libft/src/lst/ft_lstnew.c
        libs/libft/src/lst/ft_lstsize.c
        libs/libft/src/dlst/ft_dlstclear.c
        libs/libft/src/dlst/ft_dlstadd_front.c
        libs/libft/src/dlst/ft_dlstnew.c
        libs/libft/src/mem/ft_bzero.c
        libs/libft/src/mem/ft_calloc.c
        libs/libft/src/mem/ft_memccpy.c
        libs/libft/src/mem/ft_memchr.c
        libs/libft/src/mem/ft_memcmp.c
        libs/libft/src/mem/ft_memcpy.c
        libs/libft/src/mem/ft_memmove.c
        libs/libft/src/mem/ft_memset.c
        libs/libft/src/malloc_gc/malloc_gc.c
        libs/libft/src/malloc_gc/free_gc.c
        libs/libft/src/malloc_gc/memory_manager.c
        libs/libft/src/nbr/ft_atoi.c
        libs/libft/src/nbr/ft_itoa.c
        libs/libft/src/nbr/ft_atof.c
        libs/libft/src/put/ft_putchar_fd.c
        libs/libft/src/put/ft_putendl_fd.c
        libs/libft/src/put/ft_putnbr_fd.c
        libs/libft/src/put/ft_putstr_fd.c
        libs/libft/src/str/ft_split.c
        libs/libft/src/str/ft_strchr.c
        libs/libft/src/str/ft_strdup.c
        libs/libft/src/str/ft_strjoin.c
        libs/libft/src/str/ft_strlcat.c
        libs/libft/src/str/ft_strlcpy.c
        libs/libft/src/str/ft_strlen.c
        libs/libft/src/str/ft_strmapi.c
        libs/libft/src/str/ft_strncmp.c
        libs/libft/src/str/ft_strnstr.c
        libs/libft/src/str/ft_strrchr.c
        libs/libft/src/str/ft_strtrim.c
        libs/libft/src/str/ft_substr.c
        libs/libft/src/tree/ft_leafadd.c
        libs/libft/src/tree/ft_leaffind.c
        libs/libft/src/tree/ft_leafnew.c
        libs/libft/src/tree/ft_treeclear.c
        libs/libft/src/tree/ft_treeinorder.c
        libs/libft/src/tree/ft_treepostorder.c
        libs/libft/src/tree/ft_treepreorder.c

        libs/minilibx/mlx_clear_window.c
        libs/minilibx/mlx_destroy_image.c
        libs/minilibx/mlx_destroy_window.c
        libs/minilibx/mlx_expose_hook.c
        libs/minilibx/mlx_flush_event.c
        libs/minilibx/mlx_get_color_value.c
        libs/minilibx/mlx_get_data_addr.c
        libs/minilibx/mlx_get_screen_size.c
        libs/minilibx/mlx_hook.c
        libs/minilibx/mlx_init.c
        libs/minilibx/mlx_int_anti_resize_win.c
        libs/minilibx/mlx_int_do_nothing.c
        libs/minilibx/mlx_int_get_visual.c
        libs/minilibx/mlx_int_param_event.c
        libs/minilibx/mlx_int_set_win_event_mask.c
        libs/minilibx/mlx_int_str_to_wordtab.c
        libs/minilibx/mlx_int_wait_first_expose.c
        libs/minilibx/mlx_key_hook.c
#        libs/minilibx/mlx_lib_xpm.c
        libs/minilibx/mlx_loop.c
        libs/minilibx/mlx_loop_hook.c
        libs/minilibx/mlx_mouse_hook.c
        libs/minilibx/mlx_new_image.c
        libs/minilibx/mlx_new_window.c
        libs/minilibx/mlx_pixel_put.c
        libs/minilibx/mlx_put_image_to_window.c
        libs/minilibx/mlx_rgb.c
        libs/minilibx/mlx_string_put.c
        libs/minilibx/mlx_xpm.c


        libs/libgraphic_math/src/color_multi.c
        libs/libgraphic_math/src/color_sum.c
        libs/libgraphic_math/src/color_to_int.c
        libs/libgraphic_math/src/fbetween.c
        libs/libgraphic_math/src/maxf.c
        libs/libgraphic_math/src/module.c
        libs/libgraphic_math/src/normalize.c
        libs/libgraphic_math/src/rad_to_deg.c
        libs/libgraphic_math/src/reverse_vec.c
        libs/libgraphic_math/src/rotate_ray.c
        libs/libgraphic_math/src/set_lookat.c
        libs/libgraphic_math/src/vaddition.c
        libs/libgraphic_math/src/vdot.c
        libs/libgraphic_math/src/vget.c
        libs/libgraphic_math/src/vmulti.c
        libs/libgraphic_math/src/vprod.c
        libs/libgraphic_math/src/vset.c
        libs/libgraphic_math/src/vsubtract.c
        libs/libgraphic_math/libgraphic_math.h
        )

set(SRC_FILES
        src/classes/basic_functions/ft_next.c
        src/classes/basic_functions/ft_float_between.c
        src/classes/basic_functions/check_color.c
        src/classes/basic_functions/check_vector.c
        src/classes/basic_functions/check_int.c
        src/classes/basic_functions/check_float.c
        src/classes/basic_functions/check_coordinates.c

        src/classes/scene/del_scene.c
        src/classes/scene/new_scene.c
        src/classes/scene/get_d.c
        src/classes/scene/get_active_camera.c

        src/classes/resolution/new_resolution.c
        src/classes/resolution/del_resolution.c
        src/classes/resolution/resolution_is_valid.c

        src/classes/ambient/new_ambient.c
        src/classes/ambient/del_ambient.c
        src/classes/ambient/ambient_is_valid.c

        src/classes/camera/new_camera.c
        src/classes/camera/del_camera.c
        src/classes/camera/camera_is_valid.c

        src/classes/light/new_light.c
        src/classes/light/del_light.c
        src/classes/light/light_is_valid.c

        src/classes/sphere/new_sphere.c
        src/classes/sphere/del_sphere.c
        src/classes/sphere/sphere_is_valid.c
        src/classes/sphere/sp_get_n.c
        src/classes/sphere/sp_solve.c

        src/classes/plane/new_plane.c
        src/classes/plane/del_plane.c
        src/classes/plane/plane_is_valid.c
        src/classes/plane/pl_solve.c
        src/classes/plane/pl_get_n.c

        src/classes/square/new_square.c
        src/classes/square/del_square.c
        src/classes/square/square_is_valid.c
        src/classes/square/sq_get_n.c
        src/classes/square/sq_solve.c

        src/classes/cylinder/new_cylinder.c
        src/classes/cylinder/del_cylinder.c
        src/classes/cylinder/cylinder_is_valid.c
        src/classes/cylinder/cy_solve.c
        src/classes/cylinder/cy_get_n.c

        src/classes/triangle/new_triangle.c
        src/classes/triangle/del_triangle.c
        src/classes/triangle/triangle_is_valid.c
        src/classes/triangle/tr_get_n.c
        src/classes/triangle/tr_solve.c

        src/classes/dmlx/new_dmlx.c
        src/classes/dmlx/del_dmlx.c
        src/classes/dmlx/create_window.c
        src/classes/dmlx/put_image_to_bmp.c
        src/classes/dmlx/put_image_to_win.c

        src/parser/parser.c
        src/parser/match.c

        src/render/render.c
        src/render/trace_ray.c
        src/render/color_definition.c
        src/render/get_diffuse.c
        src/render/is_shadow_point.c
        src/render/ray_lim.c

        minirt.c

        src/exit/ft_exit.c
        src/exit/ft_exit_memerror.c
        src/exit/ft_exit_invalid_input.c
        src/exit/ft_exit_invalid_descriptor.c
        src/exit/ft_exit_window_error.c

        src/events/key_handler.c
        src/events/close_handler.c

        src/show_help.c
        )

add_executable(miniRT
        ${HEADER_FILES}
        ${LIBS_SRC}
        ${SRC_FILES}
        )

target_link_libraries(miniRT Xext X11 m bsd)
add_library(test ${SRC_FILES} ${LIBS_SRC})
add_subdirectory(unit_tests)
