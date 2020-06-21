/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:31:06 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 17:32:07 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "resolution.h"

void	del_resolution(t_resolution *self)
{
	free_gc(self);
}
