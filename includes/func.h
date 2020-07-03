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
#define FUNC_H

#include "minirt.h"

int			color_to_int(t_color color);
t_color		bright(t_color *color, float brightness);
float		vdot(t_3dvector a, t_3dvector b);

#endif
