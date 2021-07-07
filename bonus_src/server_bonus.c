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

#include "minitalk_bonus.h"

void	print_msg(void)
{
	mt_putstr(g_msg->buff, 1);
	mt_putchar('\n', 1);
	mt_bzero(g_msg->buff, g_msg->pos + 1);
	g_msg->pos = 0;
}

void	add_char(char c)
{
	g_msg->buff[g_msg->pos] = c;
	g_msg->pos++;
}

void	fill_char(int num)
{
	static int	c;
	static int	power;

	if (num == SIGUSR1)
	{
		c = c << 1;
		c += 1;
	}
	if (num == SIGUSR2)
		c = c << 1;
	power++;
	if (power == 8)
	{
		add_char(c);
		if (c == '\0')
			print_msg();
		power = 0;
		c = 0;
	}
}

void	print_pid(void)
{
	char	*pid;

	pid = mt_itoa(getpid());
	mt_putstr("server pid : ", 1);
	mt_putstr(pid, 1);
	mt_putchar('\n', 1);
	free(pid);
}

int	main(void)
{
	g_msg = (t_msg *)malloc(sizeof(t_msg));
	g_msg->buff = (char *)malloc(INT_MAX);
	if (!g_msg || !g_msg->buff)
		exit_err("memory allocation failed");
	g_msg->pos = 0;
	mt_bzero(g_msg->buff, INT_MAX);
	print_pid();
	signal(SIGUSR1, fill_char);
	signal(SIGUSR2, fill_char);
	while (1)
		pause();
	free(g_msg->buff);
	free(g_msg);
	return (0);
}
