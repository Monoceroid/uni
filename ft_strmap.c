/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:45:21 by wtaylor           #+#    #+#             */
/*   Updated: 2018/06/04 20:48:10 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int			size;
	char		*t;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	t = ft_strnew(size);
	size = 0;
	if (t)
	{
		while (s[size] != 0)
		{
			t[size] = f(s[size]);
			size++;
		}
		return (t);
	}
	return (NULL);
}
