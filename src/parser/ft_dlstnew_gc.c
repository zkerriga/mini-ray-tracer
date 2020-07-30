/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew_gc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:00:04 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/30 11:01:38 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew_gc(void *content)
{
	t_dlist	*fresh;

	fresh = (t_dlist *)malloc_gc(sizeof(t_dlist));
	if (fresh)
	{
		fresh->content = content;
		fresh->next = NULL;
		fresh->prev = NULL;
	}
	return (fresh);
}
