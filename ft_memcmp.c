/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:33:38 by wtaylor           #+#    #+#             */
/*   Updated: 2018/05/02 14:33:43 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t1 = (unsigned char *)s1;
	unsigned char	*t2 = (unsigned char *)s2;
	int				i;

	i = 0;
	while (t1[i] == t2[i] && i < n)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		i++;
	}
	return (0);
}
