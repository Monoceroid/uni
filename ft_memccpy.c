/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:32:57 by wtaylor           #+#    #+#             */
/*   Updated: 2018/04/28 17:38:42 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dst2;
	char	*src2;

	dst2 = (char *)dst;
	src2 = (char *)src;
	while (n-- > 0 && *src2 != (unsigned char)c)
		*dst2++ = *src2++;
	if *src2 == (unsigned char)c
		return(*src2++);
	return (NULL);
}
