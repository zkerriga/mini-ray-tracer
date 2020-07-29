/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_invalid_descriptor.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 22:11:05 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 22:11:17 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include "libft.h"

void	ft_exit_invalid_descriptor(void)
{
	ft_putendl_fd("The file path is incorrect!", 1);
	free_gc(NULL);
	exit(0);
}
