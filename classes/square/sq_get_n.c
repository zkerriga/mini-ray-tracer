/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_get_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 08:37:11 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/13 08:37:13 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "square.h"
#include "func.h"

t_vec3	*sq_get_n(t_square *self, t_point *point, t_point *camera)
{
	t_vec3	*norm;
	t_vec3	camera_to_point;

	if (!(norm = (t_vec3 *)malloc(sizeof(t_vec3))))
	{
		free_gc(NULL);
		ft_exit(ENOMEM);
	}
	norm->x = self->norm.x;
	norm->y = self->norm.y;
	norm->z = self->norm.z;
	set_vector(&camera_to_point, point, camera);
	if (vdot(norm, &camera_to_point) > 0.f)
		reverse_vec(norm);
	return (normalize(norm));
}
