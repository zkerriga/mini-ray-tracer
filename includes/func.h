/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:47:35 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/29 17:47:49 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# include "minirt.h"

int			color_to_int(t_rgbvec color);
t_rgbvec	*color_sum(t_rgbvec *dest, t_rgbvec one, t_rgbvec two);
t_rgbvec	*color_multi(t_rgbvec *dest, t_rgbvec one, t_rgbvec two);
float		vdot(t_3dvector a, t_3dvector b);
float		module(t_3dvector vector);
t_bool		fbetween(float nbr, float down, float up);
void		set_vector(t_3dvector *dest, t_point to, t_point from);
float		maxf(float one, float two);
t_range		*ray_range(float min, float max);

#endif
