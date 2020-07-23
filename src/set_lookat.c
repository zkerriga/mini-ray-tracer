/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lookat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:29:23 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/23 12:29:25 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"
#include "minirt.h"
#include "math.h"

static void	set_default_lookat(t_matrix *lookat, t_3dvector *norm)
{
	t_3dvector	fake_up;

	set_point(&fake_up, 0.f, 1.f, 0.f);
	lookat->z_f = *norm;
	vprod(&lookat->x_r, &fake_up, norm);
	vprod(&lookat->y_u, norm, &lookat->x_r);
}

void		set_lookat(t_matrix *lookat, t_3dvector *norm)
{
	if (norm->x == 0.f && norm->z == 0.f && fabs(norm->y) == 1.0)
	{
		if (norm->y == 1.f)
		{
			set_point(&lookat->x_r, 1.f, 0.f, 0.f);
			set_point(&lookat->y_u, 0.f, 0.f, 1.f);
			set_point(&lookat->z_f, 0.f, 1.f, 0.f);
		}
		else
		{
			set_point(&lookat->x_r, 0.f, 0.f, 1.f);
			set_point(&lookat->y_u, 1.f, 0.f, 0.f);
			set_point(&lookat->z_f, 0.f, -1.f, 0.f);
		}
	}
	else
		set_default_lookat(lookat, norm);
//	normalize(&lookat->x_r);
//	normalize(&lookat->y_u);
//	normalize(&lookat->z_f);
}
