cmake_minimum_required(VERSION 3.16)
project(miniRT C)

set(CMAKE_C_STANDARD 11)

set(MYCOMPILE_FLAGS "-D BUFFER_SIZE=50 -L/usr/include/X11/ -lXext -lX11 -lx -lm -lbsd")
add_definitions(${MYCOMPILE_FLAGS})

include_directories(libs/get_next_line)
include_directories(libs/libft)
include_directories(classes/includes)
include_directories(includes)
include_directories(libs/minilibx)

set(HEADER_FILES
        libs/get_next_line/get_next_line.h
        libs/libft/libft.h
        libs/minilibx/mlx.h
        libs/minilibx/mlx_int.h

        includes/parser.h
        includes/render.h
        includes/minirt.h
        includes/func.h

        classes/includes/ambient.h
        classes/includes/camera.h
        classes/includes/cylinder.h
        classes/includes/light.h
        classes/includes/plane.h
        classes/includes/resolution.h
        classes/includes/scene.h
        classes/includes/sphere.h
        classes/includes/square.h
        classes/includes/triangle.h
        classes/includes/basic_structures.h

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
        )

set(SRC_FILES
        classes/basic_functions/ft_next.c
        classes/basic_functions/ft_float_between.c
        classes/basic_functions/check_color.c
        classes/basic_functions/check_vector.c
        classes/basic_functions/check_int.c
        classes/basic_functions/check_float.c
        classes/basic_functions/check_coordinates.c

        classes/scene/del_scene.c
        classes/scene/new_scene.c
        classes/scene/get_d.c
        classes/scene/get_active_camera.c

        classes/resolution/new_resolution.c
        classes/resolution/del_resolution.c
        classes/resolution/resolution_is_valid.c

        classes/ambient/new_ambient.c
        classes/ambient/del_ambient.c
        classes/ambient/ambient_is_valid.c

        classes/camera/new_camera.c
        classes/camera/del_camera.c
        classes/camera/camera_is_valid.c

        classes/light/new_light.c
        classes/light/del_light.c
        classes/light/light_is_valid.c

        classes/sphere/new_sphere.c
        classes/sphere/del_sphere.c
        classes/sphere/sphere_is_valid.c
        classes/sphere/sp_get_n.c
        classes/sphere/sp_solve.c

        classes/plane/new_plane.c
        classes/plane/del_plane.c
        classes/plane/plane_is_valid.c
        classes/plane/pl_solve.c
        classes/plane/pl_get_n.c

        classes/square/new_square.c
        classes/square/del_square.c
        classes/square/square_is_valid.c
        classes/square/sq_get_n.c
        classes/square/sq_solve.c

        classes/cylinder/new_cylinder.c
        classes/cylinder/del_cylinder.c
        classes/cylinder/cylinder_is_valid.c
        classes/cylinder/cy_solve.c
        classes/cylinder/cy_get_n.c

        classes/triangle/new_triangle.c
        classes/triangle/del_triangle.c
        classes/triangle/triangle_is_valid.c
        classes/triangle/tr_get_n.c
        classes/triangle/tr_solve.c

        parser/parser.c

        render/render.c
        render/trace_ray.c
        render/color_definition.c
        render/get_diffuse.c
        render/is_shadow_point.c
        render/rotate.c

        minirt.c

        exit/ft_exit.c
        exit/ft_exit_memerror.c
        exit/ft_exit_invalid_input.c
        exit/ft_exit_invalid_descriptor.c
        exit/ft_exit_window_error.c

        src/color_to_int.c
        src/vdot.c
        src/color_sum.c
        src/color_multi.c
        src/module.c
        src/fbetween.c
        src/set_vector.c
        src/maxf.c
        src/ray_lim.c
        src/vprod.c
        src/set_point.c
        src/normalize.c
        src/reverse_vec.c
        src/rad_to_deg.c
        src/vmulti.c
        src/vaddition.c
        src/vsubtract.c
        )

add_executable(miniRT
        ${HEADER_FILES}
        ${LIBS_SRC}
        ${SRC_FILES}
        )

target_link_libraries(miniRT Xext X11 m bsd)
add_library(test ${SRC_FILES} ${LIBS_SRC})
add_subdirectory(Google_test)
