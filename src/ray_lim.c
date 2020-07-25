/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_lim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:26:39 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/10 14:33:50 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** The function defines the minimum and maximum values of solutions for the ray.
** The first time the function is run to create a range,
** and the second time to delete it.
*/

t_limits	*ray_lim(t_limits *dest, float min, float max)
{
	dest->min = min;
	dest->max = max;
	return (dest);
}
