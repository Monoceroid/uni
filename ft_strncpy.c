/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:25:46 by wtaylor           #+#    #+#             */
/*   Updated: 2018/04/26 12:13:11 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strncpy(char * dst, const char * src, int len)
{
	int		i;
	int		j;
	int		k;
	int		n;
	char	*str;
	
	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
		j++;
	str = malloc(sizeof(char) * (i + j + 1));
	i = 0;
	k = 0;
	while (dst[i] != '\0')
	{
		str[k] = dst[i];
		i++;
		k++;
	}
	i = 0;
	n = 0;
	while (src[i] != '\0' && n < len)
	{
		str[k] = src[i];
		i++;
		k++;
		n++;
	}
	if (j < len)
		while (j < len)
		{
			str[k] = '\0';
			j++;
			k++;
		}
	return (str);
}
