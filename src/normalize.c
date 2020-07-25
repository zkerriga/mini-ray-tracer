/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 06:45:22 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/12 06:45:24 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "func.h"

/*
** Normalizes the vector to a unit length.
*/

t_vec3	*normalize(t_vec3 *vector)
{
	float	divider;

	divider = module(vector);
	vector->x /= divider;
	vector->y /= divider;
	vector->z /= divider;
	return (vector);
}
