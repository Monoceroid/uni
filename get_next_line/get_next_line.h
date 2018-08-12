#define	BUFF_SIZE 1

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int	get_next_line(const int fd, char **line);
