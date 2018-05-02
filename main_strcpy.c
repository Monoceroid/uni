/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:27:59 by wtaylor           #+#    #+#             */
/*   Updated: 2018/04/25 11:46:36 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		main(void)
{
	char	dst[8] = "testing";
	char	src[4] = "far";

	printf("%s\n", dst);
	printf("%s\n", ft_strcpy(dst, src));
	return (0);
}
