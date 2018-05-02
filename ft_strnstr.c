/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:36:07 by wtaylor           #+#    #+#             */
/*   Updated: 2018/04/27 17:14:20 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int				i;
	size_t	j;
	size_t	k;
	size_t	l;

	l = 0;
	while (needle[l] != '\0')
		l++;
	j = 0;
	while (haystack[j] != '\0' && (int)j < (int)len - (int)l - 1)
	{
		i = 0;
		while (needle[i] != haystack[j])
			j++;
		k = j;
		while (needle[i] == haystack[j])
		{
			i++;
			j++;
		}
		if (needle[i] =='\0')
		{
			while (k > 0)
			{
				haystack++;
				k--;
			}
			return ((char *)haystack);
		}
		j++;
	}
	return (NULL);
}
