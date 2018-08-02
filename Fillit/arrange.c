/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:07:57 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/02 13:22:22 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

int	**arrange(int **a, int n, int l, int i)
{
	int	j;

	while (++i < n)
	{
//		printf("\n%i", i);
		j = 0;
		while (i - (++j) >= 0)
		{
			while (ft_1ardif(a[i], a[i - j], 4, 4) != 1)
				increment_tet(a[i], l);
			if (i == 3)
				printf("\nHere a[i][1]: %i a[i - 1][3]: %i", a[i][1], a[i - 1][3]);
			printf("\nft_1ardif: %i", ft_1ardif(a[i], a[i - 1], 4, 4));
		}
		if (a[0][3] > l * l)
			return (NULL);
		if (a[i][3] > l * l)
		{
			i--;
			increment_tet(a[i], l);
			printf("\nI'm about to call the function again.");
			arrange(a, n, l, i);
		}
	}
	return (a);
}
