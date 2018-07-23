/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1arrdif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:47:19 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/23 11:50:19 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

int	main(void)
{

	int n;
	int *arr;
	int count;
	int	i;

	n = 12;
	arr  = (int *)malloc(sizeof(int ) * n);
	count = 1;
	i = 0;
	while (i < 12)
		arr[i++] = count++;
	arr[10] = 12;
	i = 0;
	while (i < 12)
		printf("%d ", arr[i++]);
	printf("\n%d", ft_1arrdif(arr, 12));
	return (0);
}
