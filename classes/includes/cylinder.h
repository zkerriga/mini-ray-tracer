/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:00:17 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 15:00:23 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "basic_structures.h"

typedef struct	s_cylinder
{
	char		identifier[2];
	void		(*del)(struct s_cylinder *);
	float		(*solve)(struct s_cylinder *, t_point *,
							t_3dvector *, t_limits *);
	t_3dvector	*(*get_n)(struct s_cylinder *, t_point *, t_point *);
	t_rgbvec	color;
	t_point		point;
	t_3dvector	vector;
	float		diameter;
	float		height;
}				t_cylinder;

t_cylinder		*new_cylinder(char *line);
void			del_cylinder(t_cylinder *self);
t_bool			cylinder_is_valid(char *line);
float			cy_solve(t_cylinder *self, t_point *camera, t_3dvector *ray,
							t_limits *l);
t_3dvector		*cy_get_n(t_cylinder *self, t_point *point, t_point *camera);

#endif
