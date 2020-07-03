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

# define MIN_T 1
# define MAX_T 9999

# include "math.h"

void	render(t_scene *scene, t_camera *camera, int x_size, int y_size);
int		trace_ray(t_scene *scene, t_point *camera, t_3dvector *ray);

#endif
