/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:59:11 by wtaylor           #+#    #+#             */
/*   Updated: 2018/06/13 14:57:10 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	buffer;

	if (argc != 2)
	{
		ft_putstr("usage: fillit file_name");
		return (0);
	}
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (buffer != '\n')
	{
		read(fd, &buffer, 1); 
		write(1, &buffer, 1);
	}
	close(fd);
	return (0);
}
