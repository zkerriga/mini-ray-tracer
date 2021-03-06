/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:31:16 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 17:32:23 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "square.h"

void	del_square(t_square *self)
{
	free_gc(self);
}
