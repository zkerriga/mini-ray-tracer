/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:53:53 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/18 13:54:09 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "libft.h"
# include "mlx.h"

# include "ambient.h"
# include "camera.h"
# include "cylinder.h"
# include "light.h"
# include "plane.h"
# include "resolution.h"
# include "sphere.h"
# include "triangle.h"
# include "square.h"
# include "dmlx.h"

typedef struct		s_scene
{
	t_dmlx			*dmlx;
	t_resolution	*resolution;
	t_ambient		*ambient;
	t_dlist			*cameras;
	t_camera		*act_cam;
	t_list			*lights;
	t_list			*objects;
	float			(*get_d)(struct s_scene *, int);
	t_camera		*(*get_cam)(struct s_scene *, t_bool);
	void			(*del)(struct s_scene *);
}					t_scene;

t_scene				*new_scene(t_resolution *resolution, t_ambient *ambient,
								t_dlist *cameras, t_list *all_obj);
void				del_scene(t_scene *self);
float				get_d(t_scene *self, int fov);
t_camera			*get_active_camera(t_scene *self, t_bool mode);

#endif
