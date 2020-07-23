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

# include "math.h"

void	render(t_scene *scene, t_camera *camera, int x_size, int y_size);
int		trace_ray(t_scene *scene, t_point *cam, t_3dvector *ray);
int		color_definition(t_scene *scene, t_point *camera, t_any_object *obj, t_point *point);
void	get_diffuse(t_rgbvec *diffuse, t_light *light,
					t_any_object *obj, t_point *point, t_point *camera);
t_bool	is_shadow_point(t_scene *scene, t_point *point, t_3dvector *ray);
t_3dvector	*rotate_ray(t_3dvector *ray, t_3dvector *dir);

#endif
