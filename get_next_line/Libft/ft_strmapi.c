/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:01:15 by wtaylor           #+#    #+#             */
/*   Updated: 2018/06/04 19:54:20 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*t;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	t = ft_strnew(i);
	i = 0;
	if (t)
	{
		while (s[i] != 0)
		{
			t[i] = f(i, s[i]);
			i++;
		}
		return (t);
	}
	return (NULL);
}
