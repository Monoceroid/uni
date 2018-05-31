/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:25:46 by wtaylor           #+#    #+#             */
/*   Updated: 2018/05/21 18:38:34 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, int len)
{
	int		i;
	int		j;
	int		n;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(src) + 1));
	i = 0;
	j = 0;
	while (dst[i] != '\0')
		str[j++] = dst[i++];
	i = 0;
	n = 0;
	while (src[i] != '\0' && n++ < len)
		str[j++] = src[i++];
	if (n < len)
	{
		while (n++ < len)
			str[j++] = '\0';
	}
	return (str);
}
