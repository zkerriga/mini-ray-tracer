/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:59:58 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/30 11:01:44 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_gc(void *content)
{
	t_list	*fresh;

	fresh = (t_list *)malloc_gc(sizeof(t_list));
	if (fresh)
	{
		fresh->content = content;
		fresh->next = NULL;
	}
	return (fresh);
}
