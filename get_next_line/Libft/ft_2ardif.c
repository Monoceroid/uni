/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2ardif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:56:56 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/23 14:07:03 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_2ardif(int **a, int r, int c)
{
	int res;
	int x;

	res = 1;
	x = 0;
	if (r == 1)
		return (res);
	while (++x < r)
	{
		if (ft_1ardif(*a, *(a + x), c, c) == 0)
			res = 0;
	}
	if (res == 0)
		return (res);
	else
		res = ft_2ardif(a + 1, r - 1, c);
	return (res);
}
