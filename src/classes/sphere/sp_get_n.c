/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:34:41 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/12 18:30:54 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "sphere.h"

t_vec3	*sp_get_n(t_sphere *self, t_point *point, t_point *camera)
{
	t_vec3	*norm;

	if (!(norm = (t_vec3 *)malloc(sizeof(t_vec3))))
	{
		free_gc(NULL);
		ft_exit(ENOMEM);
	}
	vget(norm, point, &self->center);
	if (modulep_sqr(camera, &self->center) < self->radius_square)
		reverse_vec(norm);
	return (normalize(norm));
}
