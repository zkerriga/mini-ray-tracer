/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:07:37 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/07 10:07:40 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "math.h"

/*
** Calculates the length of the vector.
*/

float	module(t_3dvector *vector)
{
	return (sqrt(pow(vector->x, 2) +
					pow(vector->y, 2) +
					pow(vector->z, 2)));
}

/*
** Calculates the length between two points.
*/

float	modulep(t_point *a, t_point *b)
{
	return (sqrt(pow(a->x - b->x, 2) +
				 pow(a->y - b->y, 2) +
				 pow(a->z - b->z, 2)));
}
