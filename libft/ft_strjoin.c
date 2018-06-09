/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:14:21 by wtaylor           #+#    #+#             */
/*   Updated: 2018/06/04 20:05:38 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;

	if (!s1 || !s2)
		return (NULL);
	t = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(t));
	if (!t)
		return (NULL);
	ft_strcpy(t, s1);
	ft_strcat(t, s2);
	return (t);
}
