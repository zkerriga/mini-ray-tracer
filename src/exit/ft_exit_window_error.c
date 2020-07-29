/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_window_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:17:04 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/25 20:17:24 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "exit.h"

void	ft_exit_window_error(void)
{
	ft_putendl_fd("The X-window error!", 1);
	free_gc(NULL);
	exit(0);
}
