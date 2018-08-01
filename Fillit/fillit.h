/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 11:07:52 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/01 11:46:33 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef	struct	s_tet
{
	int cdif1;
	int cdif2;
	int cdif3;
}				c_tet;

int		*validate(int *n, char **argv);
void	zero_all(int **a, int n, int l);
void	upsize_tet(int *a, int l, int init_l);
void	upsize_all(int **a, int l, int init_l, int n);
c_tet	tet_struct(int *a, int l);
void	increment_tet(int *t, int l);

#endif
