/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpytest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:02:02 by wtaylor           #+#    #+#             */
/*   Updated: 2018/04/25 11:06:06 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		main(void)
{
	char	dst[8] = "testing";
	char	src[4] = "far";

	printf("%s", dst);
	printf("%s", strcpy(dst, src));
	return (0);
}
