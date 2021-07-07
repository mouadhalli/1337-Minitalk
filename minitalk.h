/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:26:09 by mhalli            #+#    #+#             */
/*   Updated: 2021/06/15 15:26:11 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>

typedef struct s_msg
{
	char	*buff;
	int		pos;
}				t_msg;

int		mt_atoi(const char *str);
void	mt_putstr(char *s, int fd);
void	mt_putchar(char c, int fd);
char	*mt_itoa(int n);
char	*mt_strdup(const char *s1);
size_t	mt_strlen(const char *s);
void	mt_bzero(void *s, size_t n);
void	exit_err(char *err_msg);
int		is_nbr(char *str);

t_msg	*g_msg;

#endif