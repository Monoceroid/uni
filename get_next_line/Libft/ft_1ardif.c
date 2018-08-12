/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1ardif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:39:43 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/01 14:16:09 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_1ardif(int *p, int *q, int n, int count)
{
	int	res;
	int	x;

	res = 1;
	if (p == q)
		return(ft_1arrdif(p, n));
	x = -1;
	if (count == 0)
		return (res);
	while (++x < n)
	{
		if (*p == *(q + x))
			res = 0;
	}
	if (res == 0)
		return (res);
	else
		res = ft_1ardif(p + 1, q, n, count - 1);
	return (res);
}
