/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:37:34 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/17 16:37:35 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char		*mt_strdup(const char *s1)
{
	char		*b;
	size_t		i;
	size_t		z;

	i = 0;
	z = mt_strlen(s1);
	if (!(b = (char *)malloc(z + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		b[i] = (char)s1[i];
		i++;
	}
	b[i] = '\0';
	return (b);
}
