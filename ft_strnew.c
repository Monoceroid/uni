#include "libft.h"

char    *ft_strnew(size_t size)
{
    char    *str;
    size_t  i;

    if (str = (char *)ft_memalloc(size))
    {
        i   = 0;
        while (i < size)
        {
           str[i] = '\0';
            i++;
        }
        return (str);
    }
    return (NULL);
}