/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:51:48 by wtaylor           #+#    #+#             */
/*   Updated: 2018/06/04 20:53:26 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[j] != '\0')
	{
		i = 0;
		while (needle[i] == haystack[i + j])
		{
			if (needle[i + 1] == '\0')
				return (char *)(haystack + j);
			i++;
		}
		j++;
	}
	return (NULL);
}
