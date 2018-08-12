/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 10:27:57 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/18 15:15:32 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
