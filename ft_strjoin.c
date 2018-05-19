/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:14:21 by wtaylor           #+#    #+#             */
/*   Updated: 2018/05/19 16:41:44 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;

	t = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(t));
	if (t = NULL)
		return (NULL);
	ft_strcpy(t, s1);
	ft_strcat(t, s2);
	return (t);
}
