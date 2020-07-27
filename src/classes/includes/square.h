/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:37:50 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 09:38:09 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include "basic_structures.h"

typedef struct	s_square
{
	char		identifier[2];
	void		(*del)(struct s_square *);
	float		(*solve)(struct s_square *, t_point *, t_vec3 *, t_limits *);
	t_vec3		*(*get_n)(struct s_square *, t_point *, t_point *);
	void		(*prepare)(struct s_square *, t_scene *);
	t_rgbvec	color;
	t_point		center;
	t_vec3		norm;
	float		side_size;
}				t_square;

t_square		*new_square(char *line);
void			del_square(t_square *self);
t_bool			square_is_valid(char *line);
t_vec3			*sq_get_n(t_square *self, t_point *point, t_point *camera);
float			sq_solve(t_square *self, t_point *camera,
							t_vec3 *ray, t_limits *l);
void			sq_prepare(t_square *self, t_scene *scene);

#endif
