/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:38:33 by wtaylor           #+#    #+#             */
/*   Updated: 2018/04/27 17:14:22 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	haystack[9] = "gotestit";
	char	needle[4] = "test";

	printf("%s", ft_strnstr(haystack, needle, 6));
	return (0);
}
