/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:41:36 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/17 15:41:38 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mt_putnbr(int n, int fd)
{
	int		subst;
	int		size;

	size = 1;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n < 0 && n != -2147483648)
	{
		mt_putchar('-', fd);
		n = n * -1;
	}
	subst = n;
	while ((subst /= 10) > 0)
		size *= 10;
	subst = n;
	while (size && n != -2147483648)
	{
		mt_putchar((subst / size) + 48, fd);
		subst %= size;
		size /= 10;
	}
}