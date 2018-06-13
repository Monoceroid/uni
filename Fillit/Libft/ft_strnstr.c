/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:59:27 by wtaylor           #+#    #+#             */
/*   Updated: 2018/06/04 20:53:14 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[j] != '\0' && j < len)
	{
		i = 0;
		while (needle[i] == haystack[i + j])
		{
			if (needle[i + 1] == '\0' && (i + j) < len)
				return (char *)(haystack + j);
			i++;
		}
		j++;
	}
	return (NULL);
}
