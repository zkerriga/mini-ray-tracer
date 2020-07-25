/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmulti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:37:32 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/20 12:37:42 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Multiplying a vector by a number.
** Returns the original pointer to dest.
*/

t_vec3	*vmulti(t_vec3 *dest, t_vec3 *vec, float multiplier)
{
	dest->x = vec->x * multiplier;
	dest->y = vec->y * multiplier;
	dest->z = vec->z * multiplier;
	return (dest);
}
