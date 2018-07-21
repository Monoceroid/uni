/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdiff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:54:47 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/21 14:20:54 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_arrdiff(int **p, int m, int n)
{
	int	i;
	int	x;
	int **q;

	i = 0;
	x = 1;
	q = p;
	while (i < (m * n))
	{
		while (x < (m * n - x + 1 - (p - q)))
		{
			if (**p == **(p + x))
				return (0);
			x++;
		}
		p++;
	}
	return (1);
}

int	main(void)
{
	int	arr[2][3] = {{1, 5, 3},{8, 2, 6}};
	int	**p;

	p = arr;	
	printf("%d", ft_arrdiff(p, 2, 3));
	return (0);
}
