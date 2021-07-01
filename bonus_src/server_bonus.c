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

static char	*add_char(char *msg, char c)
{
	char	*tmp;
	int		i;

	if (msg == NULL)
	{
		msg = malloc(1);
		msg[0] = '\0';
	}
	i = 0;
	while (msg[i])
		i++;
	tmp = (char *)malloc(i + 2);
	i = 0;
	while (msg[i])
	{
		tmp[i] = msg[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(msg);
	return (tmp);
}

void	print_msg(char **msg)
{
	mt_putstr(*msg, 1);
	mt_putchar('\n', 1);
	free(*msg);
	*msg = NULL;
}

void	fill_char(int num)
{
	static int	c;
	static int	power;
	static char	*msg;

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
		msg = add_char(msg, c);
		if (c == '\0')
			print_msg(&msg);
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
	print_pid();
	signal(SIGUSR1, fill_char);
	signal(SIGUSR2, fill_char);
	while (1)
		pause();
	return (0);
}
