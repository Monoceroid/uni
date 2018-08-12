/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1arrdif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:47:19 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/23 14:05:12 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_1arrdif(int *p, int n)
{
	int	res;
	int	x;

	res = 1;
	x = 0;
	if (n == 1)
		return (res);
	while (++x < n)
	{
		if (*p == *(p + x))
			res = 0;
	}
	if (res == 0)
		return (res);
		else
		res = ft_1arrdif(p + 1, n - 1);
	return (res);
}
