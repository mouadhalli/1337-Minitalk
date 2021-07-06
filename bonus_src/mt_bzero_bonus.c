/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:27:09 by mhalli            #+#    #+#             */
/*   Updated: 2021/07/06 16:27:12 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	mt_bzero(void *s, size_t n)
{
	char	*l;
	int		i;

	i = 0;
	l = s;
	while ((size_t)i < n)
		l[i++] = '\0';
}