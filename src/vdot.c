/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vdot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 17:26:41 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/03 17:26:49 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Scalar multiplication of two vectors
*/

float	vdot(t_vec3 *vec1, t_vec3 *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}
