/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:02:37 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 15:05:05 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "basic_structures.h"

typedef struct	s_triangle
{
	char		identifier[2];
	void		(*del)(struct s_triangle *);
	float		(*solve)(struct s_triangle *, t_point *, t_vec3 *, t_limits *);
	t_vec3		*(*get_n)(struct s_triangle *, t_point *, t_point *);
	void		(*prepare)(struct s_triangle *, t_scene *);
	t_rgbvec	color;
	t_point		a_point;
	t_point		b_point;
	t_point		c_point;
	t_vec3		ab_edge;
	t_vec3		ac_edge;
	t_vec3		norm;
}				t_triangle;

t_triangle		*new_triangle(char *line);
void			del_triangle(t_triangle *self);
t_bool			triangle_is_valid(char *line);
float			tr_solve(t_triangle *self, t_point *camera, t_vec3 *ray,
							t_limits *l);
t_vec3			*tr_get_n(t_triangle *self, t_point *point, t_point *camera);
void			tr_prepare(t_triangle *self, t_scene *scene);

#endif
