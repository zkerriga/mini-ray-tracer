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

t_3dvector	*normalize(t_3dvector *vector)
{
	float	divider;

	divider = module(vector);
	vector->x /= divider;
	vector->y /= divider;
	vector->z /= divider;
	return (vector);
}
