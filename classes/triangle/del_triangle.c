/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:31:38 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 17:32:37 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "triangle.h"

void	del_triangle(t_triangle *self)
{
	free_gc(self);
}
