/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1arrdif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:47:19 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/23 14:01:38 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
