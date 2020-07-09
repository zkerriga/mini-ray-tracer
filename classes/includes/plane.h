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
	t_rgbvec	color;
	t_point		point;
	t_3dvector	vector;
}				t_plane;

t_plane			*new_plane(char *line);
void			del_plane(t_plane *self);
t_bool			plane_is_valid(char *line);

#endif
