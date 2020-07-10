/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:30:06 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 14:30:19 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "basic_structures.h"

typedef struct	s_sphere
{
	char		identifier[2];
	void		(*del)(struct s_sphere *);
	float		(*solve)(struct s_sphere *, t_point *, t_3dvector *, t_limits);
	t_3dvector	*(*get_n)(struct s_sphere *, t_point *);
	t_rgbvec	color;
	t_point		center;
	float		diameter;
}				t_sphere;

t_sphere		*new_sphere(char *line);
void			del_sphere(t_sphere *self);
t_bool			sphere_is_valid(char *line);
float			solve(t_sphere *self, t_point *camera, t_3dvector *ray,
						t_limits l);
t_3dvector		*get_n(t_sphere *self, t_point *point);

#endif
