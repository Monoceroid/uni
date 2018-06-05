/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:44:31 by wtaylor           #+#    #+#             */
/*   Updated: 2018/06/04 20:53:47 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == ',' || s[start] == '\n' || s[start] \
			== '\t')
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == ',' || s[end] == '\n' || s[end] == '\t')
		end--;
	len = (end - start) + 1;
	return (ft_strsub(s, start, len));
}
