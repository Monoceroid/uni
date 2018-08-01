/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 10:55:08 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/01 11:47:09 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void	increment_tet(int *t, int l)
{
	int		i;
	c_tet	old_struct;

	old_struct = tet_struct(t, l);
	i = -1;
	while (++i < 4)
		t[i]++;
	while (tet_struct(t, l).cdif1 != old_struct.cdif1 || tet_struct(t, l).cdif2
			!= old_struct.cdif2 || tet_struct(t, l).cdif3 != old_struct.cdif3)
	{
		t[0]++;
		t[1]++;
		t[2]++;
		t[3]++;
	}
}
