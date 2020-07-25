/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:04:27 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/03 14:04:28 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "math.h"

float	get_d(t_scene *self, int fov)
{
	return (self->resolution->x_size / (2 * tan(M_PI * fov / 360)));
}
