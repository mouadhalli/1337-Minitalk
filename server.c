/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:20:36 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/15 15:20:37 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	fill_char(int num)
{
	static int	c;
	static int	power;

	if (num == SIGUSR1)
		c += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		write(1, &c, 1);
		power = 0;
		c = 0;
	}
}

void		print_pid(void)
{
	mt_putstr("server pid : ", 1);
	mt_putstr(mt_itoa(getpid()), 1);
	mt_putchar('\n', 1);
}

int     main(void)
{
	print_pid();
	signal(SIGUSR1, fill_char);
	signal(SIGUSR2, fill_char);
	while (1)
		pause();
}
