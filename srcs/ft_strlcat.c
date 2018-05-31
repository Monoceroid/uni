/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:14:06 by wtaylor           #+#    #+#             */
/*   Updated: 2018/05/19 20:53:18 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	l;

	i = 0;
	while (src[i])
		i++;
	j = 0;
	while (dst[j])
		j++;
	if (src[i] == '\0' && dst[j] == '\0')
	{
		k = 0;
		l = i;
		while (k < size - 1)
		{
			dst[l + 1] = src[k];
			k++;
			l++;
		}
		dst[l + 1] = '\0';
	}
	return (i + j);
}
