/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:45:21 by wtaylor           #+#    #+#             */
/*   Updated: 2018/05/19 14:59:16 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int			size;
	char const	*t;

	size = 0;
	while (s[size] != 0)
		size++;
	t = (char *)malloc((size + 1) * sizeof(t));
	size = 0;
	while (s[size] != 0)
	{
		t[size] = f(s[size]);
		size++;
	}
	return (t);
}
