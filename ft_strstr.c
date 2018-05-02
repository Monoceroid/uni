/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:51:48 by wtaylor           #+#    #+#             */
/*   Updated: 2018/04/27 16:34:47 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	while (haystack[j] != '\0')
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
