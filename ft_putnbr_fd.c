/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 18:42:39 by wtaylor           #+#    #+#             */
/*   Updated: 2018/04/16 18:44:06 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		power(int a, int b)
{
	int c;

	if (b == 0)
		return (1);
	c = a;
	while (b > 1)
	{
		c = c * a;
		b--;
	}
	return (c);
}

void	ft_putnbr_fd(int n, int fd)
{
	int o;
	int i;

	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	o = n;
	i = 1;
	while (o >= 10)
	{
		o = o / 10;
		i++;
	}
	while (--i >= 0)
	{
		ft_putchar_fd((n / power(10, i)) % 10 + 48, fd);
	}
}
