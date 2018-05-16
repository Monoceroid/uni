#include "libft.h"

void    ft_strclr(char *s)
{
    while (*s++ && s != NULL)
        *s = '\0';
}