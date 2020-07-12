/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:47:41 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 14:47:59 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "basic_structures.h"

typedef struct	s_plane
{
	char		identifier[2];
	void		(*del)(struct s_plane *);
	float		(*solve)(struct s_plane *, t_point *,
							t_3dvector *, t_limits *);
	t_3dvector	*(*get_n)(struct s_plane *, t_point *);
	t_rgbvec	color;
	t_point		point;
	t_3dvector	vector;
}				t_plane;

t_plane			*new_plane(char *line);
void			del_plane(t_plane *self);
t_bool			plane_is_valid(char *line);
float			pl_solve(t_plane *self, t_point *camera, t_3dvector *ray,
							t_limits *l);
t_3dvector		*pl_get_n(t_plane *self, t_point *point);

#endif
