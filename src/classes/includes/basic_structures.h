/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:44:28 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 15:44:32 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_STRUCTURES_H
# define BASIC_STRUCTURES_H

# define TRUE 1
# define FALSE 0

# include "libgraphic_math.h"

typedef struct s_scene	t_scene;

typedef struct	s_limits
{
	float		min;
	float		max;
}				t_limits;

typedef struct	s_any_obj
{
	char		identifier[2];
	void		(*del)(struct s_any_obj *);
	float		(*solve)(struct s_any_obj *, t_point *, t_vec3 *, t_limits *);
	t_vec3		*(*get_n)(struct s_any_obj *, t_point *, t_point *);
	void		(*prepare)(struct s_any_obj *, t_scene *);
	t_rgbvec	color;
}				t_any_object;

char			*ft_next(char *line);
t_bool			ft_float_between(float nbr, float down, float up);
t_bool			check_float(char *line);
t_bool			check_int(char *line);
t_bool			check_vector(char **line);
t_bool			check_color(char **line);
t_bool			check_coordinates(char **line);

#endif
