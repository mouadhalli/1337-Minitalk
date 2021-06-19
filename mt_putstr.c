/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:28:25 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/17 16:28:26 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mt_putstr(char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		mt_putchar(s[i], fd);
		i++;
	}
}