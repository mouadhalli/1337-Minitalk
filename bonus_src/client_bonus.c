/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:20:50 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/15 15:20:52 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <stdio.h>

void	exit_err(char *err_msg)
{
	mt_putstr("Error\n", 1);
	mt_putstr(err_msg, 1);
	mt_putchar('\n', 1);
	exit(1);
}

void	end_msg(int pid)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(50);
		i--;
	}
}

void	send_msg(int pid, char *msg)
{
	int		i;
	int		j;
	int		bit;

	i = 0;
	while (msg[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			bit = msg[i] & (1 << j);
			if (bit == 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
			j--;
		}
		i++;
	}
	end_msg(pid);
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc < 3)
		exit_err("usage :\n ./server [pid] [msg]");
	pid = mt_atoi(argv[1]);
	send_msg(pid, argv[2]);
	return (0);
}
