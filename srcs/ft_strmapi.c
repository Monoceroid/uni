/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:01:15 by wtaylor           #+#    #+#             */
/*   Updated: 2018/05/21 15:45:31 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*t;
	unsigned int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	t = (char *)malloc((i + 1) * sizeof(t));
	i = 0;
	while (s[i] != 0)
	{
		t[i] = f(i, s[i]);
		i++;
	}
	return (t);
}
