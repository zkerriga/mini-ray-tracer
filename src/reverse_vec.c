/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:53:45 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/12 19:53:47 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_3dvector	*reverse_vec(t_3dvector *vector)
{
	vector->x *= -1.f;
	vector->y *= -1.f;
	vector->z *= -1.f;
	return (vector);
}

/*
** Inverts the vector and writes the result to dest.
*/

t_3dvector	*vreverse(t_3dvector *dest, t_3dvector *vector)
{
	dest->x = vector->x * -1.f;
	dest->y = vector->y * -1.f;
	dest->z = vector->z * -1.f;
	return (dest);
}
