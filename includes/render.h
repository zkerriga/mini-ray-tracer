/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:06:03 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/26 11:06:09 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define INACCURACY (0.00005f)
# define MAX_T (999)
# define NOT_ONE (0.9999f)
# define BLACK (0)

# include "libgraphic_math.h"
# include "minirt.h"

int			*render(t_scene *scene, int x_size, int y_size);
int			trace_ray(t_scene *scene, t_point *cam, t_list *objects, t_vec3 *ray);
int			color_definition(t_scene *scene, t_point *camera,
								t_any_object *obj, t_point *point);
void		get_diffuse(t_rgbvec *diffuse, t_light *light,
						t_vec3 *norm, t_point *point);
t_bool		is_shadow_point(t_scene *scene, t_point *point, t_vec3 *ray);
t_limits	*ray_lim(t_limits *dest, float min, float max);

#endif
