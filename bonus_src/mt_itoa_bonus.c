/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:31:20 by mhalli            #+#    #+#             */
/*   Updated: 2021/07/01 19:31:21 by mhalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	size_to_allocate(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_more(char *num, int n, int j)
{
	if (n < 0)
	{
		num[0] = '-';
		n = n * -1;
		while (j + 1 > 1)
		{
			num[j--] = (n % 10) + 48;
			n /= 10;
		}
	}
	else
	{
		while (j + 1 > 0)
		{
			num[j--] = (n % 10) + 48;
			n = n / 10;
		}
	}
	return (num);
}

char	*mt_itoa(int n)
{
	int		j;
	char	*num;

	if (n == -2147483648)
		return (mt_strdup("-2147483648"));
	num = (char *)malloc(sizeof(char) * (size_to_allocate(n) + 1));
	if (!num)
		return (0);
	j = size_to_allocate(n);
	num[j] = '\0';
	j--;
	return (ft_more(num, n, j));
}
