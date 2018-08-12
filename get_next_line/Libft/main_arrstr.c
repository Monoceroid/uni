/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 10:27:57 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/18 14:50:38 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	*ft_arrstr(char *str, char c, int size)
{
	int	*p;
	int	*p2;

	p = (int *)malloc(sizeof(int) * size);
	p2 = p;
	while (*str)
	{
		if (*str >= '0' && *str <= '9' && *(str + 1) == c)
			*p++ = *str - '0';
		else if (*str >= '0' && *str <= '9')
		{
			*p++ = (*str - '0') * 10 + (*(str + 1) - '0');
			str++;
		}
		str++;
	}
	return (p2);
}

int main(void)
{
	char	*s = "1,12,6,3,8,14,7,6,";
	int		*p = ft_arrstr(s, ',', 8);
	int		i = 0;

	while (i++ < 8)
		printf("%d, ", *p++);
	return (0);
}
