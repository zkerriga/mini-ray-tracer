/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_to_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 10:07:25 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/24 10:07:27 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dmlx.h"

void	put_image_to_win(t_dmlx *self)
{
	mlx_put_image_to_window(self->mlx, self->win, self->img, 0, 0);
}
