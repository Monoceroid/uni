/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:59:11 by wtaylor           #+#    #+#             */
/*   Updated: 2018/06/13 17:17:46 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int	tetrimino(int fd)
{
	char	buffer;
	char	tet[5][5];
	int		count;
	int		i;

	i = 0;
	buffer = 'a';
	count = 0;
	while (buffer != '\n')
	{
		read(fd, &buffer, 1);
		count++;
		if (count != 5)
		{
			if (buffer != '.' && buffer != '#')
				return (0);
		}
		else
		{
			if (buffer != '\n')
				return (0);
		}
		tet[0][i] = buffer;
		printf("%c", tet[0][i]);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage: fillit file_name");
		return (0);
	}
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (tetrimino(fd) == 0)
	{
		ft_putstr("error");
		ft_putchar('\n');
		return (0);
	}
	close(fd);
	return (0);
}
