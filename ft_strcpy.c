/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 10:58:36 by wtaylor           #+#    #+#             */
/*   Updated: 2018/04/26 12:12:59 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strcpy(char * dst, const char * src)
{
	int		i;
	int 	j;
	char	*str;
	
	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
		j++;
	str = malloc(sizeof(char) * (i + j + 1));
	i = 0;
	j = 0;
	while (dst[i] != '\0')
	{
		str[j] = dst[i];
		i++;
		j++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		str[j] = src[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
