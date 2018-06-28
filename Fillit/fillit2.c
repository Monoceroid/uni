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

int	*check_count(int fd)
{
	char	buffer;
	int		pos;
	int		lines;
	int		*arr;

	buffer = 'a';
	pos = 0;
	lines = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		printf("Buffer: %c %d\n", buffer, buffer);
		pos++;
		printf("Position: %d\n", pos);
		if (pos % 5 != 0 && pos != 21)
		{
			if (buffer != '.' && buffer != '#')
				return (NULL);
		}
		else
		{
			if (buffer != '\n')
				return (NULL);
		}
		if (pos == 21)
		{
			lines += 4;
			printf("Lines: %d\n", lines);
			pos = 0;
		}
	}
	printf("%d\n", lines);
	arr = (int *)malloc(lines * sizeof(int));
	return (arr);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage: fillit file_name");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (check_count(fd) == NULL)
	{
		ft_putstr("error");
		ft_putchar('\n');
		return (0);
	}
	close(fd);
	return (0);
}