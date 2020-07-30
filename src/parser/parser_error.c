/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:49:43 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/30 09:49:45 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "exit.h"

/*
** Deletes the created objects.
*/

void	parser_error(t_resolution *resolution, t_ambient *ambient,
						t_list *all_obj, t_dlist *cameras)
{
	t_any_object	*any;
	void			*tmp;

	if (resolution)
		resolution->del(resolution);
	if (ambient)
		ambient->del(ambient);
	if (cameras)
	{
		ft_dlstclear(&cameras, free_gc);
	}
	while (all_obj)
	{
		any = all_obj->content;
		any->del(any);
		tmp = all_obj;
		all_obj = all_obj->next;
		free(tmp);
	}
	ft_exit(INVALID_DESCRIPTOR);
}
