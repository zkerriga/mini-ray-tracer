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

t_vec3	*reverse_vec(t_vec3 *vector)
{
	vector->x *= -1.f;
	vector->y *= -1.f;
	vector->z *= -1.f;
	return (vector);
}

/*
** Inverts the vector and writes the result to dest.
*/

t_vec3	*vreverse(t_vec3 *dest, t_vec3 *vector)
{
	dest->x = vector->x * -1.f;
	dest->y = vector->y * -1.f;
	dest->z = vector->z * -1.f;
	return (dest);
}
